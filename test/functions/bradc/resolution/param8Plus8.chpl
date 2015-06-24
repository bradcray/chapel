param a = 127;
param b = 127;

proc plus(x: int(8), y: int(8)) {
  writeln("in 8-bit version");
  return x + y;
}

proc plus(x: int(32), y: int(32)) {
  writeln("In 32-bit version");
  return x + y;
}

writeln(plus(a,b));
