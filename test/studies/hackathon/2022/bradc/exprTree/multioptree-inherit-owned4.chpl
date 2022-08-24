class Exp {
  proc writeThis(ch) {
  }
}

class LeafExp: Exp {
  type t;
  const val: t;

  override proc writeThis(ch) {
    write(val);
  }
}

type VarExp = LeafExp(string);
type IntExp = LeafExp(int);

class OpExp: Exp {
  const op: string;
  const lhs: owned Exp;
  const rhs: owned Exp;

  override proc writeThis(ch) {
    ch.write("(");
    ch.write(lhs);
    ch.writef(" %s ", op);
    ch.write(rhs);
    ch.write(")");
  }
}

class AddExp: OpExp {
  proc init(in lhs, in rhs) {
    super.init("+", lhs, rhs);
  }
}

class SubExp: OpExp {
  proc init(in lhs, in rhs) {
    super.init("-", lhs, rhs);
  }
}

class MultExp: OpExp {
  proc init(in lhs, in rhs) {
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
