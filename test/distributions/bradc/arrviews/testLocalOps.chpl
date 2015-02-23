use BlockDist;

//
// The hope is that if we get privatization right, none of these
// we generate communication...
//

const D = {1..10, 1..10} dmapped Block({1..10, 1..10});

var A: [D] real;

proc foo(X) {
  resetCommDiagnostics();
  startCommDiagnostics();
  forall a in X {
    local {
      a += 1.0;
    }
  }
  stopCommDiagnostics();
  writeln("\nA is:\n", A);
  writeln(getCommDiagnostics());
}

proc bar(X: [2..11, 2..11] real) {
  resetCommDiagnostics();
  startCommDiagnostics();
  forall a in X {
    local {
      a += 1.0;
    }
  }
  stopCommDiagnostics();
  writeln("\nA is:\n", A);
  writeln(getCommDiagnostics());
}

proc baz(X: [2..11] real) {
  resetCommDiagnostics();
  startCommDiagnostics();
  forall a in X {
    local {
      a += 1.0;
    }
  }
  stopCommDiagnostics();
  writeln("\nA is:\n", A);
  writeln(getCommDiagnostics());
}

foo(A[2..9, 2..9]);
foo(A[9, 3..10]);
bar(A);
baz(A[9, ..]);
