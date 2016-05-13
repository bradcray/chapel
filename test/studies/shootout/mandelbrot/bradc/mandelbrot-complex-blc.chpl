/* The Computer Language Benchmarks Game
   http://benchmarksgame.alioth.debian.org/

   contributed by Jacob Nelson
   modified by Lydia Duncan, Brad Chamberlain, and Ben Harshbarger
*/

use DynamicIters;

config const n = 200,              // the problem size
             maxIter = 50,         // the maximum # of iterations
             limit = 4.0,          // the limit before quitting
             chunkSize = 1;        // the chunk size of the dynamic iterator

param bitsPerElt = 8;              // the # of bits to store per element
type eltType = uint(bitsPerElt);   // the element type to store


proc main() {
  const ydim = 0..#n,                          // the y dimension
        xdim = 0..#divceilpos(n, bitsPerElt),  // the compacted x dimension
        bitRange = 0..#bitsPerElt,             // the degree of compactness
        iters = 1..maxIter;                    // the max # of iterations

  var image : [ydim, xdim] eltType;            // the bitmap image

  forall y in dynamic(ydim, chunkSize) {       // forall rows...
    for xelt in xdim {                         //   forall column elements

      var mask = 0: eltType;                   // zero out the mask

      for off in bitRange {                    // for each bit in the element
        const x = xelt*bitsPerElt + off;       // compute its logical location

        //        const C = 2.0*(x + y*1.0i)/n - (1.5 + 1.0i);
        //        const C = (2.0*x/n - 1.5,2.0*y/n - 1.0): complex;
        var C: complex;
        C.re = 2.0*x/n - 1.5;
        C.im = 2.0*y/n - 1.0;
        var Z, T: complex;

        for i in iters {                       // for the max # of iterations
          if (T.re + T.im > limit) {          // if we haven't converged
            break;
          }

          // Z = Z*Z + C;
          Z.im = 2.0*Z.re*Z.im + C.im;
          Z.re = T.re - T.im + C.re;
          T.re = Z.re**2;
          T.im = Z.im**2;
        }

        mask <<= 1;                            // shift the mask
        if (T.re + T.im <= limit) {                // if below the limit,
          mask |= 0x1;                         // set the low bit to 1
        }
      }

      image[y, xelt] = mask;                   // store the computed element
    }
  }

  var f = openfd(1);                           // open a stdout file descriptor
  var w = f.writer(iokind.native, locking=false);  // get a lock-free writer

  w.writef("P4\n");                            // write the file header
  w.writef("%i %i\n", n, n);

  w.write(image);                              // write out the image
}
