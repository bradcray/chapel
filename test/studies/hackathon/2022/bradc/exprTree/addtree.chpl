class Exp {
  proc print() {
  }
}

class VarExp: Exp {
  var ident: string;

  override proc print() {
    write(ident);
  }
}

class IntExp: Exp {
  var val: int;

  override proc print() {
    write(val);
  }
}

class AddExp: Exp {
  var lhs: Exp;
  var rhs: Exp;
  var op: string;

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
