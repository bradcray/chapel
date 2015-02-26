use BlockDist;

//
// The hope is that if we get privatization right, none of these
// we generate communication...
//

const D = {1..10, 1..10} dmapped Block({1..10, 1..10});

var A: [D] int;

proc foo(X) {
  var B: [X.domain] int;
  forall b in B {
    b = here.locale.id;
  }
  for ij in X.domain {
    if (X[ij] != B[ij]) {
      writeln("foo() not aligned:\n", X, "\n", B, "\n");
      return;
    }
  }
  writeln("Success!");
}

proc bar(X: [2..11, 2..11] int) {
  X.domain.displayRepresentation();
  compilerWarning(typeToString(X._value.type));
  forall ij in X.domain {
    writeln(ij, " lives on locale ", here.locale.id);
  }
  writeln("About to build array");
  var B: [X.domain] int;
  writeln("Done building array");
  /*
  writeln("B is: ", B);
  B[2,2] = 1;
  writeln("B is: ", B);
  on Locales[0] do
    B[2,2] = 2;
  writeln("B is: ", B);
  on Locales[(here.id+1)%numLocales] do
    B[2,2] = 3;
  writeln("B is: ", B);
  */
  forall b in B {
    b = here.locale.id;
  }
  /*
  writeln("Past loop");
  writeln("B is: ", B);
  */
  for ij in X.domain {
    if (X[ij] != B[ij]) {
      writeln("bar() not aligned:\n", X, "\n", B, "\n");
      return;
    }
  }
  writeln("Success!");
}

/*
proc baz(X: [2..11] int) {
  var B: [X.domain] int;
  forall b in B {
    b = here.locale.id;
  }
  for ij in X.domain {
    if (X[ij] != B[ij]) {
      writeln("baz() not aligned:\n", X, "\n", B, "\n");
      return;
    }
  }
  writeln("Success!");
}
*/

forall a in A do
  a = here.locale.id;


foo(A[2..9, 2..9]);
//foo(A[9, 3..10]);
bar(A);
//baz(A[9, ..]);
