/*
 * Copyright 2004-2019 Cray Inc.
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

module DomainViewSliceRanges {
  use ChapelStandard;

  //
  // This class represents the domain of a range-based slice of an
  // array.  Like other domain class implementations, it supports the
  // standard dsi interface.  Note that range-based slicing only makes
  // sense for rectangular domains, so this is a subclass of
  // BaseRectangularDom.
  class DomainViewSliceRanges : BaseRectangularDom {
    const ranges: rank*range;

    // the domain that we're slicing
    //
    var sliceePid:int;
    var sliceeInst; //: sliceeType(collapsedDim.size, idxType, stridable, distInst);

    inline proc slicee {
      if _isPrivatized(sliceeInst) then
        return chpl_getPrivatizedCopy(sliceeInst.type, sliceePid);
      else
        return sliceeInst;
    }

    inline proc dist {
      return slicee.dist;
    }

    proc dsiBuildArray(type eltType) {
      pragma "no auto destroy"
      const newarr = _newArray(slicee.dsiBuildArray(eltType));
      return new unmanaged ArrayViewSliceArr(eltType  =eltType,
                                             _DomPid = this.pid,
                                             dom = _to_unmanaged(this),
                                             _ArrPid=newarr._pid,
                                             _ArrInstance=newarr._instance);
    }

    proc dsiSetIndices(inds) {
      compilerError("indices of range-sliced domains can't be changed");
    }

    proc dsiDim(dim: int) {
      return (slicee.dsiDim(dim))[ranges(dim)];
    }

    proc dsiDims() {
      var inds: rank*range;
      for i in 1..rank do
        inds(i) = dsiDim(i);
      return inds;
    }

    proc dsiNumIndices {
      var tot = 0;
      for i in 1..rank do
        tot += dsiDim(i).size;
      return tot;
    }

    proc dsiLow {
      if rank == 1 {
        return dsiDim(1).low;
      } else {
        var result: rank*idxType;
        for param i in 1..rank do
          result(i) = dsiDim(i).low;
        return result;
      }

    }

    proc dsiGetIndices() {
      return dsiDims();
    }

    proc dsiAssignDomain(rhs: domain, lhsPrivate: bool) {
      this.ranges = rhs._value.ranges;
    }

    iter these() {
      const ranges = dsiDims();
      for i in ranges(1) {
        for j in ranges(2) {
          yield (i,j);
        }
      }
    }

    iter these(param tag: iterKind) where tag == iterKind.standalone
      && !localeModelHasSublocales
      && chpl__isDROrDRView(slicee)
    {
      for inds in these() do
        yield inds();
    }

    iter these(param tag: iterKind) where tag == iterKind.standalone
      && !localeModelHasSublocales
      && !chpl__isDROrDRView(slicee)
    {
      for inds in these() do
        yield inds();
    }


    iter these(param tag: iterKind) where tag == iterKind.leader {
      yield dsiDims();
    }

    iter these(param tag: iterKind, followThis)
      where tag == iterKind.follower {
      for inds in these() do
        yield inds;
    }

    // TODO: Is there something we can re-use here?
    proc dsiSerialWrite(f) {
      halt("Haven't implemented writeln() yet");
      var first = true;
      for d in 1..rank do
        if !collapsedDim(d) {
          if first {
            f <~> "{";
            first = false;
          } else
            f <~> ", ";
          f <~> slicee.dsiDim(d);
        }
      f <~> "}";
    }

    override proc dsiMyDist() {
      return dist;
    }

    proc dsiTargetLocales() {
      //
      // BLC: there's a bit of a question in my mind about whether
      // sliced domains ought to be expected to list only the subset
      // of locales that have non-empty subdomains for a given
      // domain/array, or whether all locales in the
      // domain's/distribution's target locale set should be listed
      // since they are part of the target locale set.  Both seem like
      // they could be useful, though the former seems as though it
      // could be challenging to compute precisely for less regular
      // distributions.  Here I've done the easy thing and simply
      // returned all the locales that own the domain being sliced.
      // 
      return slicee.dsiTargetLocales();
    }

    proc dsiHasSingleLocalSubdomain() param
      return slicee.dsiHasSingleLocalSubdomain();

    proc dsiLocalSubdomain(loc: locale) {
      halt("Not yet implemented");
      /*
      const dims = slicee.dsiLocalSubdomain(loc).dims();
      const empty : domain(rank, idxType, chpl__anyStridable(dims));

      // If the rank-changed dimension's index is not a member of the range
      // in the same dimension of 'dims', then this locale does not have a
      // local subdomain.
      for param d in 1..dims.size {
        if collapsedDim(d) && dims(d).isEmpty() then
          return empty;
      }

      return chpl_rankChangeConvertDownToUp(dims, rank, collapsedDim);
      */
    }

    proc isRankChangeDomainView() param {
      return true;
    }

    proc _getActualDomain() {
      if chpl__isDomainView(slicee) {
        return slicee._getActualDomain();
      } else {
        return slicee;
      }
    }

    override proc dsiDestroyDom() {
      if sliceeInst != nil then
        _delete_dom(sliceeInst, _isPrivatized(sliceeInst));
    }

    /*
    // Don't want to privatize a DefaultRectangular, so pass the query on to
    // the wrapped array
    proc dsiSupportsPrivatization() param
      return sliceeInst.dsiSupportsPrivatization();

    proc dsiGetPrivatizeData() {
      return (upDom, collapsedDim, idx, distPid, distInst, sliceePid, sliceeInst);
    }

    proc dsiPrivatize(privatizeData) {
      return new unmanaged ArrayViewRankChangeDom(rank = this.rank,
                                        idxType = this.idxType,
                                        stridable = this.stridable,
                                        upDom = privatizeData(1),
                                        collapsedDim = privatizeData(2),
                                        idx = privatizeData(3),
                                        distPid = privatizeData(4),
                                        distInst = privatizeData(5),
                                        sliceePid = privatizeData(6),
                                        sliceeInst = privatizeData(7));
    }

    proc dsiGetReprivatizeData() {
      return (upDom, sliceePid, sliceeInst);
    }

    proc dsiReprivatize(other, reprivatizeData) {
      upDom = reprivatizeData(1);
      //      collapsedDim = other.collapsedDim;
      //      idx = other.idx;
      //      distPid = other.distPid;
      //      distInst = other.distInst;
      sliceePid = reprivatizeData(2);
      sliceeInst = reprivatizeData(3);
    }
    */

 } // end of class ArrayViewRankChangeDom
}