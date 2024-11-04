use CTypes;

export proc localHello(rank: c_int) {
  extern proc printf(args...);
  printf("Hello from locale %d aka MPI rank %d\n", here.id:c_int, rank);
  //  writef("Hello from locale %i aka MPI rank %i\n", here.id, rank);
  //  writeln("Hello from locale ", here.id, " aka MPI rank ", rank);
}

export proc DistHello(rank: c_int) {
  coforall loc in Locales do
    on loc do
      writeln("Hello from locale ", here.id);
}
