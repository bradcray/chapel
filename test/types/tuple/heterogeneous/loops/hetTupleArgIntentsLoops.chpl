config param showBug = true; // flipping to false shows all other cases work

record R {
  var x: int;
}

record S {
  var y: int;
}

var homtup = (new R(1), new R(2));
var hettup = (new R(1), new S(2));

for ttt in homtup do
  writeln(ttt);

for ttt in hettup do
  writeln(ttt);

byRef(homtup);
byConstRef(homtup);
byDefaultIntent(homtup);
byInIntent(homtup);
byConstInIntent(homtup);

byRef(hettup);
byConstRef(hettup);
if showBug then
  byDefaultIntent(hettup);
byInIntent(hettup);
byConstInIntent(hettup);

proc byRef(ref tupArg) {
  for ttt in tupArg do
    writeln(ttt);
}

proc byConstRef(const ref tupArg) {
  for ttt in tupArg do
    writeln(ttt);
}

proc byDefaultIntent(tupArg) {
  for ttt in tupArg do
    writeln(ttt);
}

proc byInIntent(in tupArg) {
  for ttt in tupArg do
    writeln(ttt);
}

proc byConstInIntent(const in tupArg) {
  for ttt in tupArg do
    writeln(ttt);
}
