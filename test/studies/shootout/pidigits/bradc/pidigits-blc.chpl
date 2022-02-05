/* The Computer Language Benchmarks Game
 * https://benchmarksgame-team.pages.debian.net/benchmarksgame/index.html
 *
 * Contributed by Brad Chamberlain, Jatin Garg, and Elliot Ronaghan
 * Derived from James Wright's C and Lew Palm's C++ multi-threaded versions
 */

use BigInteger;

config var n = 27;

var q, r, t: bigint;
var tCalculating, qCalculating, extractCalculating: atomic bool;
var k, doubleK, digit: int;


proc main() {
  q = 1;
  t = 1;

  var temp1, temp2: bigint;
  var tPrecalculation = false;
  var nDigits = 0;
  var tMultDone, qMultDone, extractDone: sync bool;
  var qMult10Done: sync bool = true;

  while nDigits < n {
    var i = 0;
    while i < 10 && nDigits < n {
      if !tPrecalculation {
        k += 1;
        doubleK = 2*k + 1;
        begin with (ref t) { t *= doubleK; tMultDone.writeEF(true); }
      } else {
        tPrecalculation = false;
      }
      qMult10Done.readFE();  // Wait for 'q *= 10' to finish (if it ran)
      temp1.add(q,q);

      begin with (ref q) { q *= k; qMultDone.writeEF(true); }

      temp1 += r;
      r.mul(temp1,doubleK);

      qMultDone.readFE();  // Wait for 'q *= qMultiplicand' to finish
      tMultDone.readFE();  // Wait for 't *= doubleK' to finish (if it ran)

      var multiplyingQ = false;
      if q <= r {
        begin { extract(); extractDone.writeEF(true); }

        temp1.mul(q,4);
        temp1 += r;

        temp2.divQ(temp1, t);
        const digit2 = temp2: int;

        extractDone.readFE();  // Wait for extraction task

        if digit == digit2 {
          begin with (ref q) { q *= 10; qMult10Done.writeEF(true); }
          multiplyingQ = true;

          write(digit);
          temp1.mul(t, digit);

          k += 1;
          doubleK = 2*k + 1;

          begin with (ref t) { t *= doubleK;  tMultDone.writeEF(true); }
          tPrecalculation = true;

          temp1.sub(r, temp1);
          r.mul(temp1, 10);

          i += 1;
          nDigits += 1;
        }
      }
      if !multiplyingQ {
        qMult10Done.writeEF(true);   // pretend we did
      }
    }
    if i != 10 then
      write(" "*(10-i));
    writeln("\t:", nDigits);
  }
  exit(0);
}


// extract a digit when 'extractCalculating' is set to 'true'
var tmp1, tmp2: bigint;
proc extract() {
  tmp1.mul(q, 3);
  tmp1 += r;
  tmp2.divQ(tmp1, t);
  digit = tmp2: int;
}
