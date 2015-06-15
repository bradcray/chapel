enum color { red, white, blue };

record R {
  var c: color;
}

var c: [0..1] R;

c[0].c = color.red;
c[1].c = color.blue;

proc foo(x: uint(32), y: uint(32)) {
  writeln("In 32-bit foo!");
  return false;
}

proc foo(x: uint(64), y: uint(64)) {
  writeln("In 64-bit foo!");
  return true;
}

if (foo(c[0].c, color.white)) {
  writeln("Got correct version!");
}
