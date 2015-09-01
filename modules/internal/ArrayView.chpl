/*
 * Copyright 2004-2015 Cray Inc.
 * Other additional copyright holders may be indicated within.
 * 
 * The entirety of this work is licensed under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 * 
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//
//
// TODOs:
//
// Add standalone iterators
//
// Change setIndices to avoid the var a: b.type style and
//  just use a dsiClone() instead in order to change var
//  field back to const in domain.
//
// Create a version of testAlign that uses var A: B.type;
//
// Make reindex view store updom as a full default rectangular
//   _domain-wrapped class rather than a class reference in
//   order to remove bogus reference counting.
//
// - review dsi routines in Block -- which am I missing?
// - rename dsiSlice/Reindex/RankChange to doi
// - update README.dsi
// - test privatization routines for non-slice routines and get
//   them working -- started on new test for this
// - add comments to each class and method
// - run distribution suite cleanly for "always use array views"
//   - and set up nightly testing against this (?)
// - run distribution suite across all distributions
// - consider privatizing other operators?
// - check memory leaks
//   - insert destructors that don't auto-decrement stuff?
// - rename ArrayViewArr to imply slicing view
// - replace isArrayView-style routines with chpl try tokens (?)
// - creating arrays over arrayview.dom queries -- will it work?
// - can the dsi distribution create rank change view routine be removed?
//


//// *** INSIGHT:  Do I need a distributed/privatized domain for anything,
//// or can I rely on the array for everything, other than bounds checking,
//// given that the leader/follower interface is independent of indices?
////
//// The main question being things like "forall (i,j) in A.domain, though
//// that seems congruent with the B: [A.domain] issue I'm having....
//// and can perhaps be handled by using arr.dom as the leader rather than
//// dom?  Then use a reindex dom itself to handle the declaration case?

use DefaultRectangular;

class ArraySliceViewArr: BaseArr {
  type eltType;
  const dom;
  const arr;
  var pid = -1;

  proc isArrayView() param { return true; }
  proc idxType type return arr.idxType;
  proc rank param return arr.rank;

  inline iter these() ref {
    for i in dom do
      yield arr.dsiAccess(i);
  }

  inline iter these(param tag: iterKind) where tag == iterKind.leader {
    //    writeln("In sliceview leader");
    for followThis in dom.these(tag) do {
      //      writeln("yielding ", followThis);
      yield followThis;
    }
  }

  inline iter these(param tag: iterKind, followThis) ref
    where tag == iterKind.follower {
    for i in dom.these(tag, followThis) do
      yield arr.dsiAccess[i];
  }

  inline proc dsiAccess(i:integral) ref {
    return dsiAccess((i,));
  }

  inline proc dsiAccess(i) ref {
    //    writeln("Slice got: ", i);
    if boundsChecking then
      if !dom.dsiMember(i) then
        halt("array index out of bounds: ", i);

    return arr.dsiAccess(i);
  }

  inline proc dsiGetBaseDom() {
    return dom;
  }

  proc dsiTargetLocales() {
    return arr.dsiTargetLocales();
  }

  proc doiBulkTransferToDR(B) {
    arr.doiBulkTransferToDR(B);
  }

  proc dsiSerialWrite(f: Writer) {
    chpl_rectArrayReadWriteHelper(f, arr, dom);
  }

  proc dsiSupportsPrivatization() param
    return arr.dsiSupportsPrivatization() && dom.dsiSupportsPrivatization();

  proc dsiGetPrivatizeData() return (dom.pid, arr.pid);

  proc dsiPrivatize(privatizeData) {
    const (privdomID, privarrID) = privatizeData;
    const privdom = chpl_getPrivatizedCopy(dom.type, privdomID);
    const privarr = chpl_getPrivatizedCopy(arr.type, privarrID);
    return new ArraySliceViewArr(eltType=eltType, dom=privdom, arr=privarr);
  }
}


//
// TODO: Rename to DomDist
//
class ArrayReindexViewDom: BaseRectangularDom {
  type idxType;
  var updom;    // the upward-facing domain that clients will access
  const downdom;  // the downward-facing domain that implements things
  var pid = -1;

  proc dist {
    return this;
  }

  proc _value {
    return this;
  }

  //
  // TODO: If the following two could use the same name, a dom could be its
  // own dist more easily
  //
  proc dsiNewRectangularDom(param rank, type idxType, param stridable) {
    return new ArrayReindexViewDom(idxType=idxType, updom=updom, downdom=downdom);

  }
  
  proc dsiBuildRectangularDom(param rank, type idxType, param stridable, ranges) {
    //    writeln("ranges = ", ranges);
    //    writeln("updom = ", updom.dsiDims());
    //    writeln("downdom = ", downdom.dsiDims());
    //    downdom.dsiDisplayRepresentation();
    var diff: rank*int;
    var newranges: ranges.type;
    const newupdom = {(...ranges)};
    if !noRefCount then
      newupdom._value.incRefCount();
    for param i in 1..updom.rank {
      if (ranges(i).stride != updom.dsiDim(i).stride) {
        writeln("In dimension ", i, ", updom range is: ", updom.dsiDim(i), " while ranges(i).stride is: ", ranges(i));
        writeln("Downdom range is: ", downdom.dsiDim(i));
        writeln("Lows are: ", (downdom.dsiDim(i).low, updom.dsiDim(i).low));
        writeln("Naively, this would result in: ", ranges(i).translate(downdom.dsiDim(i).low - updom.dsiDim(i).low));
        warning("Stride mismatch in ArrayReindexViewDom.dsiBuildRectangularDom()");
      }
      newranges(i) = ranges(i).translate(downdom.dsiDim(i).low - updom.dsiDim(i).low);
    }
    //    writeln("newranges = ", newranges);
    //    halt("That's all folks!");
    const newdowndom = _newDomain(downdom.dsiBuildRectangularDom(rank, idxType, stridable, newranges));
    if !noRefCount {
      newdowndom._value.incRefCount();
      /*
      if newdowndom.linksDistribution() {
        writeln("*** Links distribution!!!");
        newdowndom.dist.incRefCount();
        newdowndom.dist.incRefCount();
      }
      */
    }
    var retval = new ArrayReindexViewDom(idxType=idxType, updom=newupdom._value, 
                                         downdom=newdowndom._value);
    //    writeln("checking dist: ", retval.downdom.dist);
    //    writeln("*** checking forall: ");
    //    forall i in newdowndom {
    //      writeln("Hello from ", i);
    //    }
    //    retval.dsiDisplayRepresentation();
    return retval;
    //    const newdowndom = downdom.dsiBuildRectangularDom(rank, idxType, stridable);
    //    return dsiNewRectangularDom(rank, idxType, stridable);
  }

  proc rank param {
    return updom.rank;
  }

  proc stridable param {
    return updom.stridable;
  }

  //
  // TODO: Are both of these really needed?
  //
  proc linksDistribution() param return false;
  proc dsiLinksDistribution() return false;

  //
  // TODO: I don't think this'll actually work if it's used
  // for anything other than initialization.  If someone
  // really re-set the indices for a domain that was created
  // from this distribution, we'd need to ask for the new
  // domain all the way down the stack, similar to in the
  // dsiBuildRectangularDom routine.
  //
  proc dsiSetIndices(x) {
    //    writeln("*****>>>> dsiSetIndices = ", x);
    var newdom = {(...x)};
    if !noRefCount then
      newdom._value.incRefCount();
    updom = newdom._value;
    //    dsiDisplayRepresentation();
    //    writeln("*****<<<< dsiSetIndices = ", x);
  }

  proc dsiSerialWrite(f: Writer) {
    updom.dsiSerialWrite(f);
  }

  proc dsiDisplayRepresentation() {
    writeln("{");
    write("  updom: {");
    updom.dsiDisplayRepresentation();
    write("  downdom {");
    downdom.dsiDisplayRepresentation();
    writeln("}");
  }


  //
  // TODO: Is BaseDist really needed?
  //
  proc dsiMyDist(): BaseDist {
    return nil;
  }

  //  proc dist return downdom.dist;

  proc dsiBuildArray(type eltType) {
    //    writeln("Building array over: ", downdom);
    //
    // TODO: Is this array getting reclaimed?  Do I need to bump its
    // reference count or...?
    //
    var newarr = _newArray(downdom.dsiBuildArray(eltType))._value;
    return new ArrayReindexViewArr(eltType=eltType, dom=this, arr=newarr);
  }

  proc dsiGetIndices() {
    return updom.dsiGetIndices();
  }

  proc dsiDims() {
    return updom.dsiDims();
  }

  proc dsiDim(i) {
    return updom.dsiDim(i);
  }

  proc dsiLow return updom.dsiLow;
  proc dsiHigh return updom.dsiHigh;
  proc dsiStride return updom.dsiStride;

  proc dsiNumIndices {
    return updom.dsiNumIndices;
  }

  proc dsiMember(i) {
    //    writeln("Reindex xhecking membership of: ", i);
    return updom.dsiMember(i);
  }

  inline iter these() {
    for i in updom do
      yield i;
  }

  inline iter these(param tag: iterKind) where tag == iterKind.leader {
    //    writeln("In reindexviewdom leader");
    for followThis in downdom.these(tag) do {
      //      writeln("yielding ", followThis);
      yield followThis;
    }
  }

  inline iter these(param tag: iterKind, followThis)
    where tag == iterKind.follower {
    for i in updom.these(tag, followThis) do
      yield i;
  }

  proc dsiSupportsPrivatization() param
    return downdom.dsiSupportsPrivatization();

  proc dsiGetPrivatizeData() return (updom.dsiDims(), downdom.pid);

  proc dsiPrivatize(privatizeData) {
    const (updomdims, privdowndomID) = privatizeData;
    const privdowndom = chpl_getPrivatizedCopy(downdom.type, privdowndomID);
    //    writeln("*** about to return new ArrayReindexViewDom ****");
    //
    // TODO: Am I going to be in trouble here if the source of the
    // privatization did not store updom as a defaultrectangular
    // itself?  Can I / should I just always store updom that way?
    //
    var newdom = {(...updomdims)};
    if !noRefCount then
      newdom._value.incRefCount();
    return new ArrayReindexViewDom(idxType=updomdims(1).idxType, 
                                   updom=newdom._value, 
                                   downdom=privdowndom);
  }

  proc dsiGetReprivatizeData() {
    //    compilerError("In dsiGetReprivatizeData");
    // HACK!  Must remove this ***
    //    updom = {2..11, 2..11}._value;
    //    writeln("********* In GetReprivatizeData *************");
    //    dsiDisplayRepresentation();
    //    writeln("********* Done ******************************");
    return updom.dsiDims();
  }
  
  proc dsiReprivatize(other, reprivatizeData) {
    //    writeln("Got: ", reprivatizeData);
    //    writeln("Other = ", other);
    //
    // TODO: Am I going to be in trouble here if the source of the
    // privatization did not store updom as a defaultrectangular
    // itself?  Can I / should I just always store updom that way?
    //
    var newdom = {(...reprivatizeData)};
    if !noRefCount then
      newdom._value.incRefCount();
    updom=newdom._value;
  }

  proc destroyDist() {
    //    writeln("Being asked to destroy self");
    return 999;  // we never want to destroy ourselves as the dist
  }

  proc dsiDestroyDistClass() {
    // no-op;
  }
}


