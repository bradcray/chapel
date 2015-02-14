class ArrayViewArr: BaseArr {
  type eltType;
  var dom;
  var arr;

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
}
