

config const n = 6, epsilon = 0.01;

const AllInds = {0..n+1, 0..n+1},
            D = AllInds[1..n, 1..n],
      LastRow = AllInds[n+1..n+1, ..];

var A, Temp : [AllInds] real;

const north = (-1,0), south = (1,0), east = (0,1), west = (0,-1);

A[LastRow] = 1.0;

do {
  Temp[D] = (A[D.translate(north)] + A[D.translate(south)] + 
             A[D.translate(east)]  + A[D.translate(west)]) / 4;

  const delta = max reduce abs(A[D] - Temp[D]);
  A[D] = Temp[D];
} while delta > epsilon;

writeln(A);
