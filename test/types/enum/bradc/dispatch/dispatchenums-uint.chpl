/* Convert a Roman number to an Arabic number using string->enum conversions */

enum numeral {I=1, V=5, X=10, L=50, C=100, D=500, M=1000};

var enumEq1000: numeral = numeral.M;
var enumEqFive = 5:numeral;

param enumParamEq1000 = numeral.M;
param enumParamEqFive = numeral.V;


uint8or32orDefault(enumEq1000, enumEqFive);
uint8or32orDefault(1000, 5);
writeln();

uint8vs32(numeral.I);
uint8vs32(numeral.M);
uint8vs32(enumEq1000);
uint8vs32(enumEqFive);
uint8vs32(enumParamEq1000);
uint8vs32(enumParamEqFive);
writeln();

uint8paramVsNot(1);
uint8paramVsNot(numeral.I);
//uint8paramVsNot(numeral.M);
//uint8paramVsNot(enumEq1000);
//uint8paramVsNot(enumEqFive);
//uint8paramVsNot(enumParamEq1000);
uint8paramVsNot(enumParamEqFive);
writeln();

uint16paramVsNot(1);
uint16paramVsNot(numeral.I);
uint16paramVsNot(numeral.M);
uint16paramVsNot(enumEq1000);
uint16paramVsNot(enumEqFive);
uint16paramVsNot(enumParamEq1000);
uint16paramVsNot(enumParamEqFive);
writeln();

uint8vs16(1);
uint8vs16(numeral.I);
uint8vs16(numeral.M);
uint8vs16(enumEq1000);
uint8vs16(enumEqFive);
uint8vs16(enumParamEq1000);
uint8vs16(enumParamEqFive);
writeln();

uint8vs16vsDefault(1);
uint8vs16vsDefault(numeral.I);
uint8vs16vsDefault(numeral.M);
uint8vs16vsDefault(enumEq1000);
uint8vs16vsDefault(enumEqFive);
uint8vs16vsDefault(enumParamEq1000);
uint8vs16vsDefault(enumParamEqFive);
writeln();


////

proc uint8or32orDefault(x: uint(8), y: uint(8)) {
  writeln("In uint(8) uint8or32orDefault");
}

proc uint8or32orDefault(x: uint(32), y: uint(32)) {
  writeln("In uint(32) uint8or32orDefault");
}

proc uint8or32orDefault(x: uint, y: uint) {
  writeln("In uint uint8or32orDefault");
}

////

proc uint8vs32(x: uint(8)) {
  writeln("In uint(8) uint8vs32");
}

proc uint8vs32(param x: uint(8)) {
  writeln("In uint(8) param uint8vs32");
}

proc uint8vs32(x: uint(32)) {
  writeln("In uint(32) uint8vs32");
}

proc uint8vs32(param x: uint(32)) {
  writeln("In uint(32) param uint8vs32");
}


////

proc uint8paramVsNot(x: uint(8)) {
  writeln("In uint(8) uint8paramVsNot");
}

proc uint8paramVsNot(param x: uint(8)) {
  writeln("In param uint(8) uint8paramVsNot");
}


////

proc uint16paramVsNot(x: uint(16)) {
  writeln("In uint(16) uint16paramVsNot");
}

proc uint16paramVsNot(param x: uint(16)) {
  writeln("In param uint(16) uint16paramVsNot");
}


////

proc uint8vs16(x: uint(8)) {
  writeln("In uint(8) uint8vs16");
}

proc uint8vs16(param x: uint(8)) {
  writeln("In param uint(8) uint8vs16");
}

proc uint8vs16(x: uint(16)) {
  writeln("In uint(16) uint8vs16");
}

proc uint8vs16(param x: uint(16)) {
  writeln("In param uint(16) uint8vs16");
}



////

proc uint8vs16vsDefault(x: uint(8)) {
  writeln("In uint(8) uint8vs16vsDefault");
}

proc uint8vs16vsDefault(param x: uint(8)) {
  writeln("In param uint(8) uint8vs16vsDefault");
}

proc uint8vs16vsDefault(x: uint(16)) {
  writeln("In uint(16) uint8vs16vsDefault");
}

proc uint8vs16vsDefault(param x: uint(16)) {
  writeln("In param uint(16) uint8vs16vsDefault");
}

proc uint8vs16vsDefault(x: uint) {
  writeln("In uint uint8vs16vsDefault");
}

proc uint8vs16vsDefault(param x: uint) {
  writeln("In param uint uint8vs16vsDefault");
}

