{
  var A = [-3, -2, -1, 0, 1, 2, 3];

  ref B = A.reindex({-3..3});
  writeln(B.domain);
  [i in -3..3] B[i] = -B[i];
  writeln(B);
  writeln(A);

  ref C = A.reindex(-3..3);
  writeln(C.domain);
  [i in -3..3] C[i] = -C[i];
  writeln(C);
  writeln(A);
}

{
  var A = [11, 12, 13; 21, 22, 23; 31, 32, 33];

  ref B = A.reindex({-1..1, -1..1});
  writeln(B.domain);
  [i in {-1..1, -1..1}] B[i] = -B[i];
  writeln(B);
  writeln(A);

  ref C = A.reindex(-1..1, -1..1);
  writeln(C.domain);
  [i in {-1..1, -1..1}] C[i] = -C[i];
  writeln(C);
  writeln(A);
}
