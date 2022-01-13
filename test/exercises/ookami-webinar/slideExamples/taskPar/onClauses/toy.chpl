use IO;

proc main() {
  var x = stdin.read(int);
  writeln("Hello!");

  coforall loc in Locales do
    on loc do
      writeln(loc.id * x);

  writeln("Bye!");
}