class ArrayReindexViewArr: BaseArr {
  type eltType;
  const dom;
  const arr;
  var pid = -1;

  proc isArrayReindexView() param { return true; }
  proc idxType type return arr.idxType;
  proc rank param return arr.rank;

  //
  // For serial/standalone/leader/follower, the arity of the domains
  // is identical even though the indices are different, so given that
  // the leader/follower interface already factors the precise index
  // values out of the equation, we can just call into the array's
  // leader/follower iterators directly.
  //
  inline iter these() ref {
    for a in arr do
      yield a;
  }

  inline iter these(param tag: iterKind) where tag == iterKind.leader {
    //    writeln("**** In array reindex view leader");
    for followThis in arr.these(tag) do
      yield followThis;
  }

  inline iter these(param tag: iterKind, followThis) ref
    where tag == iterKind.follower {
    for a in arr.these(tag, followThis) do
      yield a;
  }

  inline proc dsiAccess(i: integral) ref {
    return dsiAccess((i,));
  }

  inline proc dsiAccess(i) ref {
    //    writeln("Reindex incoming index: ", i);
    //    dom.dsiDisplayRepresentation();
    if boundsChecking then
      if !dom.dsiMember(i) then
        halt("array index out of bounds: ", i);
    if (dom.rank == 1) {
      const pos_i = dom.dsiDim(1).indexOrder((...i));
      const ind_i = arr.dom.dsiDim(1).orderToIndex(pos_i);
      //      writeln("Reindex outgoing index: ", ind_i);
      return arr.dsiAccess(ind_i);
    } else {
      var ind_i: dom.rank*dom.idxType;
      for d in 1..dom.rank {
        const pos_i_d = dom.dsiDim(d).indexOrder(i(d));
        ind_i(d) = arr.dom.dsiDim(d).orderToIndex(pos_i_d);
      }
      //      writeln("Reindex outgoing index: ", ind_i);
      return arr.dsiAccess(ind_i);
    }
  }

