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
  const lhs: owned Exp;
  const rhs: owned Exp;

  override proc eval(env) {
    if op == "+" then
      return lhs.eval(env) + rhs.eval(env);
    else if op == "-" then
      return lhs.eval(env) - rhs.eval(env);
    else if op == "*" then
      return lhs.eval(env) * rhs.eval(env);
    else
      compilerError("Unknown operator: '" + op + "'");
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
var exp = new AddExp(new VarExp("x"), new IntExp(42));
var exp2 = new AddExp(new VarExp("x"),
                      new MultExp(new VarExp("y"), new SubExp(new VarExp("z"),
                                                              new IntExp(42)))
                     );

for (i,e) in zip (env.domain, env) do writeln(i, "=>", e);
writeln(exp, " = ", eval(exp,env));
writeln(exp2, " = ", eval(exp2,env));

proc eval(expr, env) {
  return expr.eval(env);
}
