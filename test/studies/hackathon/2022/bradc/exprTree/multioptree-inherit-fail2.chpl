// commented out INT_ASSERT at functionResolution.cpp:2618 and got:
//
// multioptree-inherit-fail2.chpl:44: In initializer:
// multioptree-inherit-fail2.chpl:45: error: const actual is passed to 'ref' formal 'src' of chpl__initCopy()
// multioptree-inherit-fail2.chpl:45: error: const actual is passed to 'ref' formal 'src' of chpl__initCopy()
// multioptree-inherit-fail2.chpl:44: error: cannot default-initialize a variable with generic type
// multioptree-inherit-fail2.chpl:44: note: '<temporary>' has generic type 'borrowed OpExp'
// multioptree-inherit-fail2.chpl:44: note: cannot find initialization point to split-init this variable
//  multioptree-inherit-fail2.chpl:61: called as AddExp.init(lhs: owned Exp, rhs: owned Exp)
// note: generic instantiations are underlined in the above callstack
//

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
  const lhs: Exp;
  const rhs: Exp;

  override proc writeThis(ch) {
    ch.write("(");
    ch.write(lhs);
    ch.writef(" %s ", op);
    ch.write(rhs);
    ch.write(")");
  }
}

class AddExp: OpExp {
  proc init(lhs: Exp, rhs: Exp) {
    super.init("+", lhs, rhs);
  }
}

class SubExp: OpExp {
  proc init(lhs: Exp, rhs: Exp) {
    super.init("-", lhs, rhs);
  }
}

class MultExp: OpExp {
  proc init(lhs: Exp, rhs: Exp) {
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
