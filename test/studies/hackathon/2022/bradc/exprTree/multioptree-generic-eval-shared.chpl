class Exp {
  proc eval(env) {  // would like to make a pure virtual function...?
    return 0;
  }

  proc writeThis(ch) {
  }
}

class LeafExp: Exp {
  type t;
  const val: t;

  override proc eval(env) {
    if t == string then
      return env[val];
    else
      return val: int;
  }

  override proc writeThis(ch) {
    write(val);
  }
}

type VarExp = LeafExp(string);
type IntExp = LeafExp(int);

class OpExp: Exp {
  param op: string;
  const lhs: shared Exp;
  const rhs: shared Exp;

  override proc eval(env) {
    if op == "+" then
      return lhs.eval(env) + rhs.eval(env);
    else if op == "-" then
      return lhs.eval(env) - rhs.eval(env);
    else if op == "*" then
      return lhs.eval(env) * rhs.eval(env);
    else
      halt("Unknown operator: '", op, "'");
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

var env = ["x" => 3, "y" => 2, "z" => 45];
var exp = new shared AddExp(new shared VarExp("x"), new shared IntExp(42));
var exp2 = new shared AddExp(new shared VarExp("x"),
                             new shared MultExp(new shared VarExp("y"),
                                                new shared SubExp(
                                                  new shared VarExp("z"),
                                                  new shared IntExp(42))));

for (i,e) in zip (env.domain, env) do writeln(i, "=>", e);
writeln(exp, " = ", eval(exp,env));
writeln(exp2, " = ", eval(exp2,env));

proc eval(expr, env) {
  return expr.eval(env);
}
