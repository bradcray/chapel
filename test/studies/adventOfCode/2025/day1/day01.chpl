use IO;

const numSettings = 100;

var setting = 50,
    count = 0;

var str: string;
while readln(str) {
  // get step size
  const step = str[1..]: int;

  // see if we're turning right or left
  if str[0] == 'R' {
    setting += step;
  } else {
    setting -= step;
  }

  // Though it's tempting to use 'setting %= numSettings;' here, that
  // doesn't treat negative numbers in a mathematically correct
  // manner, so I'm using 'mod()' instead
  //
  setting = mod(setting, numSettings);

  if setting == 0 then
    count += 1;
}

writeln(count);
