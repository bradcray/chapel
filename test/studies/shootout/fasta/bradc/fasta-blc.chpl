/* The Computer Language Benchmarks Game
   http://benchmarksgame.alioth.debian.org/

   contributed by Brad Chamberlain

   derived from the GNU C version by Аноним Легионов and Jeremy Zerfas
     as well as from previous Chapel versions by Casey Battaglino,
     Kyle Brady, and Preston Sahabu.
*/

config const n = 1000,           // the length of the generated strings
             lineLength = 60,    // the number of columns in the output
             blockSize = 1024;   // the parallelization granularity

config param frames = 3;         // number of pipeline frames to store


//
// Nucleotide definitions
//
enum nucleotide {
  A = ascii("A"), C = ascii("C"), G = ascii("G"), T = ascii("T"),
  a = ascii("a"), c = ascii("c"), g = ascii("g"), t = ascii("t"),
  B = ascii("B"), D = ascii("D"), H = ascii("H"), K = ascii("K"),
  M = ascii("M"), N = ascii("N"), R = ascii("R"), S = ascii("S"),
  V = ascii("V"), W = ascii("W"), Y = ascii("Y")
}
use nucleotide;

//
// Sequence to be repeated
//
const ALU: [0..286] int(8) = [
  G, G, C, C, G, G, G, C, G, C, G, G, T, G, G, C, T, C, A, C,
  G, C, C, T, G, T, A, A, T, C, C, C, A, G, C, A, C, T, T, T,
  G, G, G, A, G, G, C, C, G, A, G, G, C, G, G, G, C, G, G, A,
  T, C, A, C, C, T, G, A, G, G, T, C, A, G, G, A, G, T, T, C,
  G, A, G, A, C, C, A, G, C, C, T, G, G, C, C, A, A, C, A, T,
  G, G, T, G, A, A, A, C, C, C, C, G, T, C, T, C, T, A, C, T,
  A, A, A, A, A, T, A, C, A, A, A, A, A, T, T, A, G, C, C, G,
  G, G, C, G, T, G, G, T, G, G, C, G, C, G, C, G, C, C, T, G,
  T, A, A, T, C, C, C, A, G, C, T, A, C, T, C, G, G, G, A, G,
  G, C, T, G, A, G, G, C, A, G, G, A, G, A, A, T, C, G, C, T,
  T, G, A, A, C, C, C, G, G, G, A, G, G, C, G, G, A, G, G, T,
  T, G, C, A, G, T, G, A, G, C, C, G, A, G, A, T, C, G, C, G,
  C, C, A, C, T, G, C, A, C, T, C, C, A, G, C, C, T, G, G, G,
  C, G, A, C, A, G, A, G, C, G, A, G, A, C, T, C, C, G, T, C,
  T, C, A, A, A, A, A
];

//
// Index aliases for use with (nucleotide, probability) tuples
//
param nucl = 1,
      prob = 2;

param IM = 139968;

//
// Probability tables for sequences to be randomly generated
//
const IUB = [(a, 0.27), (c, 0.12), (g, 0.12),
                                     (t, 0.27), (B, 0.02), (D, 0.02),
                                     (H, 0.02), (K, 0.02), (M, 0.02),
                                     (N, 0.02), (R, 0.02), (S, 0.02),
                                     (V, 0.02), (W, 0.02), (Y, 0.02)];

const HomoSapiens = [(a, 0.3029549426680),
                                            (c, 0.1979883004921),
                                            (g, 0.1975473066391),
                                            (t, 0.3015094502008)];


proc main() {
  repeatMake(">ONE Homo sapiens alu\n", ALU, 2*n);
  randomMake(">TWO IUB ambiguity codes\n", IUB, 3*n);
  randomMake(">THREE Homo sapiens frequency\n", HomoSapiens, 5*n);
}

//
// Redefine stdout to use lock-free binary I/O and capture a newline
//
const stdout = openfd(1).writer(kind=iokind.native, locking=false);
param newline = ascii("\n"): int(8);

