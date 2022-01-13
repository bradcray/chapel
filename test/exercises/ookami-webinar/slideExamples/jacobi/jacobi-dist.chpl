use BlockDist;

config const n = 6, epsilon = 0.01;

const AllInds = {0..n+1, 0..n+1} dmapped Block({1..n, 1..n}),
            D = AllInds[1..n, 1..n],
      LastRow = AllInds[n+1..n+1, ..];

var A, Temp : [AllInds] real;



A[LastRow] = 1.0;

do {
  forall (i,j) in D do
    Temp(i,j) = (A[i-1,j] + A[i+1,j] + A[i,j-1] + A[i,j+1]) / 4;

  const delta = max reduce abs(A[D] - Temp[D]);
  A[D] = Temp[D];
} while delta > epsilon;

writeln(A);