  inline proc dsiGetBaseDom() {
    return dom;
  }

  proc dsiTargetLocales() {
    return arr.dsiTargetLocales();
  }

  /*
  proc doiBulkTransfer(B) {
    arr.doiBulkTransfer(B);
  }
  */

  proc dsiSerialWrite(f: Writer) {
    chpl_rectArrayReadWriteHelper(f, this, dom);
  }

  proc dsiDisplayRepresentation() {
    writeln("ArrayReindexViewArr {");
    write("  dom: {");
    dom.dsiDisplayRepresentation();
    write("  arr's dom: {");
    arr.dom.dsiDisplayRepresentation();
    writeln("}");
  }
  

  proc dsiSupportsPrivatization() param {
    if (arr.dsiSupportsPrivatization() != dom.dsiSupportsPrivatization()) then
      compilerWarning("Expected arr/dom privatization to always match");
    return arr.dsiSupportsPrivatization() && dom.dsiSupportsPrivatization();
  }

  proc dsiGetPrivatizeData() { 
    //    writeln(here.id, ": *** about to return privatizeData for:");
    //    this.dsiDisplayRepresentation();
    //    writeln(here.id, ": *** about to return");
    //    writeln(here.id, "arr.pid = ", arr.pid);
    //    writeln(here.id, "arr.type = ", typeToString(arr.type));
    return (dom.pid, arr.pid);
  }

