config const n = 10;

config const checkOutOfBounds = false;

var D = {1..n};
var D2 = {2..n-1};

var A: [D] real = [i in D] i;

for a in A[D2] do
  writeln(a);
writeln();

foo(A[D2]);
writeln("A is: ", A);
foo(A[2..n-1]);
writeln("A is: ", A);

bar(A);

proc foo(Arr) {
  for a in Arr do
    writeln(a);
  writeln();
  writeln(Arr[2]);
  if checkOutOfBounds then
    writeln(Arr[1]);
  writeln();

  for i in Arr.domain do
    writeln(i);
  writeln();

  forall a in A[D2] do
    a += 1;
}

proc bar(Arr: [4..n+3]) {
  for i in Arr.domain do
    writeln(i);
  for a in Arr do
    writeln(a);
}
