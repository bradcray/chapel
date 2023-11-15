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

// ChapelTasking.chpl
//
module ChapelTasking {
  use ChapelDataPar, ChapelContext, Errors, ChapelLocale, ChplConfig;

  proc chpl_resetTaskSpawn(numTasks) {
    const dptpl = if dataParTasksPerLocale==0 then here.maxTaskPar
                  else dataParTasksPerLocale;

    if numTasks >= dptpl {
      chpl_rt_reset_task_spawn();
    } else if numTasks == 1 {
      // Don't create a task for local single iteration coforalls
      use ChapelTaskData;
      var tls = chpl_task_getInfoChapel();
      chpl_task_data_setNextCoStmtSerial(tls, true);
    }
  }

  // This function is called by the initiating task once for each new
  // task *before* any of the tasks are started.  As above, no on
  // statement needed.
  pragma "dont disable remote value forwarding"
  pragma "no remote memory fence"
  pragma "task spawn impl fn"
  proc _upEndCount(e: _EndCount, param countRunningTasks=true) {
    if isAtomic(e.taskCnt) {
      e.add(1, memoryOrder.release);
      e.taskCnt.add(1, memoryOrder.release);
    } else {
      // note that this on statement does not have the usual
      // remote memory fence because of pragma "no remote memory fence"
      // above. So we do an acquire fence before it.
      chpl_rmem_consist_fence(memoryOrder.release);
      on e {
        e.add(1, memoryOrder.release);
        e.taskCnt += 1;
      }
    }
    if countRunningTasks {
      here.runningTaskCntAdd(1);  // decrement is in _waitEndCount()
      chpl_comm_task_create();    // countRunningTasks is a proxy for "is local"
                                  // here.  Comm layers are responsible for the
                                  // remote case themselves.
    }
  }

  pragma "dont disable remote value forwarding"
  pragma "no remote memory fence"
  pragma "task spawn impl fn"
  proc _upEndCount(e: _EndCount, param countRunningTasks=true, numTasks) {
    e.add(numTasks:int, memoryOrder.release);

    if countRunningTasks {
      if numTasks > 1 {
        here.runningTaskCntAdd(numTasks:int-1);  // decrement is in _waitEndCount()
      }
      chpl_comm_task_create();    // countRunningTasks is a proxy for "is local"
                                  // here.  Comm layers are responsible for the
                                  // remote case themselves.
    } else {
      here.runningTaskCntSub(1);
    }
  }

  // This function is called once by the initiating task.  As above, no
  // on statement needed.
  // called for sync blocks (implicit or explicit), unbounded coforalls
  pragma "dont disable remote value forwarding"
  pragma "task join impl fn"
  pragma "unchecked throws"
  proc _waitEndCount(e: _EndCount, param countRunningTasks=true) throws {
    // Remove the task that will just be waiting/yielding in the following
    // waitFor() from the running task count to let others do real work. It is
    // re-added after the waitFor().
    here.runningTaskCntSub(1);

    // Wait for all tasks to finish
    e.waitFor(0, memoryOrder.acquire);

    if countRunningTasks {
      const taskDec = if isAtomic(e.taskCnt) then e.taskCnt.read() else e.taskCnt;
      // taskDec-1 to adjust for the task that was waiting for others to finish
      here.runningTaskCntSub(taskDec-1);  // increment is in _upEndCount()
    } else {
      // re-add the task that was waiting for others to finish
      here.runningTaskCntAdd(1);
    }

    // Throw any error raised by a task this is waiting for
    if ! e.errors.empty() then
      throw new owned TaskErrors(e.errors);
  }

  // called for bounded coforalls and cobegins
  pragma "dont disable remote value forwarding"
  pragma "task join impl fn"
  pragma "unchecked throws"
  proc _waitEndCount(e: _EndCount, param countRunningTasks=true, numTasks) throws {
    // Wait for all tasks to finish
    e.waitFor(0, memoryOrder.acquire);

    if countRunningTasks {
      if numTasks > 1 {
        here.runningTaskCntSub(numTasks:int-1);
      }
    } else {
      here.runningTaskCntAdd(1);
    }

    // Throw any error raised by a task this is waiting for
    if ! e.errors.empty() then
      throw new owned TaskErrors(e.errors);
  }

  pragma "task spawn impl fn"
  proc _upDynamicEndCount(param countRunningTasks=true) {
    var e = __primitive("get dynamic end count");
    _upEndCount(e, countRunningTasks);
  }

