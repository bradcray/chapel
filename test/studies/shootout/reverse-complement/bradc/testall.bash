#!/bin/bash

echo compiling fasta
chpl $CHPL_HOME/test/studies/shootout/fasta/kbrady/fasta-printf.chpl --fast -o tmpFasta
echo creating revcomp input
./tmpFasta --n=100000000 -nl 1 > fasta.rvcmp
echo compiling revcomp-submitted-2
chpl --fast revcomp-submitted-2.chpl
echo compiling revcomp-blc
chpl --fast revcomp-blc.chpl
echo compiling revcomp-blc-noref
chpl --fast revcomp-blc-noref.chpl
echo compiling revcomp-zip
chpl --fast revcomp-blc-zip.chpl
echo compiling revcomp-zip-noref
chpl --fast revcomp-blc-zip-noref.chpl
echo compiling revcomp-par
chpl --fast revcomp-blc-par.chpl
echo compiling revcomp-par-noref
chpl --fast revcomp-blc-par-noref.chpl
echo compiling revcomp-gcc-5
gcc -O3 revcomp-gcc-5.c -o revcomp-gcc-5

echo revcomp-submitted-2
time -p ./revcomp-submitted-2 < fasta.rvcmp > /dev/null
time -p ./revcomp-submitted-2 < fasta.rvcmp > /dev/null
time -p ./revcomp-submitted-2 < fasta.rvcmp > /dev/null
time -p ./revcomp-submitted-2 < fasta.rvcmp > /dev/null
time -p ./revcomp-submitted-2 < fasta.rvcmp > /dev/null

echo revcomp-blc
time -p ./revcomp-blc < fasta.rvcmp > /dev/null
time -p ./revcomp-blc < fasta.rvcmp > /dev/null
time -p ./revcomp-blc < fasta.rvcmp > /dev/null
time -p ./revcomp-blc < fasta.rvcmp > /dev/null
time -p ./revcomp-blc < fasta.rvcmp > /dev/null

echo revcomp-blc-noref
time -p ./revcomp-blc-noref < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-noref < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-noref < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-noref < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-noref < fasta.rvcmp > /dev/null

echo revcomp-blc-zip
time -p ./revcomp-blc-zip < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-zip < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-zip < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-zip < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-zip < fasta.rvcmp > /dev/null

echo revcomp-blc-zip-noref
time -p ./revcomp-blc-zip-noref < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-zip-noref < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-zip-noref < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-zip-noref < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-zip-noref < fasta.rvcmp > /dev/null

echo revcomp-blc-par
time -p ./revcomp-blc-par < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-par < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-par < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-par < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-par < fasta.rvcmp > /dev/null

echo revcomp-blc-par-noref
time -p ./revcomp-blc-par-noref < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-par-noref < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-par-noref < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-par-noref < fasta.rvcmp > /dev/null
time -p ./revcomp-blc-par-noref < fasta.rvcmp > /dev/null

echo revcomp-gcc-5
time -p ./revcomp-gcc-5 < fasta.rvcmp > /dev/null
time -p ./revcomp-gcc-5 < fasta.rvcmp > /dev/null
time -p ./revcomp-gcc-5 < fasta.rvcmp > /dev/null
time -p ./revcomp-gcc-5 < fasta.rvcmp > /dev/null
time -p ./revcomp-gcc-5 < fasta.rvcmp > /dev/null
