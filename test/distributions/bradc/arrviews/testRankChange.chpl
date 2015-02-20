config const n = 4;

const D = {1..n, 1..n};

var A: [D] real;

forall (i,j) in D {
  A[i,j] = i + j/10.0;
}

proc foo(X) {
  for a in X do
    write(a, " ");
  writeln();
}

writeln(A);
writeln();
foo(A[2, ..]);
foo(A[.., 3]);
