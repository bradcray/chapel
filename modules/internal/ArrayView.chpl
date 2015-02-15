//
// TODO: Re-optimize cases that can be done in-place like DefaultRectangular
// to not use these ArrayView wrappers.  Re-use/redefine the param functions
// below?
//
// TODOs:
// - run distribution suite across all distributions
// - enable in-place cases for DefaultRectangular
// - can mult be removed?
//

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

  //
  // TODO: Should I need both these overloads
  //
  proc dsiAccess(i:integral) ref {
    return dsiAccess((i,));
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

  proc dsiRankChange(a,b,c,d) {
    halt("rank change not yet supported on array views");
    return this;
  }
}


class ArrayReindexViewArr: BaseArr {
  type eltType;
  var dom;
  var arr;

  proc isArrayReindexView() param { return true; }

  iter these() ref {
    for i in dom do
      yield dsiAccess(i);
  }

  iter these(param tag: iterKind) where tag == iterKind.leader {
    for followThis in dom.these(tag) do
      yield followThis;
  }

  iter these(param tag: iterKind, followThis) ref
    where tag == iterKind.follower {
    for i in dom.these(tag, followThis) do
      yield dsiAccess[i];
  }

  //
  // TODO: Should I need both these overloads
  //
  proc dsiAccess(i: integral) ref {
    return dsiAccess((i,));
  }

  proc dsiAccess(i) ref {
    if boundsChecking then
      if !dom.dsiMember(i) then
        halt("array index out of bounds: ", i);
    if (dom.rank == 1) {
      const pos_i = dom.dsiDim(1).indexOrder((...i));
      const ind_i = arr.dom.dsiDim(1).orderToIndex(pos_i);
      return arr.dsiAccess(ind_i);
    } else {
      var ind_i: dom.rank*dom.idxType;
      for d in 1..dom.rank {
        const pos_i_d = dom.dsiDim(d).indexOrder(i(d));
        ind_i(d) = arr.dom.dsiDim(d).orderToIndex(pos_i_d);
      }
      return arr.dsiAccess(ind_i);
    }

    return arr.dsiAccess(i);
  }

  proc dsiGetBaseDom() {
    return dom;
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

  proc dsiRankChange(a, param b,param c,d) {
    halt("rank change not yet supported on array views");
    return this;
  }
}


class ArrayRankchangeViewArr: BaseArr {
  type eltType;
  const dom;
  const arr;
  const collapsedDim;
  const idx;

  iter these() ref {
    for i in dom do
      yield dsiAccess(i);
  }

  iter these(param tag: iterKind) where tag == iterKind.leader {
    for followThis in dom.these(tag) do
      yield followThis;
  }

  iter these(param tag: iterKind, followThis) ref
    where tag == iterKind.follower {
    for i in dom.these(tag, followThis) do
      yield dsiAccess[i];
  }

  //
  // TODO: Should I need both these overloads
  //
  proc dsiAccess(i: integral) ref {
    return dsiAccess((i,));
  }

  proc dsiAccess(i) ref {
    /*
    if boundsChecking then
      if !dom.dsiMember(i) then
        halt("array index out of bounds: ", i);
    */
    //    writeln("Incoming index = ", i);
    param arrRank = arr.rank;
    type idxType = dom.idxType;
    var ind = idx;
    var j = 1;
    for param d in 1..arrRank {
      if !collapsedDim(d) {
        ind(d) = i(j);
        j += 1;
      }
    }
    //    writeln("Outgoing index = ", ind);

    return arr.dsiAccess(ind);
  }

  proc dsiGetBaseDom() {
    //
    // WARNING!!!
    //
    return dom;
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

  proc dsiRankChange(a, param b,param c,d) {
    halt("rank change not yet supported on array views");
    return this;
  }
}
