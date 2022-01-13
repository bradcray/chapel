proc main() {
  var n = 6;
  var A, B: [1..n] real;

  A = 1..n;
  writeln(A);
  
  forall i in 2..n-1 do
    B[i] = (A[i-1] + A[i+1])/2;

  writeln(B);
}
