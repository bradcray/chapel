use BlockDist;

config const n = 6, epsilon = 0.01;

const AllInds = {0..n+1, 0..n+1} dmapped Block({1..n, 1..n}),
            D = AllInds[1..n, 1..n],
      LastRow = AllInds[n+1..n+1, ..];

var A, Temp : [AllInds] real;

const north = (-1,0), south = (1,0), east = (0,1), west = (0,-1);

A[LastRow] = 1.0;

do {
  forall ij in D do
    Temp[ij] = (A[ij+north] + A[ij+south] + A[ij+east] + A[ij+west]) / 4;

  const delta = max reduce abs(A[D] - Temp[D]);
  A[D] = Temp[D];
} while delta > epsilon;

writeln(A);
