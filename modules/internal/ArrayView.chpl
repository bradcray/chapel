class ArrayViewArr: BaseArr {
  type eltType;
  var dom;
  var arr;

  proc isArrayView() param { return true; }

  iter these() ref {
    for i in dom do
      yield arr.dsiAccess(i);
  }

  iter these(param tag: iterKind) where tag == iterKind.leader {
    for followThis in dom.these(tag) do
      yield followThis;
  }

  iter these(param tag: iterKind, followThis) ref
    where tag == iterKind.follower {
    for i in dom.these(tag, followThis) do
      yield arr.dsiAccess[i];
  }

  proc dsiAccess(i) ref {
    if boundsChecking then
      if !dom.dsiMember(i) then
        halt("array index out of bounds: ", i);

    return arr.dsiAccess(i);
  }

  proc dsiGetBaseDom() {
    return dom;
  }

  proc dsiReindex(d) {
    halt("reindexing not supported on array views yet");
    return this;
  }

  proc dsiSerialWrite(f: Writer) {
    //
    // Copied from BlockArr... refactor
    //
    type idxType = dom.idxType;
    param rank = dom.rank;
    type strType = chpl__signedType(idxType);
    var binary = f.binary();
    if dom.dsiNumIndices == 0 then return;
    var i : rank*idxType;
    for dim in 1..rank do
      i(dim) = dom.dsiDim(dim).low;
    label next while true {
      f.write(dsiAccess(i));
      if i(rank) <= (dom.dsiDim(rank).high - dom.dsiDim(rank).stride:strType) {
        if ! binary then f.write(" ");
        i(rank) += dom.dsiDim(rank).stride:strType;
      } else {
        for dim in 1..rank-1 by -1 {
          if i(dim) <= (dom.dsiDim(dim).high - dom.dsiDim(dim).stride:strType) {
            i(dim) += dom.dsiDim(dim).stride:strType;
            for dim2 in dim+1..rank {
              f.writeln();
              i(dim2) = dom.dsiDim(dim2).low;
            }
            continue next;
          }
        }
        break;
      }
    }
  }
}
