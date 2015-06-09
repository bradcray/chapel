class C {
  var x: int;
}
/*
proc foo(myC: C, myC2: C) {
  writeln("In myC foo()");
}

proc foo(b: bool, b2: bool) {
  writeln("in bool foo()");
}

proc foo(param b: bool, param b2: bool) {
  writeln("in param bool foo()");
}

proc foo(b: int, b2: int) {
  writeln("in int foo()");
}

proc foo(param b: int, param b2: int) {
  writeln("in param int foo()");
}
foo(0,0);
*/

proc foobar(x: C, y: C) {
  writeln("In myC foobar()");
  return true;
}

var myC = new C(),
  myC2 = new C();


writeln("myC = ", myC);
writeln("myC2 = ", myC2);
writeln(foobar(true, false));
writeln(foobar(0,1));
writeln(foobar(myC, myC2));
