use Time;

config const trials = 100_000_000;
enum days {Mon=1, Tue=2, Wed=3, Thu=4, Fri=5, Sat=6, Sun=7}

//var daysArr = for day in days do day; // does not compile
var daysArr: [1..7] days;
for (a, d) in zip (daysArr, days) do a = d;
writeln(daysArr);

var t: Timer; t.start();
var total = 0;
for 1..trials {
  for day in daysArr { // for day in days generates weird patten with alloc?
    total += day:int;
  }
}
assert(total == 28 * trials);
writef("%.2drs\n", t.elapsed());
