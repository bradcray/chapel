use BlockDist;

var A = newBlockArr({1..10}, real);

proc throwingFunction() throws {
  throw new owned Error("die!");
}

proc throwingCaller() throws {
  for a in A {
      throwingFunction();
  }
}

proc main() {
  try { throwingCaller(); }
  catch e { writeln("Caught an error!"); }
}
