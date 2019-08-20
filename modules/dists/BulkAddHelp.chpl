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

module BulkAddHelp {
  // (1) sorts indices if !dataSorted
  // (2) verifies the flags are set correctly if boundsChecking
  // (3) checks OOB if boundsChecking
  proc bulkAdd_prepareInds(inds, dataSorted, isUnique, cmp) {
    use Sort;
    if !dataSorted then sort(inds, comparator=cmp);

    //verify sorted and no duplicates if not --fast
    if boundsChecking {
      if dataSorted && !isSorted(inds, comparator=cmp) then
        halt("bulkAdd: Data not sorted, call the function with \
              dataSorted=false");

      //check duplicates assuming sorted
      if isUnique {
        const indsStart = inds.domain.low;
        const indsEnd = inds.domain.high;
        var lastInd = inds[indsStart];
        for i in indsStart+1..indsEnd {
          if inds[i] == lastInd then
            halt("bulkAdd: There are duplicates, call the function \
                  with isUnique=false");
          else lastInd = inds[i];
        }
      }
      
      //check OOB
      for i in inds do boundsCheck(i);
    }
  }
}
