use IO, List;

// For more detailed instructions and color commentary, refer to:
//   https://adventofcode.com/2021/day/4

// Run by piping in an input file like './day4 < day4.test' or
// './day4 < day4.in'

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


//
// I stored a separate array of boolean boards to keep track of which
// numbers were called or not; another, more clever/compact way of
// doing it, might've been to negate the integers in the original
// bingo cards once they're called?
//
var Marked: [Boards.domain] [BoardInds] bool;

//
// playBingo() is my main routine which will return a tuple of the
// winning card (as an index into 'Boards') and the last number
// called.  Once I find a winner, I print some stuff and calculate
// its score using calculateScore().
//
const (winner, lastnumber) = playBingo();
writeln("The winning board is ", winner);
const score = calculateScore(Boards[winner], Marked[winner], lastnumber);
writeln("Its score was: ", score);

//
// playBingo() loops over the numbers serially so that we can check
// for a winner each time, but for a given number, searches all boards
// and all positions within a board in parallel.  When it finds one,
// it marks the corresponding entry in my 'Marked' arrays.
//
proc playBingo() {
  for number in numbers {
    forall (myBoard, myMarks) in zip(Boards, Marked) do
      forall rc in BoardInds do
        if myBoard[rc] == number then
          myMarks[rc] = true;

    // check to see if we're done
    const winner = lookForWinner();
    if winner != -1 then
      return (winner, number);
  }
  halt("We didn't find a winner before running out of numbers");
}

//
// lookForWinner() looks for a winner by iterating over the marked
// cards, then the rows and columns of each card, doing a + reduce of
// the booleans (which will coerce to 0 or 1), to see whether any row
// or column is full.  If it is, return it.  I didn't parallelize this
// because Chapel doesn't currently support returning within a
// 'forall' loop.  Another approach would be to search in parallel
// over the cards, marking the winning card in a shared variable, and
// skipping the row/column loops if a winning card has already been
// found (a form of a benign race).
//
proc lookForWinner() {
  for i in Marked.domain {
    ref b = Marked[i];

    for r in dim do
      if + reduce b[r, ..] == boardSize then
        return i;

    for c in dim do
      if + reduce b[.., c] == boardSize then
        return i;
  }

  return -1;
}

//
// Calculate the score as we were told too — I used a reduction to get
// a bit of parallelism over the board (only really interesting for
// larger boards than 5x5 presumably...)
//
proc calculateScore(board, called, lastnumber) {
  var sum = + reduce [rc in BoardInds] if called[rc] then 0 else board[rc];
  writeln("sum of winning board is: ", sum);
  return sum*lastnumber;
}

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
  var Board: [BoardInds] int;
  do {
    const success = read(Board);
    if (success) then
      yield Board;
  } while success;
}
