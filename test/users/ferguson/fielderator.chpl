record R {
  /* 0 */ param param_value = 1;
  /* 1 */ type type_value = int;
  /* 2 */ var x: int;
  /* 3 */ var y: string;
  /* 4 */ var z: real;
  proc something() {
    return z;
  }
}

var m = new R(1, int, 3, "hi", 17.23);
const epsilon = 1e-8; // for comparing reals.

assert(__primitive("num fields", R) == 5);

assert(__primitive("field num to name", R, 2) == "x");
assert(__primitive("field num to name", R, 3) == "y");
assert(__primitive("field num to name", R, 4) == "z");

assert(isParam(__primitive("field by num", m, 0)));
assert(isType(__primitive("field by num", m, 1)));
assert(__primitive("field by num", m, 2) == 3);
assert(__primitive("field by num", m, 3) == "hi");
assert(realEqual(__primitive("field by num", m, 4), 17.23));

for param i in 0..<(__primitive("num fields", R)) {
  if isType(__primitive("field by num", m, i)) {
    writeln("type ", __primitive("field num to name", R, i));
  } else if isParam(__primitive("field by num", m, i)) {
    writeln("param ", __primitive("field num to name", R, i));
  } else {
    writeln(__primitive("field num to name", R, i));
    writeln(__primitive("field by num", m, i));
  }
}

proc realEqual(a: real, b: real): bool {
  var diff = abs(a - b);
  return diff < epsilon;
}
