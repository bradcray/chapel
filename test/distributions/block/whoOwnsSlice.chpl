use BlockDist, CommDiagnostics;

config const n = 11;

const D = {1..n, 1..n} dmapped Block({1..n, 1..n});
var A: [D] real;

printOwnership("D:", D);
// printOwnership(str, A);

const Row4 = D[4..4, ..];

printOwnership("Row 4 (2D):", Row4);


const Col11 = D[.., 11..11];

printOwnership("Col 11 (2D):", Col11);

const Row8 = D[8, ..];

printOwnership("Row 8:", Row8);

const Col2 = D[.., 2];

printOwnership("Col 2:", Col2);

const Mid = D[4..8, 4..8];

printOwnership("Mid:", Mid);


proc printOwnership(str, D) {
  writeln(str);
  var first = true;
  for loc in D.owningLocales() {
    if first then
      first = false;
    else
      write(", ");
    write(loc.id);
  }
  writeln();
}
