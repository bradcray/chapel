use ParallelIO;

config const filename = "day01.in";

enum dir {L=-1, R=1};

const numSettings = 100;

const strs = readLines(filename),
      steps = strToStep(strs),
      offs = 50 + (+ scan steps),
      settings = mod(offs, numSettings),
      zeroes = + reduce (settings == 0);

writeln(zeroes);

proc strToStep(str: string) {
  return str[0]:dir:int * str[1..]:int;
}
