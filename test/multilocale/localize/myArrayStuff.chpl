use BlockDist;

pragma "no doc"
pragma "reference to const when const this"
pragma "fn returns aliasing array"
proc _array.mySlice(d: domain) {
  /* TODO: need to do something here
  if boundsChecking then
    checkSlice((... ranges));
  */

  // TODO: I removed the intersection from here to avoid communication;
  // we should be using a local 'shape' query to do this slice
  //     was: _dom((...ranges));
  /*
  pragma "no auto destroy" var d = {(...ranges)};
  d._value._free_when_no_arrs = true;
  */

  //
  // If this is already a slice array view, we can short-circuit
  // down to the underlying array.
  //
  const (arr, arrpid) = if (_value.isSliceArrayView())
                          then (this._value.arr, this._value._ArrPid)
                          else (this._value, this._pid);

  var a = new unmanaged myArrayViewSlice(eltType=this.eltType,
                                         _DomPid=d._pid,
                                         dom=d._instance,
                                         _ArrPid=arrpid,
                                         _ArrInstance=arr);

  // this doesn't need to lock since we just created the domain d
  d._value.add_arr(a);
  return myNewArray(a);
}  

/* Return true if the argument ``a`` is an array with a rectangular
   domain.  Otherwise return false. */
proc isRectangularArr(a: myArray) param return isRectangularDom(a.domain);

pragma "always RVF"
pragma "array"
pragma "ignore noinit"
pragma "default intent is ref if modified"
record myArray {
  var _pid:int;  // only used when privatized
  pragma "owned"
  pragma "alias scope from this"
  var _instance; // generic, but an instance of a subclass of BaseArr
  var _unowned:bool;

  forwarding _value except doiBulkTransferFromKnown, doiBulkTransferToKnown,
                           doiBulkTransferFromAny,  doiBulkTransferToAny;

  pragma "alias scope from this"
  inline proc _value {
    if _isPrivatized(_instance) {
      return chpl_getPrivatizedCopy(_instance.type, _pid);
    } else {
      return _instance;
    }
  }

  proc writeThis(f) {
    _value.dsiSerialWrite(f);
  }

  /* The type of elements contained in the array */
  proc eltType type return _value.eltType;
  /* The type of indices used in the array's domain */
  proc idxType type return _value.idxType;
  pragma "return not owned"
  proc _dom return _getDomain(_value.dom);
  /* The number of dimensions in the array */
  proc rank param return this.domain.rank;

  // array element access
  // When 'this' is 'const', so is the returned l-value.
  pragma "no doc" // ref version
  pragma "reference to const when const this"
  pragma "removable array access"
  pragma "alias scope from this"
  inline proc ref this(i: rank*_value.dom.idxType) ref {
    if isRectangularArr(this) || isSparseArr(this) then
      return _value.dsiAccess(i);
    else
      return _value.dsiAccess(i(1));
  }
  pragma "no doc" // value version, for POD types
  pragma "alias scope from this"
  inline proc const this(i: rank*_value.dom.idxType)
  where shouldReturnRvalueByValue(_value.eltType)
  {
    if isRectangularArr(this) || isSparseArr(this) then
      return _value.dsiAccess(i);
    else
      return _value.dsiAccess(i(1));
  }
  pragma "no doc" // const ref version, for not-POD types
  pragma "alias scope from this"
  inline proc const this(i: rank*_value.dom.idxType) const ref
  where shouldReturnRvalueByConstRef(_value.eltType)
  {
    if isRectangularArr(this) || isSparseArr(this) then
      return _value.dsiAccess(i);
    else
      return _value.dsiAccess(i(1));
  }

  record mySliceHelper {
    const dompid: int;
    const arrpid: int;
  }

  proc chpl__serialize() {
    var buff: chpl__inPlaceBuffer;
    //    writeln("[", here.id, "] In serialize, sending ", (_value._DomPid, _value._ArrPid));
    return new mySliceHelper(_value._DomPid, _value._ArrPid);
  }

