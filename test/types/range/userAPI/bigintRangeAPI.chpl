use BigInteger, rangeAPItest;;

var lo: bigint = 1;
var hi: bigint = 10;

for i in 1..10 do
  lo *= 1000;

hi += lo;

testRangeAPI("bigint range", lo..hi, lo+7, (lo+2)..(hi-3));
/*
testRangeAPI("bigint strided", lo..hi by 2, lo+7, (lo+2)..(hi-3) by 2);
testRangeAPI("unbounded range", lo.., lo+7, (lo+2)..(hi-3));
testRangeAPI("upper unbounded", ..hi, lo+7, (lo+2)..(hi-3));
testRangeAPI("neg upper unbounded", ..hi by -1, lo+7, (lo+2)..(hi-3) by -1);
*/
