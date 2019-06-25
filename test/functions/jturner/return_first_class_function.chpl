use Functions;

proc make_fun() : func(func(int)) {
  return (lambda() { return (lambda() { return 3; }):func(int); }): func(func(int));
}

var g = make_fun();
var h = g();
writeln(h());
