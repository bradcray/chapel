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
  param op: string;
  const lhs: Exp;
  const rhs: Exp;

  proc init(param op: string, in lhs: Exp, in rhs: Exp) {
    this.op = op;
    this.lhs = lhs;
    this.rhs = rhs;
  }
  
  override proc writeThis(ch) {
    ch.write("(");
    ch.write(lhs);
    ch.writef(" %s ", op);
    ch.write(rhs);
    ch.write(")");
  }
}

type AddExp = OpExp("+");
type SubExp = OpExp("-");
type MultExp = OpExp("*");

var exp = new AddExp(new VarExp("x"), new IntExp(42));
writeln(exp);
