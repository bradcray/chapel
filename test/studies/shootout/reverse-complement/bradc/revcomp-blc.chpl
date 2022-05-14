/* The Computer Language Benchmarks Game
   https://salsa.debian.org/benchmarksgame-team/benchmarksgame/

   contributed by Brad Chamberlain
   based on the Chapel #3 version with some inspiration taken from the
   C gcc #6 version by Jeremy Zerfas
*/

use IO;

param eol = '\n'.toByte(),  // end-of-line, as an integer
      cols = 61,            // # of characters per full row (including '\n')

      // A 'bytes' value that stores the complement of each base at its index
      cmpl = b"          \n                                                  "
           + b"    TVGH  CD  M KN   YSAABW R       TVGH  CD  M KN   YSAABW R";
             //    ↑↑↑↑  ↑↑  ↑ ↑↑   ↑↑↑↑↑↑ ↑       ↑↑↑↑  ↑↑  ↑ ↑↑   ↑↑↑↑↑↑ ↑
             //    ABCDEFGHIJKLMNOPQRSTUVWXYZ      abcdefghijklmnopqrstuvwxyz

// TODO: config param?
config const readSize = 65536,
             n = 0;

var pairCmpl: [0..<65536] uint(16);

var stdinBin  = openfd(0).reader(iokind.native, locking=false,
                                 hints=QIO_CH_ALWAYS_UNBUFFERED),
    stdoutBin = openfd(1).writer(iokind.native, locking=false,
                                 hints=QIO_CH_ALWAYS_UNBUFFERED);

// TODO: Shift by just 7?
inline proc join(i:uint(16), j) {
  return i << 8 | j;
}

proc main() {
  const offs = eol..<cmpl.size;
  forall i in offs {
    forall j in offs {
      pairCmpl[join(i,j)] = join(cmpl(j), cmpl(i));
    }
  }

  var seqCap = readSize,
      totRead, seqSize = 0,
      seqDom = {0..<seqCap},
      seq: [seqDom] uint(8);

  do {
    const chunkInds = seqSize..#readSize;
    ref nextChunk = seq[chunkInds];
    const more = stdinBin.read(nextChunk);
    var bytesRead = stdinBin.offset()-totRead;
    totRead += readSize;
//    writef("read %i bytes\n", bytesRead);
    do {
//      writeln("Looking for sep");
      const seqStart = findSep(seq[seqSize..#bytesRead]);
      if seqStart != 0 {
        const prevBytes = seqStart - seqSize;
        seqSize += prevBytes;

        if seqSize {   // TODO: Is this ever not true?
          revcomp(seq, seqSize);

//          writeln("Shifting from ", seqStart..#(bytesRead-prevBytes), " to ",
//                  0..<bytesRead-prevBytes);
          for j in 0..<bytesRead-prevBytes {
            seq[j] = seq[j+seqStart];
          }

          seqSize = 0;
        }

        seqSize += 1;  // TODO: Necessary?
        bytesRead -= prevBytes+1;
      }
    } while seqStart;

    seqSize += bytesRead;

    if seqSize > seqCap-readSize {
      seqCap *= 2;
      seqDom = {0..<seqCap};
    }
    } while (more);

  if seqSize {
    revcomp(seq, seqSize);
  }
}


proc revcomp(seq, size) {
  var i = 0;
  while seq[i] != eol {
    i += 1;
  }
  stdoutBin.write(seq[0..i]);
  stdoutBin.write(seq[i+1..<size]);
}


proc findSep(chunk: [?inds]) {
  for i in inds {
    if chunk[i] == '>'.toByte() && i != inds.low {
//      writeln("Found sep at ", i);
      return i;
    }
  }
  return 0;
}


proc revcomp(buf, lo, hi) {
  // shift all of the linefeeds into the right places
  const len = hi - lo + 1,
        off = (len - 1) % cols,
        shift = cols - off - 1;

  if off {
    forall m in lo+off..<hi by cols {
      for i in m..#shift by -1 do
        buf[i+1] = buf[i];
      buf[m] = eol;
    }
  }

  // walk from both ends of the sequence, complementing and swapping
  forall (i,j) in zip(lo..#(len/2), ..<hi by -1) do
    (buf[i], buf[j]) = (cmpl[buf[j]], cmpl[buf[i]]);
}
