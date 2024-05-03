config const numTasks = here.maxTaskPar;

coforall loc in Locales do
  on loc do
    coforall i in 1..numTasks do
      writeln("Hello from task ", i, " of ", numTasks, " on locale ", here.id);
writeln("Goodbye!");
