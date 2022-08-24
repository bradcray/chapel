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

class SubExp: Exp {
  var lhs: Exp;
  var rhs: Exp;

  override proc writeThis(ch) {
    ch.write("(");
    ch.write(lhs);
    ch.write(" - ");
    ch.write(rhs);
    ch.write(")");
  }
}

class MultExp: Exp {
  var lhs: Exp;
  var rhs: Exp;

  override proc writeThis(ch) {
    ch.write("(");
    ch.write(lhs);
    ch.write(" * ");
    ch.write(rhs);
    ch.write(")");
  }
}

var exp = new AddExp(new VarExp("x"), new IntExp(42));
writeln(exp);
var exp2 = new AddExp(new VarExp("x"),
                      new MultExp(new VarExp("y"), new SubExp(new VarExp("z"),
                                                              new IntExp(42)))
                     );
writeln(exp2);