//
// Repeat string 'str' for 'n' characters
//
proc repeatMake(desc, str, n) {
  stdout.write(desc);

  const r = str.size,
        s = [i in 0..(r+lineLength)] str[i % r];

  for i in 0..n by lineLength {
    const lo = i % r + 1,
          len = min(lineLength, n-i);
    stdout.write(s[lo..#len], newline);
  }
}

//
// Output a random sequence of length 'n' using distribution 'a'
//
proc randomMake(desc, nuclInfo, n) {
  const numNucls = nuclInfo.size;

  stdout.write(desc);

  var cumul_p: [1..numNucls] int;
  //
  // Sum the probabilities of the nucleotide info
  //
  var p = 0.0;
  for i in 1..numNucls {
    p += nuclInfo[i](prob);
    cumul_p[i] = 1 + (p*IM):int;
  }

  /*
  for i in 0..#numTasks {
    randGo[i].write(1);
    outGo[i].write(1);
  }
*/

  const chunkSize = lineLength*blockSize;

  var line_buff: [0..#frames] [0..(lineLength+1)*blockSize-1] int(8);
  var rands: [0..#frames] [0..chunkSize] int/*(32)*/;
  var randGo, computeGo, writeGo: [0..#frames] atomic int;

  randGo.write(1);

  if (here.maxTaskPar < 3) then
    writef("Warning: This code uses busy waiting and 3 tasks, so may deadlock",
           " since here.maxTaskPar = %i", here.maxTaskPar);

  cobegin {
    computeRands();
    computeLines();
    writeLines();
  }

  proc computeRands() {
    var frame = 0;
    for i in 1..n by chunkSize {
      //      stderr.writef("computeRands waiting on frame %i\n", frame);
      while (randGo[frame].read() != 1) do ;
      //      stderr.writef("computeRands resetting frame %i\n", frame);
      randGo[frame].write(0);

      const bytes = min(chunkSize, n-i+1);
      getRands(bytes, rands[frame]);

      //      stderr.writef("computeRands writing %i to computeGo[%i]\n", bytes, frame);
      computeGo[frame].write(bytes);

      frame += 1;
      frame %= frames;
    }
    //    stderr.writef("computeRands writing -1 to computeGo[%i]\n", frame);
    computeGo[frame].write(-1);
  }

  proc computeLines() {
    var frame = 0;
    while true {
      //      stderr.writef("computeLines waiting on frame %i\n", frame);
      var bytes = 0;
      while bytes == 0 do
        bytes = computeGo[frame].read();
      //      stderr.writef("computeLines read %i\n", bytes);
      if bytes == -1 then break;
      //      stderr.writef("computeLines resetting frame %i\n", frame);
      computeGo[frame].write(0);
      
      var col = 0;
      var off = 0;
      ref myRands = rands[frame],
          myBuff = line_buff[frame];
      for i in 0..#bytes {
        const r = myRands[i];
        var ncnt = 1;
        for j in 1..numNucls do
          if r >= cumul_p[j] then
            ncnt += 1;

        myBuff[off] = nuclInfo[ncnt](nucl);

        off += 1;
        col += 1;
        if (col == lineLength) {
          col = 0;
          myBuff[off] = newline;
          off += 1;
        }
      }
      if (col != 0) {
        myBuff[off] = newline;
        off += 1;
      }

      //      stderr.writef("computeLines setting writeGo[%i] to 1\n", frame);
      writeGo[frame].write(off);

      frame += 1;
      frame %= frames;
    }
    //    stderr.writef("computeLines setting writeGo[%i] to -1\n", frame);
    writeGo[frame].write(-1);
  }

  proc writeLines() {
    var frame = 0;
    while true {
      var off = 0;
      //      stderr.writef("writeLines waiting on frame %i\n", frame);
      while off == 0 do
        off = writeGo[frame].read();
      if off == -1 then break;
      //      stderr.writef("writeLines resetting writeGo[%i]\n", frame);
      writeGo[frame].write(0);

      stdout.write(line_buff[frame][0..#off]);

      //      stderr.writef("writeLines setting randGo[%i] to 1\n", frame);
      frame = (frame+1)%frames;
      randGo[frame].write(1);
    }
  }
}


//
// Deterministic random number generator
//
var lastRand = 42/*:int(32)*/;

proc getRands(n, arr) {
  param IA = 3877,
        IC = 29573;

  //  writef("tid %i got turn\n", tid);
  for i in 0..#n {
    lastRand = (lastRand * IA + IC) % IM;
    arr[i] = lastRand;
  }
}