  proc dsiPrivatize(privatizeData) {
    //    writeln(here.id, ": ***** In dsiPrivatize");
    const (privdomID, privarrID) = privatizeData;
    const privdom = chpl_getPrivatizedCopy(dom.type, privdomID);
    //    writeln(here.id, ": ***** About to show privdom");
    //    privdom.dsiDisplayRepresentation();
    const privarr = chpl_getPrivatizedCopy(arr.type, privarrID);
    //    writeln(here.id, "arr.pid = ", arr.pid);
    //    writeln(here.id, "arr.type = ", typeToString(arr.type));
    //    writeln(here.id, ": ***** About to show privarr");
    //    privarr.dom.dsiDisplayRepresentation();
    //    writeln(here.id, ": ***** About to return new array");
    return new ArrayReindexViewArr(eltType=eltType, dom=privdom, arr=privarr);
  }
}


class ArrayRankChangeViewDom: BaseRectangularDom {
  type idxType;
  //
  // TODO: Turn back to const
  //
  var updom;
  const downdom;
  const collapsedDim;
  const idx;
  var pid = -1;

  proc dist {
    return this;
  }

  proc _value {
    return this;
  }

  proc dsiNewRectangularDom(param rank, type idxType, param stridable) {
    return new ArrayRankChangeViewDom(idxType=idxType, updom=updom, 
                                      downdom=downdom,
                                      collapsedDim=collapsedDim, idx=idx);
  }

