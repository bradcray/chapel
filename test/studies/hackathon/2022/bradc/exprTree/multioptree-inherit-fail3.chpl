// This version (with the assertion commented out) gives:
//
// tree.chpl:33: In initializer:
// tree.chpl:33: error: cannot default-initialize a variable with generic type
// tree.chpl:33: note: '<temporary>' has generic type 'borrowed OpExp'
// tree.chpl:33: note: cannot find initialization point to split-init this variable
//   tree.chpl:50: called as AddExp.init(lhs: owned Exp, rhs: owned Exp)
// note: generic instantiations are underlined in the above callstack
//

class Exp {
  proc writeThis(ch) {
  }
}

class LeafExp: Exp {
  type t;
  var val: t;

  override proc writeThis(ch) {
    write(val);
  }
}

type VarExp = LeafExp(string);
type IntExp = LeafExp(int);

class OpExp: Exp {
  var op: string;
  var lhs: Exp;
  var rhs: Exp;

  override proc writeThis(ch) {
    ch.write("(");
    ch.write(lhs);
    ch.writef(" %s ", op);
    ch.write(rhs);
    ch.write(")");
  }
}

class AddExp: OpExp {
  proc init(in lhs: Exp, in rhs: Exp) {
    super.init("+", lhs, rhs);
  }
}

class SubExp: OpExp {
  proc init(in lhs: Exp, in rhs: Exp) {
    super.init("-", lhs, rhs);
  }
}

class MultExp: OpExp {
  proc init(in lhs: Exp, in rhs: Exp) {
    super.init("*", lhs, rhs);
  }
}

var exp = new AddExp(new VarExp("x"), new IntExp(42));
writeln(exp);
var exp2 = new AddExp(new VarExp("x"),
                      new MultExp(new VarExp("y"), new SubExp(new VarExp("z"),
                                                              new IntExp(42)))
                     );
writeln(exp2);
