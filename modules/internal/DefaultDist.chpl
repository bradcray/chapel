/*
 * Copyright 2020-2023 Hewlett Packard Enterprise Development LP
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

// ChapelDefaultDist.chpl
//
module ChapelDefaultDist {
  config param debugDefaultDist = false;
  config param debugDefaultDistBulkTransfer = false;

  @unstable("DefaultDist is unstable and may change in the future")
  class DefaultDist: BaseDist {
    override proc dsiNewRectangularDom(param rank: int, type idxType,
                                       param strides: strideKind, inds) {
      const dom = new unmanaged DefaultRectangularDom(rank, idxType, strides,
                                                      _to_unmanaged(this));
      dom.dsiSetIndices(inds);
      return dom;
    }

    override proc dsiNewAssociativeDom(type idxType, param parSafe: bool) do
      return new unmanaged DefaultAssociativeDom(idxType, parSafe, _to_unmanaged(this));

    override proc dsiNewSparseDom(param rank: int, type idxType, dom: domain) do
      return new unmanaged DefaultSparseDom(rank, idxType, _to_unmanaged(this), dom);

    proc dsiTargetLocales() const ref {
      return EachLocSingletonArr[this.locale.id];
    }

    proc dsiIndexToLocale(ind) do return this.locale;

    // Right now, the default distribution acts like a singleton.
    // So we don't have to copy it when a clone is requested.
    proc dsiClone() do return _to_unmanaged(this);

    proc dsiAssign(other: this.type) { }

    proc dsiEqualDMaps(d:unmanaged DefaultDist) param do return true;
    proc dsiEqualDMaps(d) param do return false;

    proc trackDomains() param do return false;
    override proc dsiTrackDomains() do    return false;

    override proc singleton() param do return true;

    override proc dsiIsLayout() param do return true;
  }

  //
  // Replicated copies are set up in chpl_initOnLocales() during locale
  // model initialization
  //
  pragma "locale private"
  var defaultDist = new dmap(new unmanaged DefaultDist());

/*  Seemingly unused -- remove?
  proc chpl_defaultDistInitPrivate() {
    if defaultDist._value==nil {
      // FIXME benharsh: Here's what we want to do:
      //   defaultDist = new dmap(new DefaultDist());
      // The problem is that the LHS of the "proc =" for _distributions
      // loses its ref intent in the removeWrapRecords pass.
      //
      // The code below is copied from the contents of the "proc =".
      const nd = new dmap(new unmanaged DefaultDist());
      __primitive("move", defaultDist, chpl__autoCopy(nd.clone(),
                                                      definedConst=false));
    }
  }
  */
}