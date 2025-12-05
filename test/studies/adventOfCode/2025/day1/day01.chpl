use IO;

enum dir {L=-1, R=1};

const numSettings = 100;

var setting = 50,
    count = 0;

var str: string;
while readln(str) {
  // get step size
  const step = str[1..]: int;

  setting += str[0]:dir:int * step;

  // Though it's tempting to use 'setting %= numSettings;' here, that
  // doesn't treat negative numbers in a mathematically correct
  // manner, so I'm using 'mod()' instead
  //
  setting = mod(setting, numSettings);

  if setting == 0 then
    count += 1;
}

writeln(count);