  pragma "no copy return"  // this to avoid putting in chpl__unref calls
  proc type chpl__deserialize(data) {
    //    compilerWarning(this:string);
    //    writeln("[", here.id, "] in my deserialize routine, received", (data.dompid, data.arrpid));
    const dompid = data.dompid;
    //    const dom = chpl_getPrivatizedCopy(BlockDom(rank=2, idxType=int, stridable=false, sparseLayoutType=unmanaged DefaultDist), dompid);
    const dom = chpl_getPrivatizedCopy(unmanaged BlockDom(2, int, false, unmanaged DefaultDist), dompid);
    const arrpid = data.arrpid;
    const arr = chpl_getPrivatizedCopy(unmanaged BlockArr(rank=2, idxType=int, stridable=false, eltType=real, sparseLayoutType=unmanaged DefaultDist), arrpid);

    // This is not so helpful because the "array" pragma causes us to sugar
    // this thing's type in unfortunate ways...
    //
    // writeln(this:string);
    
    const dmapclass = new unmanaged myArrayViewSlice(eltType=real,
                                                     _DomPid=data.dompid,
                                                     dom = dom,
                                                     _ArrPid=data.arrpid,
                                                     _ArrInstance = arr);

    const newarr = myNewArray(dmapclass);
    
    return newarr;
  }
}

private proc buildIndexCacheHelper(arr, dom) {
  param isRankChangeReindex = arr.isRankChangeArrayView() ||
                              arr.isReindexArrayView() ||
                              (chpl__isArrayView(arr) && arr._containsRCRE());
  if chpl__isDROrDRView(arr) && isRankChangeReindex {
    if chpl__isArrayView(arr) then
      return arr.indexCache.toSlice(dom);
    else
      return arr.dsiGetRAD().toSlice(dom);
  } else {
    return false;
  }
}


class myArrayViewSlice: BaseArr {
  type eltType;

  const _DomPid;
  const dom;

  const _ArrPid;
  const _ArrInstance;;

  const indexCache = buildIndexCacheHelper(_ArrInstance, dom);;

  proc idxType type return dom.idxType;
  proc rank param return arr.rank;

  inline proc privDom {
    if _isPrivatized(dom) {
      return chpl_getPrivatizedCopy(dom.type, _DomPid);
    } else {
      return dom;
    }
  }

  inline proc arr {
    if _isPrivatized(_ArrInstance) {
      return chpl_getPrivatizedCopy(_ArrInstance.type, _ArrPid);
    } else {
      return _ArrInstance;
    }
  }

  proc dsiSerialWrite(f) {
    chpl_serialReadWriteRectangular(f, arr, privDom);
  }

  iter these() ref {
    for elem in chpl__serialViewIter(this, privDom) do
      yield elem;
  }

  iter these(param tag: iterKind) ref
    where tag == iterKind.standalone && !localeModelHasSublocales &&
    __primitive("method call resolves", privDom, "these", tag) {
    forall i in privDom do yield arr.dsiAccess(i);
  }

  iter these(param tag: iterKind) where tag == iterKind.leader {
    for followThis in privDom.these(tag) do {
      yield followThis;
    }
  }

  iter these(param tag: iterKind, followThis) ref
    where tag == iterKind.follower {
    for i in privDom.these(tag, followThis) {
      yield arr.dsiAccess[i];
    }
  }

  inline proc dsiAccess(i: idxType ...rank) ref {
    return dsiAccess(i);
  }

  inline proc dsiAccess(i: idxType ...rank)
    where shouldReturnRvalueByValue(eltType) {
    return dsiAccess(i);
  }

  inline proc dsiAccess(i: idxType ...rank) const ref
    where shouldReturnRvalueByConstRef(eltType) {
    return dsiAccess(i);
  }

  proc shouldUseIndexCache() param {
    return false;
  }
  
  inline proc dsiAccess(i) ref {
    checkBounds(i);
    if shouldUseIndexCache() {
      const dataIdx = indexCache.getDataIndex(i);
      return indexCache.getDataElem(dataIdx);
    } else {
      return arr.dsiAccess(i);
    }
  }
  
  inline proc dsiAccess(i)
    where shouldReturnRvalueByValue(eltType) {
    checkBounds(i);
    if shouldUseIndexCache() {
      const dataIdx = indexCache.getDataIndex(i);
      return indexCache.getDataElem(dataIdx);
    } else {
      return arr.dsiAccess(i);
    }
  }
  
  inline proc dsiAccess(i) const ref
    where shouldReturnRvalueByConstRef(eltType) {
    checkBounds(i);
    if shouldUseIndexCache() {
      const dataIdx = indexCache.getDataIndex(i);
      return indexCache.getDataElem(dataIdx);
    } else {
      return arr.dsiAccess(i);
    }
  }

  inline proc checkBounds(i) {
    if boundsChecking then
      if !privDom.dsiMember(i) then
        halt("array index out of bounds: ", i);
  }
}


pragma "unsafe"
pragma "no copy return"
proc myNewArray(value) {
  if _isPrivatized(value) then
    return new myArray(_newPrivatizedClass(value), value);
  else
    return new myArray(nullPid, value);
}
