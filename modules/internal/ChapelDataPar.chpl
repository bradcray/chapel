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

// ChapelDataPar.chpl
//
module ChapelDataPar {
  use ChapelConfig, ChapelOps;

  @unstable("The variable 'dataParTasksPerLocale' is unstable and its interface is subject to change in the future")
  config const dataParTasksPerLocale = 0;
  @unstable("The variable 'dataParIgnoreRunningTasks' is unstable and its interface is subject to change in the future")
  config const dataParIgnoreRunningTasks = false;
  @unstable("The variable 'dataParMinGranularity' is unstable and its interface is subject to change in the future")
  config const dataParMinGranularity: int = 1;

  if dataParTasksPerLocale<0 then halt("dataParTasksPerLocale must be >= 0");
  if dataParMinGranularity<=0 then halt("dataParMinGranularity must be > 0");

  inline proc getDataParTasksPerLocale() {
    return dataParTasksPerLocale;
  }

  inline proc getDataParIgnoreRunningTasks() {
    return dataParIgnoreRunningTasks;
  }

  inline proc getDataParMinGranularity() {
    return dataParMinGranularity;
  }
}