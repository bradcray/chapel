class Exp {
  proc print() {
  }
}

class VarExp: Exp {
  const ident: string;

  override proc print() {
    write(ident);
  }
}

class IntExp: Exp {
  const val: int;

  override proc print() {
    write(val);
  }
}

class AddExp: Exp {
  const lhs: Exp;
  const rhs: Exp;
  const op: string;

  override proc print() {
    write("(");
    lhs.print();
    write(" + ");
    rhs.print();
    write(")");
  }
}

var exp = new AddExp(new VarExp("x"), new IntExp(42));
exp.print();