  proc dsiBuildRectangularDom(param rank, type idxType, param stridable,
                              ranges) {
    const newupdom = {(...ranges)};
    var newranges: downdom.rank*range(idxType=idxType, stridable=stridable); // = downdom.dsiDims();

    var j = 1;
    for param d in 1..downdom.rank {
      if !collapsedDim(d) {
        newranges(d) = ranges(j);
        j += 1;
      } else {
        newranges(d) = downdom.dsiDim(d);
      }
    }
    //
    // TODO: Must somehow preserve downdom's domain map
    // TODO: Did I do this for the reindex case?
    //
    const newdowndom = _newDomain(downdom.dsiBuildRectangularDom(downdom.rank,
                                                                 idxType,
                                                                 stridable,
                                                                 newranges));
   
    if !noRefCount {
      newupdom._value.incRefCount();
      newdowndom._value.incRefCount();
    }

    var retval = new ArrayRankChangeViewDom(idxType=idxType, 
                                            updom=newupdom._value,
                                            downdom=newdowndom._value,
                                            collapsedDim=collapsedDim,
                                            idx=idx);

    return retval;
  }

  proc rank param {
    return updom.rank;
  }

  proc stridable param {
    return updom.stridable;
  }

  proc linksDistribution() param return false;
  proc dsiLinksDistribution() return false;

  //
  // TODO: I don't think this'll actually work if it's used
  // for anything other than initialization.  If someone
  // really re-set the indices for a domain that was created
  // from this distribution, we'd need to ask for the new
  // domain all the way down the stack, similar to in the
  // dsiBuildRectangularDom routine.
  //
  proc dsiSetIndices(x) {
    var newdom = {(...x)};
    if !noRefCount then
      newdom._value.incRefCount();
    updom = newdom._value;
  }

  proc dsiSerialWrite(f: Writer) {
    updom.dsiSerialWrite(f);
  }

  proc dsiDisplayRepresentation() {
    writeln("ArrayRankChangeViewDom {");
    write("  updom: {");
    updom.dsiDisplayRepresentation();
    write("  downdom {");
    downdom.dsiDisplayRepresentation();
    writeln("  collapsedDim: ", collapsedDim);
    writeln("  idx: ", idx);
    writeln("}");
  }

  proc dsiMyDist(): BaseDist {
    return nil;
  }

  proc dsiBuildArray(type eltType) {
    var newarr = _newArray(downdom.dsiBuildArray(eltType))._value;
    return new ArrayRankChangeViewArr(eltType=eltType, dom=this, arr=newarr, collapsedDim=collapsedDim, idx=idx);
  }

  proc dsiGetIndices() {
    return updom.dsiGetIndices();
  }

  proc dsiDims() {
    return updom.dsiDims();
  }

  proc dsiDim(i) {
    return updom.dsiDim(i);
  }

  proc dsiLow return updom.dsiLow;
  proc dsiHigh return updom.dsiHigh;
  proc dsiStride return updom.dsiStride;

  proc dsiNumIndices {
    return updom.dsiNumIndices;
  }

  proc dsiMember(i) {
    return updom.dsiMember(i);
  }

  inline iter these() {
    for i in updom do
      yield i;
  }

  inline iter these(param tag: iterKind) where tag == iterKind.leader {
    //    writeln("In rank change viewdom leader");
    //
    // STOPPED HERE::  This is wrong...  Need to use updom's indices
    // (because they're a subset of downdom's) but to downdom's
    // distribution; suggesting we need a slice of updom against
    // downdom, but a rank-preserving slice; suggesting this needs
    // to be done back in ChapelArray.chpl.  :(
    //
    param arrRank = downdom.rank;
    for followThis in downdom.these(tag) {
      var followThisReally: updom.rank*followThis(1).type;
      var j = 1;
      for param d in 1..arrRank {
        if !collapsedDim(d) {
          followThisReally(j) = followThis(d);
          j += 1;
        }
      }
      yield followThisReally;
    }
  }

  inline iter these(param tag: iterKind, followThis)
    where tag == iterKind.follower {
    for i in updom.these(tag, followThis) do
      yield i;
  }

