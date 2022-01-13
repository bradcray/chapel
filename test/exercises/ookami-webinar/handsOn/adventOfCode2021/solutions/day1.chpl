use IO;

// For more detailed instructions and color commentary, refer to:
//   https://adventofcode.com/2021/day/1

// Run by either entering integers interactively, or by piping in an
// input file like './day1 < day1.test' or './day1 < day1.in'

config const debug = false;  // enable debugging by running as './day1 --debug'

var Values = readInts();   // store integers in (0-indexed) array 'Values'

if debug then writeln(Values);

// TODO (step 1): Compute how many values are greater than their
// predecessor

// Here, I'm iterating over all the indices in Values.domain but the
// first.  I used a fairly esoteric way of saying "all indices in
// 'Values' other than the first.  Other ways would be:
// * to embed that the low bound is 0 and write '1..<Values.size'
// * to explicitly loop from Values.domain.low+1..Valuse.domain.high
// * probably lots of other things as well...

const sum = + reduce [i in Values.domain#-(Values.size-1)]
                       (Values[i] > Values[i-1]);

writeln("Number of increasing entries = ", sum);

// TODO (step 2): Compute how many sums of three values are greater
// than the sum of their three immediate predecessors


// I continued my somewhat esoteric approach from above, for better or
// worse (probably worse) and introduced a temporary array containing
// the sums.  But with a bit more work and cleverness, you can
// probably figure out how to do it without the temporary array...

const sumsOf3 = [i in Values.domain#-(Values.size-2)] + reduce Values[i-2..i];

const tot = + reduce [i in sumsOf3.domain#-(sumsOf3.size-1)]
                       (sumsOf3[i] > sumsOf3[i-1]);

writeln("Number of increasing sums of three = ", tot);


/* Helper routines */

//
// readInts() will read and yield integers from 'stdin' until there are no more
//
iter readInts() {
  var i: int;
  while read(i) {
    yield i;
  }
}
