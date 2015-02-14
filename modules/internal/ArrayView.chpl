class ArrayViewArr: BaseArr {
  type eltType;
  var dom;
  var arr;

  iter these() ref {
    for i in dom do
      yield arr.dsiAccess(i);
  }

  proc dsiAccess(i) ref {
    return arr.dsiAccess(i);
  }

  proc dsiGetBaseDom() {
    return dom;
  }
}