  proc dsiSupportsPrivatization() param
    return downdom.dsiSupportsPrivatization();

  proc dsiGetPrivatizeData() return (updom.dsiDims(), downdom.pid,
                                      collapsedDim, idx);

  proc dsiPrivatize(privateData) {
    const (updomdims, privdowndomID, collapsedDim, idx) = privateData;
    const privdowndom = chpl_getPrivatizedCopy(downdom.type, privdowndomID);
    var newdom = {(...updomdims)};
    if !noRefCount then
      newdom._value.incRefCount();
    return new ArrayRankChangeViewDom(idxType=idxType, updom=newdom._value, downdom=privdowndom, collapsedDim=collapsedDim, idx=idx);
  }

  proc dsiGetReprivatizeData() {
    return updom.dsiDims();
  }

  proc dsiReprivatize(other, reprivatizeData) {
    var newdom = {(...reprivatizeData)};
    if !noRefCount then
      newdom._value.incRefCount();
    updom=newdom._value;
  }

  proc destroyDist() {
    return 999;  // we never want to destroy ourselves as the dist
  }

  proc dsiDestroyDistClass() {
    // no-op;
  }
}


class ArrayRankChangeViewArr: BaseArr {
  type eltType;
  const dom;
  const arr;
  const collapsedDim;
  const idx;
  var pid = -1;

  proc idxType type return arr.idxType;
  proc rank param return dom.rank;

  //
  // For serial/standalone/leader/follower, the arity of the domain
  // differs from the arity of the arrays, as with the slice array
  // view.  So we must iterate over the domain, accessing the array.
  //
  inline iter these() ref {
    for i in dom do
      yield dsiAccess(i);
  }

  inline iter these(param tag: iterKind) where tag == iterKind.leader {
    //    writeln("In rank change view arr leader");
    for followThis in dom.these(tag) do {
      yield followThis;
    }
  }

  inline iter these(param tag: iterKind, followThis) ref
    where tag == iterKind.follower {
    for i in dom.these(tag, followThis) do
      yield dsiAccess[i];
  }

  inline proc dsiAccess(i: integral) ref {
    return dsiAccess((i,));
  }

  inline proc dsiAccess(i) ref {
    //    writeln("RankChange Incoming index = ", i);
    if boundsChecking then
      if !dom.dsiMember(i) then
        halt("array index out of bounds: ", i);
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
    //    writeln("RankChange Outgoing index = ", ind);

    return arr.dsiAccess(ind);
  }

  inline proc dsiGetBaseDom() {
    return dom;
  }

  proc dsiTargetLocales() {
    return arr.dsiTargetLocales();
  }

  /*
  proc doiBulkTransfer(B) {
    arr.doiBulkTransfer(B);
  }
  */

  proc dsiSerialWrite(f: Writer) {
    chpl_rectArrayReadWriteHelper(f, this, dom);
  }

  proc dsiDisplayRepresentation() {
    writeln("ArrayRankChangeViewArr {");
    write("  dom: ");
    dom.dsiDisplayRepresentation();
    write("  arr's dom: ");
    arr.dom.dsiDisplayRepresentation();
    writeln("  collapsedDim: ", collapsedDim);
    writeln("  idx: ", idx);
    writeln("}");
  }

  proc dsiSupportsPrivatization() param {
    if (arr.dsiSupportsPrivatization() != dom.dsiSupportsPrivatization()) then
      compilerWarning("Expected arr/dom privatization to always match");
    return arr.dsiSupportsPrivatization() && dom.dsiSupportsPrivatization();
  }

  proc dsiGetPrivatizeData() return (dom.pid, arr.pid, collapsedDim, idx);

  proc dsiPrivatize(privatizeData) {
    const (privdomID, privarrID, collapsedDim, idx) = privatizeData;
    const privdom = chpl_getPrivatizedCopy(dom.type, privdomID);
    const privarr = chpl_getPrivatizedCopy(arr.type, privarrID);
    return new ArrayRankChangeViewArr(eltType=eltType, dom=privdom, arr=privarr, collapsedDim=collapsedDim, idx=idx);
  }
}
