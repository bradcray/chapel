var locs = [Locales[3], Locales[1], Locales[0], Locales[2], Locales[3]];

forall loc in locs do
  writeln("Hello from ", here.id);

var B = locs;

B = locs;

record R {
  const targetLocDom: domain(1);
  const targetLocales: [targetLocDom] locale;
  
  proc init(Y: [] locale = Locales) {
    this.targetLocDom = {0..#Y.size};
    this.targetLocales = Y;
  }
}

writeln("About to set up myR");
var myR = new R(locs);

writeln("About to set up myR (2)");
var myR2 = new R();
