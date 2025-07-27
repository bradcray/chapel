use BlockDist;
use CompressedSparseLayout;
use CTypes;
use IO.FormattedIO;
use Time;

use CustomCopyAggregation;
use RecursiveMatrixGenerator;
use SortUtils;

config const A = 0.57;
config const B = 0.19;
config const C = 0.19;
config const D = 0.05;
config const SCALE = 10;
config const FACTOR = 16;
config const N = 2**SCALE;
config const NNZ = 2**SCALE * FACTOR;
config const verboseArrayPrint = false;
config const idxBufSize = SCALE;
var timer:stopwatch;

// The dense space
const Space = {1..N, 1..N};
const DenseDom = blockDist.createDomain(Space);

// Creating sparse domains and arrays for two use cases
var SparseDomNoAgg: sparse subdomain(DenseDom) dmapped new csrLayout(parSafe=true);
var SparseDomAgg: sparse subdomain(DenseDom) dmapped new csrLayout(parSafe=true);

var SparseArrNoAgg: [SparseDomNoAgg] int;
var SparseArrAgg: [SparseDomAgg] int;

// Recursively generate sparse indices
var (row,col) = recursiveMatrixGenerator(A, B, C, D, SCALE, N, NNZ);

// Parse out repeated indices
var iv = coargsort(row,col);
var sortedRow = row[iv]; var sortedCol = col[iv];
var sortedIdx = blockDist.createArray(row.domain, (int,int));
forall (si, i) in zip(sortedIdx, sortedIdx.domain) do 
  si = (sortedRow[i], sortedCol[i]);
var uniqueIdx = uniqueFromSorted(sortedIdx, needCounts=false);
var rowIdx = blockDist.createArray(uniqueIdx.domain, int);
var colIdx = blockDist.createArray(uniqueIdx.domain, int);

// Add one to row and column values to account for 0-based index creation that
// `recursiveMatrixGenerator` carries out
forall (ui, r, c) in zip(uniqueIdx, rowIdx, colIdx) {
  r = ui[0];
  c = ui[1];
}

var vals = blockDist.createArray(uniqueIdx.domain, int);
forall (i,v) in zip(vals.domain, vals) do v = i + 1;

/***************************** NO AGGREGATION *********************************/
timer.start();

// Note: Will currently only work with CHPL_RT_NUM_THREADS_PER_LOCALE=1
forall (i,j) in zip(rowIdx,colIdx) with (var idxBuf = SparseDomNoAgg.createIndexBuffer(idxBufSize,true,true)) do
	idxBuf.add((i,j));
forall (i,j,v) in zip(rowIdx,colIdx,vals) with (ref SparseArrNoAgg) do
	SparseArrNoAgg[i,j] = v;

writeln("SparseDomNoAgg time: %r".format(timer.elapsed()));
writeln("SparseDomNoAgg size: %i".format(SparseDomNoAgg.size));
writeln("SparseArrNoAgg size: %i".format(SparseArrNoAgg.size));

/******************************** AGGREGATION *********************************/
class DestinationHandler {
  var domVal;
  var arrVal;

  proc init(domVal, arrVal) {
    this.domVal = domVal;
    this.arrVal = arrVal;
  }

  inline proc flush(ref rBuffer, const ref remBufferPtr, const ref myBufferIdx) {
    const (found, locid) = domVal.parentDom.distribution.chpl__locToLocIdx(here);
    var locIdxBuf = domVal.createIndexBuffer(idxBufSize,true,true);
    for (dstAddr, srcVal) in rBuffer.localIter(remBufferPtr, myBufferIdx) {
      assert(dstAddr == nil);
      var (i,j,_) = srcVal;
      locIdxBuf.add((i, j));
    }
    locIdxBuf.commit();
    for (dstAddr, srcVal) in rBuffer.localIter(remBufferPtr, myBufferIdx) {
      assert(dstAddr == nil);
      var (i,j,v) = srcVal;
      var (_,loc) = this.domVal.find((i,j));
      this.arrVal.data[loc] = v;
    }
  }
}

class SourceHandler {
  var domVal;
  var arrVal;
  type elemType = (int,int,int);

  proc init(D, A) {
    this.domVal = D._value;
    this.arrVal = A._value;
  }

  proc sourceCopy() {
    return new unmanaged DestinationHandler(domVal,arrVal);
  }

  proc getDestinationLocale(val: elemType) {
    var (i,j,_) = val;
    return domVal.parentDom.distribution.dsiIndexToLocale((i,j));
  }
}
timer.restart();

// Note: Will currently only work with CHPL_RT_NUM_THREADS_PER_LOCALE=1
forall (i,j,v) in zip(rowIdx,colIdx,vals) with (var agg = new CustomDstAggregator(new shared SourceHandler(SparseDomAgg, SparseArrAgg))) do 
	agg.copy((i,j,v));

writeln("  SparseDomAgg time: %r".format(timer.elapsed()));
writeln("  SparseDomAgg size: %i".format(SparseDomAgg.size));
writeln("  SparseArrAgg size: %i".format(SparseArrAgg.size));

if verboseArrayPrint {
	writeln();
	for (r,c) in SparseDomNoAgg do write(SparseArrNoAgg[r,c], " ");
	writeln();
	for (r,c) in SparseDomAgg do write(SparseArrAgg[r,c], " ");
	writeln();
}
