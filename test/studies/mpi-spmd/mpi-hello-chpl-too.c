#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include "ChapelHello.h"

int main(int argc, char* argv[]) {
  MPI_Init(&argc, &argv);

  char* chpl_argv[3];
  chpl_argv[0] = argv[0];
  chpl_argv[1] = "-nl4";
  chpl_argv[2] = "";

  chpl_library_init(2, chpl_argv);
  chpl__init_ChapelHello(0, 0);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  printf("Hello from rank %d of %d\n", rank, size);
  localHello(rank);

  chpl_library_finalize();
  
  MPI_Finalize();

  exit(0);
}
