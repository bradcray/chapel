#
# Assumes CHPL_COMM=mpi && 
#

include lib/Makefile.ChapelHello

./a.out: mpi-hello-chpl-too.c lib/ChapelHello.h lib/libChapelHello.a
	mpicc mpi-hello-chpl-too.c -I lib/ $(CHPL_CFLAGS) $(CHPL_LDFLAGS)

lib/ChapelHello.h lib/libChapelHello.a: ChapelHello.chpl Makefile
#	chpl --library --library-makefile ChapelHello.chpl --comm=gasnet --comm-substrate=mpi
	chpl --library --library-makefile ChapelHello.chpl

test: ./a.out
	mpirun -np 4 ./a.out
