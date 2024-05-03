use BlockDist;

config const n = 100;

const Dom = blockDist.createDomain({1..n});

forall i in Dom do
  writeln("Hello from iteration ", i, " of ", n, " on locale ", here.id);
writeln("Goodbye!");
