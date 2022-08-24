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

class AddExp: Exp {
  const lhs: Exp;
  const rhs: Exp;

  override proc writeThis(ch) {
    ch.write("(");
    ch.write(lhs);
    ch.write(" + ");
    ch.write(rhs);
    ch.write(")");
  }
}

var exp = new AddExp(new VarExp("x"), new IntExp(42));
writeln(exp);
