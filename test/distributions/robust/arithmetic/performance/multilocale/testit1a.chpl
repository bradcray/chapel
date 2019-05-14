config const n = 10;

{
  use CyclicDist;


  var D = newCyclicDom({1..n});
  var A: [D] real;

  forall a in A do
    a = here.id + 1;

  writeln(A);
}

{
  use CyclicDist;


  var D = newCyclicDom({1..2*n by 2});
  var A: [D] real;

  forall a in A do
    a = here.id + 1;

  writeln(A);
}
  