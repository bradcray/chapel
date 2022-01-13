use IO, List;

// For more detailed instructions and color commentary, refer to:
//   https://adventofcode.com/2021/day/4

// Run by piping in an input file like './day4 < day4.test' or './day4
// < day4.stdin'.  For day4.test, the third board wins (#2 using
// 0-based indexing), the last number called was 24, and its score
// should be 4512.  What's the score for day4.test?

config const debug = false;  // enable debugging by running as './day4 --debug'

config param boardSize = 5;

const dim = 1..boardSize,
      BoardInds = {dim, dim};

var numbers = readInts(); // numbers will be an array of the integers called

if debug then
  writeln(numbers);

var Boards = readBoards(); // boards is a 1D array of 2D arrays (the boards)

if debug then
  for b in Boards do
    writeln(b, "\n");

// TODO: Simulate the bingo game, determining which board wins first,
// and then computing its score which is the sum of all unmarked
// numbers on the board multiplied by the number that was just called.

// What opportunities are there for parallelism in this one?


/* Helper routines */

//
// readInts() will read and yield a line of comma-separated integers
// from 'stdin' until there are no more
//
iter readInts() {
  while true {
    const num = read(int);
    yield num;
    try {
      readf(",");
    } catch {
      return;
    }
  }
}

//
// readBoards() will read and yield a series of 5x5 bingo cards (with
// no free space?!?) from 'stdin' until there are no more
//
iter readBoards() {
  var Board: [1..5, 1..5] int;
  do {
    const success = read(Board);
    if (success) then
      yield Board;
  } while success;
}
