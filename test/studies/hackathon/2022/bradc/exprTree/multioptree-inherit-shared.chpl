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
  var lhs: shared Exp;
  var rhs: shared Exp;

  override proc writeThis(ch) {
    ch.write("(");
    ch.write(lhs);
    ch.writef(" %s ", op);
    ch.write(rhs);
    ch.write(")");
  }
}

class AddExp: OpExp {
  proc init(in lhs: shared Exp, in rhs: shared Exp) {
    super.init("+", lhs, rhs);
  }
}

class SubExp: OpExp {
  proc init(in lhs: shared Exp, in rhs: shared Exp) {
    super.init("-", lhs, rhs);
  }
}

class MultExp: OpExp {
  proc init(in lhs: shared Exp, in rhs: shared Exp) {
    super.init("*", lhs, rhs);
  }
}

var exp = new shared AddExp(new shared VarExp("x"), new shared IntExp(42));
writeln(exp);
var exp2 = new shared AddExp(new shared VarExp("x"),
                             new shared MultExp(new shared VarExp("y"),
                                                new shared SubExp(
                                                  new shared VarExp("z"),
                                                  new shared IntExp(42))));
writeln(exp2);
