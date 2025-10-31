module MatMatMult {
  use CommDiagnostics, Time;
  use SpsMatUtil;
  
  config const countComms=false,
               printTimings=false;

  // sparse, outer, matrix-matrix multiplication algorithm; A is assumed
  // CSC and B CSR
  //
  proc sparseMatMatMult(A, B) {
    if countComms then startCommDiagnostics();
    var time: stopwatch;
    time.start();

    var spsData: sparseMatDat;

    sparseMatMatMult(A, B, spsData);

    var C = makeSparseMat(A.domain.parentDom, spsData);
    
    const elapsed = time.elapsed();

    if countComms {
      stopCommDiagnostics();
      printCommDiagnosticsTable();
      writeln();
    }

    if printTimings then writeln("Elapsed time = ", elapsed, "\n");

    return C;
  }

  // This version forms the guts of the above and permits a running set
  // of nonzeroes to be passed in and updated rather than assuming that
  // the multiplication is the first/only step.
  //
  proc sparseMatMatMult(A, B, ref spsData) {
    sparseMatMatMult(A, B, A.cols(), spsData);
  }

  proc sparseMatMatMult(A, B, inds, ref spsData) {
    //    forall ac_br in inds with (merge reduce spsData) do {
    for ac_br in inds {
      writeln((A.domain.rowRange, A.domain.colRange));
      for (ar, a) in A.rowsAndVals(ac_br) do
        for (bc, b) in B.colsAndVals(ac_br) do
          spsData.add((ar, bc), a * b);
    }
  }
  
  class Box {
    const val;

    proc init(in x) {
      this.val = x;
    }
  }

  proc sparseMatMatMult(A, B) where (!A.chpl_isNonDistributedArray() &&
                                     !B.chpl_isNonDistributedArray()) {
    use Math;

    var CD = emptySparseDomLike(B);  // For now, hard-code C to use CSR, like B
    var C: [CD] int;

    ref targLocs = A.targetLocales();

    const locRows = targLocs.dim(0).size,
          locCols = targLocs.dim(1).size,
          numBlocks = if locRows == locCols then locRows
                                            else lcm(locRows, locCols),
          blocksPerLocRow = numBlocks / locRows,
          blocksPerLocCol = numBlocks / locCols;

    if countComms then startCommDiagnostics();
    var time: stopwatch;
    time.start();

    // TODO: re-enable coforall
    //    coforall (locRow, locCol) in targLocs.domain {
    for (locRow, locCol) in targLocs.domain {
      on targLocs[locRow, locCol] {

        var spsData: sparseMatDat;

        writef("[%i,%i] Starting with A block (%i.%i)\n", locRow, locCol, locRow, 0);
        writef("[%i,%i] Starting with B block (%i.%i)\n", locRow, locCol, 0, locCol);
        // pre-populate the A and B boxes for iter 0 to get the types right
        var aBlkBox = new Box(A.getLocalSubarray(locRow, locCol)),
            bBlkBox = new Box(B.getLocalSubarray(locRow, locCol));

        for blk in 0..<numBlocks {
          if blk {  // skip blk == 0 because we've done that above
            if blk % blocksPerLocCol == 0 {
              const srcLocCol = (blk/blocksPerLocCol)%locCols;
              writef("[%i,%i] In iteration %i, time to get a new A block from (%i.%i)\n", locRow, locCol, blk, locRow, srcLocCol);
              aBlkBox = new Box(A.getLocalSubarray(locRow, srcLocCol));
            }
            if blk % blocksPerLocRow == 0 {
              const srcLocRow = (blk/blocksPerLocRow)%locRows;
              writef("[%i,%i] In iteration %i, time to get a new B block from (%i.%i)\n", locRow, locCol, blk, srcLocRow, locCol);
              bBlkBox = new Box(B.getLocalSubarray(srcLocRow, locCol));
            }
          }
          use DSIUtil;
          const inds = _computeBlock(A.dim(0).size, numBlocks, blk, A.dim(0).high, A.dim(0).low, A.dim(0).low);
          writef("[%i,%i] In iteration %i, computing on inds %i..%i\n", locRow, locCol, blk, inds(0), inds(1));
                                     
          /*
          // Skew the row/col we access to avoid communication bottlenecks
          const srcloc = (loc + locRow)%numBlocks;

          // Make a local copy of the remote blocks of A and B; on my branch
          // this will also make a local copy of the remote indices, so long
          // as these are 'const'/read-only
          //
          const aBlk = A.getLocalSubarray(locRow, srcloc),
                bBlk = B.getLocalSubarray(srcloc, locCol);

          // This local block is not strictly necessary but ensures that the
          // computation on the blocks will not require communication
*/
          writeln((aBlkBox.locale.id, aBlkBox.val.locale.id));
          // TODO: re-enble local block
//          local {
            sparseMatMatMult(aBlkBox.val, bBlkBox.val, inds(0)..inds(1), spsData);
//          }
        }

        // Get my locale's local indices and create a sparse matrix
        // using them and the spsData computed above.
        //
        const locInds = A.domain.parentDom.localSubdomain();
        var cBlk = makeSparseMat(locInds, spsData);

        // Stitch the local portions back together into the global-view
        //
        CD.setLocalSubdomain(cBlk.domain);
        C.setLocalSubarray(cBlk);
      }
    }

    const elapsed = time.elapsed();
    
    if countComms {
      stopCommDiagnostics();
      printCommDiagnosticsTable();
      writeln();
    }

    if printTimings then writeln("Elapsed time = ", elapsed, "\n");

    return C;
  }


  // dense, simple matrix-matrix multiplication algorithm; this is
  // wildly inefficient, both because it ignores the sparsity and
  // because it uses random access of the sparse arrays which tends to
  // be expensive.
  //
  proc denseMatMatMult(A, B) {
    if countComms then startCommDiagnostics();
    var time: stopwatch;
    time.start();

    const n = A.dim(0).size;
    
    var spsData: sparseMatDat;
  
    for i in 1..n {
      for j in 1..n {
        var prod = 0;

        forall k in 1..n with (+ reduce prod) do
          prod += A[i,k] * B[k,j];

        if prod != 0 then
          spsData.add((i,j), prod);
      }
    }

    var C = makeSparseMat(A.domain.parentDom, spsData);

    const elapsed = time.elapsed();

    if countComms {
      stopCommDiagnostics();
      printCommDiagnosticsTable();
      writeln();
    }

    if printTimings then writeln("Elapsed time = ", elapsed, "\n");

    return C;
  }
}
