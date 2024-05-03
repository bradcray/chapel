writeln("Hello from locale ", here.id);
writeln();

var A: [1..2, 1..2] real = [(i,j) in {1..2, 1..2}] i + j/10.0;;

writeln("A is:\n", A);
writeln();

for loc in Locales {
  on loc {
    var B = A;
    writeln("[", here.id, "] B is:\n", B, "\n");
  }
}
