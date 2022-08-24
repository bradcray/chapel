// Error:
//
// multioptree-generic-eval-owned-nilable-fail.chpl:37: In method 'eval':
// multioptree-generic-eval-owned-nilable-fail.chpl:39: error: unresolved call 'owned Exp?.eval([DefaultAssociativeDom(string,true)] int(64))'
// multioptree-generic-eval-owned-nilable-fail.chpl:5: note: this candidate did not match: Exp.eval(env)
// multioptree-generic-eval-owned-nilable-fail.chpl:39: note: because method call receiver with type 'owned Exp?'
// multioptree-generic-eval-owned-nilable-fail.chpl:5: note: is passed to formal 'this: borrowed Exp'
// multioptree-generic-eval-owned-nilable-fail.chpl:39: note: try to apply the postfix ! operator to method call receiver
// multioptree-generic-eval-owned-nilable-fail.chpl:39: note: other candidates are:
// multioptree-generic-eval-owned-nilable-fail.chpl:17: note:   LeafExp.eval(env)
// multioptree-generic-eval-owned-nilable-fail.chpl:37: note:   OpExp.eval(env)
// multioptree-generic-eval-owned-nilable-fail.chpl:72: note:   eval(expr, env)
// multioptree-generic-eval-owned-nilable-fail.chpl:39: error: unresolved call 'owned Exp?.eval([DefaultAssociativeDom(string,true)] int(64))'
// multioptree-generic-eval-owned-nilable-fail.chpl:5: note: this candidate did not match: Exp.eval(env)
// multioptree-generic-eval-owned-nilable-fail.chpl:39: note: because method call receiver with type 'owned Exp?'
// multioptree-generic-eval-owned-nilable-fail.chpl:5: note: is passed to formal 'this: borrowed Exp'
// multioptree-generic-eval-owned-nilable-fail.chpl:39: note: try to apply the postfix ! operator to method call receiver
// multioptree-generic-eval-owned-nilable-fail.chpl:39: note: other candidates are:
// multioptree-generic-eval-owned-nilable-fail.chpl:17: note:   LeafExp.eval(env)
// multioptree-generic-eval-owned-nilable-fail.chpl:37: note:   OpExp.eval(env)
// multioptree-generic-eval-owned-nilable-fail.chpl:72: note:   eval(expr, env)
//   multioptree-generic-eval-owned-nilable-fail.chpl:73: called as (OpExp(\"+\")).eval(env: [DefaultAssociativeDom(string,true)] int(64)) from function 'eval'
//   multioptree-generic-eval-owned-nilable-fail.chpl:69: called as eval(expr: owned OpExp(\"+\"), env: [DefaultAssociativeDom(string,true)] int(64))
// note: generic instantiations are underlined in the above callstack
//
//

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
  const lhs: owned Exp?;
  const rhs: owned Exp?;

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
