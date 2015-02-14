config const n = 10;

var D = {1..n};
var D2 = {2..n-1};

var A: [D] real = [i in D] i;

for a in A[D2] do
  writeln(a);