  // This function is called once by each newly initiated task.  No on
  // statement is needed because the call to sub() will do a remote
  // fork (on) if needed.
  pragma "dont disable remote value forwarding"
  pragma "task complete impl fn"
  pragma "down end count fn"
  proc _downEndCount(e: _EndCount, err: unmanaged Error?) {
    chpl_save_task_error(e, err);
    if CHPL_LOCALE_MODEL == "gpu" {
      pragma "task complete impl fn"
      extern proc chpl_gpu_task_end(): void;

      chpl_gpu_task_end();
    }
    chpl_comm_task_end();
    // inform anybody waiting that we're done
    e.sub(1, memoryOrder.release);
  }

  pragma "dont disable remote value forwarding"
  pragma "task complete impl fn"
  pragma "down end count fn"
  proc _downDynamicEndCount(err: unmanaged Error?) {
    var e = __primitive("get dynamic end count");
    _downEndCount(e, err);
  }

  // This version is called for normal sync blocks.
  pragma "task join impl fn"
  pragma "unchecked throws"
  proc chpl_waitDynamicEndCount(param countRunningTasks=true) throws {
    var e = __primitive("get dynamic end count");
    _waitEndCount(e, countRunningTasks);

    // Throw any error raised by a task this sync statement is waiting for
    if ! e.errors.empty() then
      throw new owned TaskErrors(e.errors);
  }

  config param commDiagsTrackEndCounts = false;

  pragma "no default functions"
  record endCountDiagsManager : contextManager {
    var taskInfo: c_ptr(chpl_task_infoChapel_t);
    var prevDiagsDisabledVal: bool;

    inline proc ref enterContext() {
      if !commDiagsTrackEndCounts {
        taskInfo = chpl_task_getInfoChapel();
        prevDiagsDisabledVal = chpl_task_data_setCommDiagsTemporarilyDisabled(taskInfo, true);
      }
    }

    inline proc exitContext(in unused: owned Error?) {
      if !commDiagsTrackEndCounts {
        chpl_task_data_setCommDiagsTemporarilyDisabled(taskInfo, prevDiagsDisabledVal);
      }
    }
  }

  // Parent class for _EndCount instances so that it's easy
  // to add non-generic fields here.
  // And to get 'errors' field from any generic instantiation.
  pragma "no default functions"
  class _EndCountBase {
    var errors: chpl_TaskErrors;
  }

  pragma "end count"
  pragma "no default functions"
  class _EndCount : _EndCountBase {
    type iType;
    type taskType;
    var i: iType;
    var taskCnt: taskType;
    proc init(type iType, type taskType) {
      this.iType = iType;
      this.taskType = taskType;
    }

    inline proc add(value: int, param order: memoryOrder) {
      manage new endCountDiagsManager() do
        this.i.add(value, order);
    }

    inline proc sub(value: int, param order: memoryOrder) {
      manage new endCountDiagsManager() do
        this.i.sub(value, order);
    }

    inline proc waitFor(value: int, param order: memoryOrder) {
      manage new endCountDiagsManager() do
        this.i.waitFor(value, order);
    }
  }

  // This function is called once by the initiating task.  No on
  // statement needed, because the task should be running on the same
  // locale as the sync/coforall/cobegin was initiated on and thus the
  // same locale on which the object is allocated.
  //
  // TODO: 'taskCnt' can sometimes be local even if 'i' has to be remote.
  // It is currently believed that only a remote-begin will want a network
  // atomic 'taskCnt'. There should be a separate argument to control the type
  // of 'taskCnt'.
  pragma "dont disable remote value forwarding"
  inline proc _endCountAlloc(param forceLocalTypes : bool) {
    type taskCntType = if !forceLocalTypes && useAtomicTaskCnt then atomic int
                                           else int;
    if forceLocalTypes {
      return new unmanaged _EndCount(iType=chpl__processorAtomicType(int),
                                     taskType=taskCntType);
    } else {
      return new unmanaged _EndCount(iType=chpl__atomicType(int),
                                     taskType=taskCntType);
    }
  }

  // Compiler looks for this variable to determine the return type of
  // the "get end count" primitive.
  type _remoteEndCountType = _endCountAlloc(false).type;

  // This function is called once by the initiating task.  As above, no
  // on statement needed.
  pragma "dont disable remote value forwarding"
  inline proc _endCountFree(e: _EndCount) {
    delete _to_unmanaged(e);
  }
}