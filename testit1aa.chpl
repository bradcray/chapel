enum color {red=1, green, blue};

const colorStrings = (1, 2, 3);
const colorVals = ("red", "green", "blue");

iter colorStringsIter() {
  yield 1;
  yield 2;
  yield 3;
}

var c: color;

writeln(c);

on Locales[numLocales-1] {
  local {
    extern proc printf(x...);
    printf("%lld\n", colorStrings[1]);
    var x = colorVals[2];
  }
}
