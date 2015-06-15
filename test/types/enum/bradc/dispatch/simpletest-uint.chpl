/* Convert a Roman number to an Arabic number using string->enum conversions */

enum numeral {I=1, V=5, X=10, L=50, C=100, D=500, M=1000};

var enumEq1000: numeral = numeral.M;

uint8works(enumEq1000);

proc uint8works(x: uint(8)) {
  writeln("We incorrectly got to the int(8) version");
}
