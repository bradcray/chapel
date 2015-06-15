enum color { red, white, blue };

var c: color;

c = color.red;

proc foo(x: uint(32), y: uint(32)) {
  writeln("In 32-bit foo!");
  return false;
}

proc foo(x: uint(64), y: uint(64)) {
  writeln("In 64-bit foo!");
  return true;
}

if (foo(c, color.white)) {
  writeln("We got the right one!");
}

