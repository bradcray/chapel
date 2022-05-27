config const x = 42;
enum color {red = 1, green = 2*red, blue= x};
writeln(color.red:int);
writeln(color.green:int);
writeln(color.blue:int);

