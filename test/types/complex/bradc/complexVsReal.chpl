use Time;

config const numTrials = 1000000000;
config const printTimings = true;

{
  var C, Z, T: complex;

  {
    const startTime = getCurrentTime();
    for i in 1..numTrials {
      C.re = 2.0*i/numTrials - 1.5;
      C.im = 2.0*i/numTrials - 1.0;
    }
    if printTimings then
      writeln("Complex Loop 1: ", getCurrentTime() - startTime);
  }

  {
    const startTime = getCurrentTime();
    for i in 1..numTrials {
      Z.im = 2.0*Z.re*Z.im + C.im;
      Z.re = T.re - T.im + C.re;
    }
    if printTimings then
      writeln("Complex Loop 2: ", getCurrentTime() - startTime);
  }

  {
    const startTime = getCurrentTime();
    for i in 1..numTrials {
      T.re = Z.re**2;
      T.im = Z.im**2;
    }
    if printTimings then
      writeln("Complex Loop 3: ", getCurrentTime() - startTime);
  }
}

{
  var Cr, Ci, Zr, Zi, Tr, Ti: real;

  {
    const startTime = getCurrentTime();
    for i in 1..numTrials {
      Cr = 2.0*i/numTrials - 1.5;
      Ci = 2.0*i/numTrials - 1.0;
    }
    if printTimings then
      writeln("Real Loop 1: ", getCurrentTime() - startTime);
  }

  {
    const startTime = getCurrentTime();
    for i in 1..numTrials {
      Zi = 2.0*Zr*Zi + Ci;
      Zr = Tr - Ti + Cr;
    }
    if printTimings then
      writeln("Real Loop 2: ", getCurrentTime() - startTime);
  }
  
  {
    const startTime = getCurrentTime();
    for i in 1..numTrials {
      Tr = Zr**2;
      Ti = Zi**2;
    }
    if printTimings then
      writeln("Real Loop 3: ", getCurrentTime() - startTime);
  }
}
