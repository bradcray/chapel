config const numTasks = here.maxTaskPar;

coforall i in 1..numTasks do
  writeln("Hello from task ", i, " of ", numTasks);
writeln("Goodbye!");
