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

var exp = new AddExp(new VarExp("x"), new IntExp(42));
writeln(exp);
