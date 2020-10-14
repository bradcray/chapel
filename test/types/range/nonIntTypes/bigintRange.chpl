use BigInteger;

var lo: bigint = 1;
var hi: bigint = 10;

for i in 1..10 do
  lo *= 1000;

hi += lo;

const r = lo..hi;

writeln(r);
for i in r do
  writeln(i);
