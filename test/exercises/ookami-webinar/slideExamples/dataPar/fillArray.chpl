 

config const n = 5;

const D = {1..n, 1..n};
var A: [D] real;

forall (i,j) in D do
  A[i,j] = i + (j - 0.5)/n;

writeln(A);
