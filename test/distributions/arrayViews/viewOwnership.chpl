use BlockDist;

config const n = 9;

const D = {1..n, 1..n} dmapped Block({1..n, 1..n});

var A: [D] real;

forall (i,j) in D do
  A[i,j] = i + j / 10.0;

writeln("Testing slice:");
foo(A[4..6, 4..6]);

writeln("Testing rank change:");
foo(A[3, 4..6]);
foo(A[4..6, 3]);

writeln("Testing reindex:");
foo(A.reindex({0..#n, 2..2*n by 2}));

proc foo(X: [?D]) {
  forall ind in D do
    X[ind] = here.id;
  writeln(X);
  writeln();
}
