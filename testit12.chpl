config var m = 1,
           n = 1,
           p = 1;

proc foo(type t: []) {
  writeln(t:string);
}

debugDomDist=true;

writeln("------- In user code ------");
foo([1..m] [1..n, 1..p] real);

debugDomDist = false;
