use ParallelIO;

config const filename = "day01.in";

const numSettings = 100;

const strs = readLines(filename),
      steps = strToStep(strs),
      offs = 50 + (+ scan steps),
      settings = mod(offs, numSettings),
      zeroes = + reduce (settings == 0);

writeln(zeroes);

proc strToStep(str: string) {
  const val = str[1..]: int;
  return if str[0] == 'L' then -val else val;
}
