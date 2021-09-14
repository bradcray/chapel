/*
 * Copyright 2020-2021 Hewlett Packard Enterprise Development LP
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

#ifndef CHPL_RUNTIME_ETC_SRC_MLI_CHPL_MLI_LIBC_WRAPPERS_H
#define CHPL_RUNTIME_ETC_SRC_MLI_CHPL_MLI_LIBC_WRAPPERS_H

#include <stdlib.h>

void chpl_mli_libc_exit(int status) {
  exit(status);
}

void* chpl_mli_libc_malloc(size_t bytes) {
  return malloc(bytes);
}

void chpl_mli_libc_free(void* ptr) {
  free(ptr);
}

#endif