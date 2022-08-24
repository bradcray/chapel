// fails with:
//
// multioptree-inherit-fail4.chpl:37: In initializer:
// multioptree-inherit-fail4.chpl:37: error: cannot default-initialize a variable with generic type
// multioptree-inherit-fail4.chpl:37: note: '<temporary>' has generic type 'borrowed OpExp'
// multioptree-inherit-fail4.chpl:37: note: cannot find initialization point to split-init this variable

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
  proc init(in lhs: owned Exp, in rhs: owned Exp) {
    super.init("+", lhs, rhs);
  }
}

class SubExp: OpExp {
  proc init(in lhs: owned Exp, in rhs: owned Exp) {
    super.init("-", lhs, rhs);
  }
}

class MultExp: OpExp {
  proc init(in lhs: owned Exp, in rhs: owned Exp) {
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
