module IntUIntOpsInt {
  config param safeCast = true;

  proc +(x: int(?w), y: uint(w)) {
    if safeCast then
      return x + y.safeCast(int(w));
    else
      return x + y:int(w);
  }

  proc +(x: uint(?w), y: int(w)) {
    if safeCast then
      return x.safeCast(int(w)) + y;
    else
      return x:int(w) + y;
  }
}
