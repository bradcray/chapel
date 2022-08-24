class Exp {
  proc writeThis(ch) {
  }
}

class VarExp: Exp {
  const ident: string;

  override proc writeThis(ch) {
    write(ident);
  }
}

class IntExp: Exp {
  const val: int;

  override proc writeThis(ch) {
    write(val);
  }
}

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
