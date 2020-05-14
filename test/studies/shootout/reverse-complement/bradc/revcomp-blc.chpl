/* The Computer Language Benchmarks Game
   https://salsa.debian.org/benchmarksgame-team/benchmarksgame/

   contributed by Brad Chamberlain
   based on the C gcc #5 version by Mr Ledrug
*/

param eol = "\n".toByte();      // end-of-line, as an integer

const table = createTable();    // create the table of code complements

proc main(args: [] string) {
  use IO;
  const stdinBin = openfd(0).reader(iokind.native, locking=false,
                                 hints = QIO_CH_ALWAYS_UNBUFFERED),
        stdoutBin = openfd(1).writer(iokind.native, locking=false,
                                  hints=QIO_CH_ALWAYS_UNBUFFERED);;

  // read in the data using an incrementally growing buffer
  var bufLen = 8 * 1024,
      bufDom = {0..<bufLen},
      buf: [bufDom] uint(8),
      end = 0;

  do {
    const more = stdinBin.read(buf[end..]);
    if more {

      end = bufLen;
      bufLen += min(1024**2, bufLen);
      bufDom = {0..<bufLen};
    }
  } while more;
  end = stdinBin.offset()-1;

  // search for the '>' that marks the start of a sequence
  var hi = end;

  while (hi >= 0) {
    var lo = hi;
    while buf[lo] != '>'.toByte() do
      lo -= 1;

    // process the sequence once we find it
    process(buf, lo, hi);

    hi = lo - 1;
  }

  // write out the transformed buffer
  stdoutBin.write(buf[..end]);
}


proc process(buf, in lo, hi) {
  param cols = 61;  // the number of characters per row (including '\n')
  
  // skip past header line
  while (buf[lo] != eol) {
    lo += 1;
  }
  lo += 1;

  // shift all of the linefeeds into the right places
  const len = hi - lo + 1,
        off = (len-1)%cols,
        shift = cols - off - 1;

  if off {
    for m in lo+off..<hi by cols {
      for i in m..#shift by -1 do
        buf[i+1] = buf[i];
      buf[m] = eol;
    }
  }

  // march from both ends of the sequence, complementing and swapping
  for (i,j) in zip(lo..#(len/2), ..<hi by -1) do
    (buf[i], buf[j]) = (table[buf[j]], table[buf[i]]);
}


proc createTable() {
  // `pairs` compactly represents the table we're creating, where the
  // first byte of each pair (in either case) maps to the second:
  //   A|a -> T, C|c -> G, G|g -> C, T|t -> A, etc.
  param pairs = b"ATCGGCTAUAMKRYWWSSYRKMVBHDDHBVNN",
        upperToLower = "a".toByte() - "A".toByte();

  var table: [0..127] uint(8);

  for i in pairs.indices by 2 {
    const src = pairs[i],
          dst = pairs[i+1];

    table[src] = dst;
    table[src+upperToLower] = dst;
  }
  table[eol] = eol;

  return table;
}
