include lib/Makefile.ChapelHello

./a.out: mpi-hello-chpl-too.c lib/ChapelHello.h lib/libChapelHello.a
	mpicc mpi-hello-chpl-too.c -I lib/ $(CHPL_CFLAGS) $(CHPL_LDFLAGS)

lib/ChapelHello.h lib/libChapelHello.a: ChapelHello.chpl
	chpl --library --library-makefile ChapelHello.chpl

