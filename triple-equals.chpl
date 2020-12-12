class C {
  var x: int;
}

proc ==(x: C, y: C) {
  return x.x == y.x;
}

var a = new C(10);
var b = new C(10);

writeln(a == b);
writeln(a === b);
