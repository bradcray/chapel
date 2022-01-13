Examples from Slides
====================
* Fibonacci Iterations
  o ./slideExamples/fibonacci/fib.chpl        : first version
  o ./slideExamples/fibonacci/fib-zipped.chpl : zippered version

* Task Parallel Hello World
  o ./slideExamples/taskPar/hello/hello-taskpar.chpl      : single-locale version
  o ./slideExamples/taskPar/hello/hello-taskpar-dist.chpl : distributed version

* Parallelism and Locality are Orthogonal in Chapel
  o ./slideExamples/taskPar/locParOrthog/parOnly.chpl
  o ./slideExamples/taskPar/locParOrthog/parLoc.chpl
  o ./slideExamples/taskPar/locParOrthog/locOnly.chpl

* Examples illustrating on-clauses and Chapel's global view
  o ./slideExamples/taskPar/onClauses/varsLocalToTask.chpl
  o ./slideExamples/taskPar/onClauses/remoteReadWrite.chpl
  o ./slideExamples/taskPar/onClauses/toy.chpl

* Data Parallel Array Fill
  o ./slideExamples/dataPar/fillArray.chpl      : single-locale version
  o ./slideExamples/dataPar/fillArray-dist.chpl : distributed version

* 3-point Stencil
  o ./slideExamples/dataPar/3PtStencil.chpl

* Jacobi Examples
  o ./slideExamples/jacobi/jacobi.chpl           : main single-locale version
  o ./slideExamples/jacobi/jacobi-tupleInds.chpl : using tuple indexing
  o ./slideExamples/jacobi/jacobi-slices.chpl    : using slices
./slideExamples/jacobi/jacobi-dist.chpl          : distributed version

Benchmarks / Applications Mentioned in Slides
=============================================
* Stream Triad:  $CHPL_HOME/examples/benchmarks/hpcc/[variants/]stream*.chpl
* HPCC RA:       $CHPL_HOME/examples/benchmarks/hpcc/[variants/]ra*.chpl
* Bale IndexGather: https://github.com/chapel-lang/chapel/tree/main/test/studies/bale/indexgather
* Arkouda: https://github.com/Bears-R-Us/arkouda
* CHAMPS: is not currently open-source, but is made available upon request
