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
    for followThis in dom.these(tag) do
      yield followThis;
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


class ArrayReindexViewDom: BaseRectangularDom {
  type idxType;
  const updom;
  const downdom;
  const dist: DefaultDist;
  var pid = -1;

  proc rank param {
    return updom.rank;
  }

  proc stridable param {
    return updom.stridable;
  }

  proc linksDistribution() param return false;

  /*
  proc linksDistribution() param return dom.linksDistribution();
  proc dsiLinksDistribution() return dom.dsiLinksDistribution();

  proc dsiMyDist() {
    return dom.dsiMyDist();
  }
  */

  proc dsiBuildArray(type eltType) {
    //
    // Do I need to do something different here, if privatized?
    //
    var newarr = downdom._value.dsiBuildArray(eltType);
    return new ArrayReindexViewArr(eltType=eltType, dom=this, arr=newarr);
  }

  proc dsiDim(i) {
    return updom._value.dsiDim(i);
  }

  proc dsiMember(i) {
    if (rank == 1) {
      const pos_i = updom._value.dsiDim(1).indexOrder((...i));
      const ind_i = downdom._value.dsiDim(1).orderToIndex(pos_i);
      return downdom._value.dsiMember(i);
    } else {
      var ind_i: rank*idxType;
      for d in 1..rank {
        const pos_i_d = updom._value.dsiDim(d).indexOrder(i(d));
        ind_i(d) = downdom._value.dsiDim(d).orderToIndex(pos_i_d);
      }
      return downdom._value.dsiMember(ind_i);
    }
  }

  inline iter these() {
    for i in updom do
      yield i;
  }

  inline iter these(param tag: iterKind) where tag == iterKind.leader {
    for followThis in downdom.these(tag) do
      yield followThis;
  }

  inline iter these(param tag: iterKind, followThis)
    where tag == iterKind.follower {
    for i in updom.these(tag, followThis) do
      yield i;
  }

  /*
  proc dsiSupportsPrivatization() param
    return dom.dsiSupportsPrivatization();

  proc dsiGetPrivatizeData() return dom.pid;

  proc dsiPrivatize(privatizeData) {
    const privdomID = privatizeData;
    const privdom = chpl_getPrivatizedCopy(dom.type, privdomID);
    return new ArraySliceViewArr(dom=privdom);
  }
  */
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
    for followThis in arr.these(tag) do
      yield followThis;
  }

  inline iter these(param tag: iterKind, followThis) ref
    where tag == iterKind.follower {
    for i in arr.these(tag, followThis) do
      yield i;
  }

  inline proc dsiAccess(i: integral) ref {
    return dsiAccess((i,));
  }

  inline proc dsiAccess(i) ref {
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

  /*
  proc dsiSupportsPrivatization() param
    return arr.dsiSupportsPrivatization() && dom.dsiSupportsPrivatization();

  proc dsiGetPrivatizeData() return (dom.pid, arr.pid);

  proc dsiPrivatize(privatizeData) {
    const (privdomID, privarrID) = privatizeData;
    const privdom = chpl_getPrivatizedCopy(dom.type, privdomID);
    const privarr = chpl_getPrivatizedCopy(arr.type, privarrID);
    return new ArrayReindexViewArr(eltType=eltType, dom=privdom, arr=privarr);
  }
  */
}


class ArrayRankchangeViewArr: BaseArr {
  type eltType;
  const dom;
  const arr;
  const collapsedDim;
  const idx;
  var pid = -1;

  proc idxType type return arr.idxType;
  proc rank param return dom.rank;

  inline iter these() ref {
    for i in dom do
      yield dsiAccess(i);
  }

  inline iter these(param tag: iterKind) where tag == iterKind.leader {
    for followThis in dom.these(tag) do
      yield followThis;
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
    if boundsChecking then
      if !dom.dsiMember(i) then
        halt("array index out of bounds: ", i);
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

  proc dsiSupportsPrivatization() param
    return arr.dsiSupportsPrivatization() && dom.dsiSupportsPrivatization();

  proc dsiGetPrivatizeData() return (dom.pid, arr.pid, collapsedDim, idx);

  proc dsiPrivatize(privatizeData) {
    const (privdomID, privarrID, collapsedDim, idx) = privatizeData;
    const privdom = chpl_getPrivatizedCopy(dom.type, privdomID);
    const privarr = chpl_getPrivatizedCopy(arr.type, privarrID);
    return new ArrayRankChangeViewArr(eltType=eltType, dom=privdom, arr=privarr, collapsedDim, idx);
  }
}
