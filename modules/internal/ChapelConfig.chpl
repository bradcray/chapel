
  use ChapelDataPar;  // needed for 
  use CTypes;  // needed for c_char below

  //  we'd use a chapel string type here instead, but that will require some
  //  compiler changes to work.
  pragma "command line setting"
  proc _command_line_cast(param s: chpl_c_string, type t, x:c_ptrConst(c_char)) {
    if isSyncType(t) then
      compilerError("config variables of sync type are not supported");
    if isSingleType(t) then
      compilerError("config variables of single type are not supported");
    if isAtomicType(t) then
      compilerError("config variables of atomic type are not supported");

    try! {
      var str = string.createCopyingBuffer(x);
      if t == string {
        return str;
      } else {
        use Regex;
        if t==regex(string) || t==regex(bytes) then
          return new regex(str);
        else
          return str:t;
      }
    }
  }
  // These two are called by compiler-generated code.
  extern proc chpl_config_has_value(name, module_name): bool;
  extern proc chpl_config_get_value(name, module_name): c_ptrConst(c_char);

