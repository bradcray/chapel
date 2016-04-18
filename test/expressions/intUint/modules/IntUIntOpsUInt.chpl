module IntUIntOpsUInt {
  config param safeCast = true;

  proc +(x: int(?w), y: uint(w)) {
    if safeCast then
      return x.safeCast(uint(w)) + y;
    else
      return x:uint(w) + y;
  }

  proc +(x: uint(?w), y: int(w)) {
    if safeCast then
      return x + y.safeCast(uint(w));
    else
      return x + y:uint(w);
  }
}
