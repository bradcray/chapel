use Map;

// doing the same for a local map causes things to go off the rails on locale 1
proc main() {
  var m: map(int, string);
  m.add(1, "one");

  on Locales[1] {
    for k in m.keys() do
      writeln(k);
  }
}
