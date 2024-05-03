writeln("Hello from locale ", here.id);
writeln();

var A: [1..2, 1..2] real = [(i,j) in {1..2, 1..2}] i + j/10.0;;

writeln("A is:\n", A);
writeln();

on Locales[1] {
  var B: [1..2, 1..2] real;

  B = 2 * A;
  writeln("B is:\n", B);
}
