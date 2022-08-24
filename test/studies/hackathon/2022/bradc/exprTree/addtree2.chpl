class Exp {
  proc writeThis(ch) {
  }
}

class VarExp: Exp {
  var ident: string;

  override proc writeThis(ch) {
    write(ident);
  }
}

class IntExp: Exp {
  var val: int;

  override proc writeThis(ch) {
    write(val);
  }
}

class AddExp: Exp {
  var lhs: Exp;
  var rhs: Exp;

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
