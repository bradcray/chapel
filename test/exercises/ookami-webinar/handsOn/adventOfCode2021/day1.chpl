use IO;

// For more detailed instructions and color commentary, refer to:
//   https://adventofcode.com/2021/day/1

// Run by either entering integers interactively, or by piping in an
// input file like './day1 < day1.test' or './day1 < day1.stdin'.
// Using day1.test, the answers should be 7 and 5, respectively.
// What are the answers for day1.stdin?

config const debug = false;  // enable debugging by running as './day1 --debug'

var Values = readInts();   // store integers in (0-indexed) array 'Values'

if debug then writeln(Values);

// TODO (step 1): Compute how many values are greater than their
// predecessor.  Maybe try it serially first, then in parallel?

// Possibly Helpful Tips (you won't need all of these)
// ---------------------------------------------------
// * myArray.domain: returns the domain (index set) of 'myArray'
// * myArray.size:   returns the size of 'myArray'
// * myArray.low:    returns the low bound of 'myArray'
// * myArray.high:   returns the high bound of 'myArray'
// * myArray[l..h]:  refers to a sub-array of 'myArray'
// * + reduce expr:  returns the sum of all values in 'expr'
// * [i in expr]:    iterates over an 'expr', binding values to 'i'
// * myDomain#n:     returns a domain with the first n indices if n > 0
//                   and the final n indices if n < 0
// * myArray#n:      similar, but for the array's elements
//   -> shorthand for 'forall i in expr' if 'expr' supports parallel iteration
//                 or 'for i in expr' if it does not

// TODO (step 2): Compute how many sums of three values are greater
// than the sum of their three immediate predecessors.  Again, can you
// do it in parallel?



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
