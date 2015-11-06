// isx-global.chpl
// 
// Port of ISx to Chapel, developed by Brad Chamberlain on
// 2015-11-05 to try and use more of a global programming
// style.  Based on the SPMD Chapel version.
//

//
// TODO: Top priorities:
// - LocaleSpace -> BucketSpace/Buckets
// - timer insertion
// - performance analysis / chplvis


// TODO:
// * variants that we should try
//   - multiple buckets per locale w/out any atomic ints
//   - some sort of hybrid between the current 1 bucket per locale scheme
//     and the previous?


//
// TODO: What are the potential performance issues?
// * put as one message?
// * how do Ben's locality optimizations do?
// * does returning arrays cost us anything?  Do we leak them?
// * other?
// * (this would be a good chplvis demo)
//

use BlockDist, DSIUtil;

//
// The type of key to use when sorting.
//
config type keyType = int(32);

// TODO: replace 'numLocales' below with 'numBuckets' and LocaleSpace
// with BucketSpace (or somesuch)??

//
// The following options respectively control...
// - whether or not to print debug information
// - whether to print it on all trials, or just the first one
// - whether or not to do a test run (results in small problem sizes)
// - whether or not to run quietly (squashes successful verification messages)
// - whether or not to print the execution time configuration
//
config const debug = false,
             debugAllTrials = false,
             testrun = debug,
             quiet = false,
             printConfig = !quiet;


//
// Define three scaling modes: strong scaling, weak scaling, and
// weakISO (in which the number of buckets per locale is held
// constant.
//
enum scaling {strong, weak, weakISO};

//
// Which scaling mode should the program be run in?
//
config const mode = scaling.strong;

//
// The number of keys is defined in terms of 'n', though whether this
// represents the total number of keys or the number of keys per
// bucket depends on whether we're running in a strong or weak scaling
// mode.  When debugging, we run a smaller problem size.
//
config const n = if testrun then 32 else 2**27;


//
// How many buckets should we store per locale and total?
//
config const bucketsPerLocale = 1;  // TODO: or here.maxTaskPar?
       const numBuckets = numLocales * bucketsPerLocale;

// TODO: If we made bucketsPerLocale a config param, could do the following.
// Or, could simply make a config param saying whether or not we expected
// this to be greater than 1.
//
//type safeCountType = if (bucketsPerLocale == 1) then atomic int else int;
//
type safeCountType = atomic int;


//
// The total number of keys
//
config const totalKeys = if mode == scaling.strong then n
                                                   else n * numBuckets;

//
// The number of keys per locale -- this is approximate for strong
// scaling if the number of locales doesn't divide 'n' evenly.
//
config const keysPerBucket = if mode == scaling.strong
                               then divceil(n, numBuckets)
			       else n;


//
// The bucket width to use per locale when running in weakISO mode
//
config const isoBucketWidth = if mode == scaling.weakISO then 8192 else 0;
//
// Issue a warning if this has been set in modes other than weakISO
//
if !quiet && mode != scaling.weakISO && isoBucketWidth != 0 then
  warning("Note that isoBucketWidth has no effect for weakISO scaling mode");

//
// The maximum key value to use.  When debugging, use a small size.
//
config const maxKeyVal = if mode == scaling.weakISO 
                           then numBuckets * isoBucketWidth
			   else (if testrun then 32 else 2**28);

//
// When running in the weakISO scaling mode, this width of each bucket
// is fixed.  Otherwise, it's the largest key value divided by the
// number of locales.
//
config const bucketWidth = if mode == scaling.weakISO
                             then isoBucketWidth
			     else divceil(maxKeyVal, numBuckets);

//
// This tells how large the receive buffer should be relative to the
// average number of keys per locale.
//
config const recvBuffFactor = 2.0,
             recvBuffSize = (totalKeys * recvBuffFactor): int;

//
// These specify the number of burn-in runs and number of experimental
// trials, respectively.  If the number of trials is zero, we exit
// after printing the configuration (useful for debugging problem size
// logic without doing anything intense).
//
config const numBurnInRuns = if debug then 0 else 1,
             numTrials = 1;


// TODO: add timers and timing printouts

if printConfig then
  printConfiguration();

if numTrials == 0 then
  exit(0);

//
// TODO: rename to just buckets?
//
const LocBucketSpace = {0..#numBuckets};
const BucketSpace = LocBucketSpace dmapped Block(LocBucketSpace);

const KeySpace = {0..#totalKeys} dmapped Block({0..#totalKeys});

var allBucketKeys: [BucketSpace] [0..#recvBuffSize] int;
var recvOffset: [BucketSpace] atomic int;
var verifyKeyCount: atomic int;
  
//
// Run bucketsort numtrials + numBurnInRuns times.  To make
// the indices for the numtrials runs 1..numTrials, we start
// counting at 1-numBurnInRuns.
//
// Only time the non-burn-in executions (those with positive indices).
// Only verify the final timed run to save verification time.
//
for i in 1-numBurnInRuns..numTrials do
  bucketSort(time=(i>0), verify=(i==numTrials));

if debug {
  writeln("\n", "final buckets:");
  for (i,b) in zip(BucketSpace, allBucketKeys) do
    writeln("  Bucket ", i, " (owned by ", b.locale.id, "): ", b);
}
  

proc bucketSort(time = false, verify = false) {
  var keys = makeInput();
  var bucket2KeyInds = computeBucketsToKeys(keys);

  forall b in BucketSpace {
    var keysPerBucket: [LocBucketSpace] safeCountType;
    var myKeys = keys.localSlice[bucket2KeyInds[b]];

    //
    // TODO: Note the nested "express all parallelism" style.  Do we like?
    //
    forall key in myKeys {
      const bucketIndex = key / bucketWidth;
      keysPerBucket[bucketIndex].add(1);
    }
    if (debug) then
      writeln("bucket ", b, " (on locale ", here.id, ") has key count of: ", keysPerBucket);

    var sendOffsets: [LocBucketSpace] int = + scan keysPerBucket.read();
    sendOffsets -= keysPerBucket.read();
    if debug then writeln("bucket ", b, " (on locale ", here.id, ") has send offsets of: ", sendOffsets);
  }
  /*
  var keysPerBucket: [BucketSpace] [LocBucketSpace] safeCountType;
  forall bucket in BucketSpace {
    var bucketSizes = countLocalBucketSizes(keys);
  }

  var bucketSizes = countLocalBucketSizes(keys);
  if debug && verify then writeln(here.id, ": bucketSizes = ", bucketSizes);
*/

  /*

  //
  // TODO: Should we be able to support scans on arrays of atomics without a
  // .read()?
  //
  // TODO: We really want an exclusive scan, but Chapel's is inclusive... :(
  //
  var sendOffsets: [LocaleSpace] int = + scan bucketSizes.read();
  sendOffsets -= bucketSizes.read();
  if debug && verify then writeln(here.id, ": sendOffsets = ", sendOffsets);

  //
  // TODO: should we pass our globals into/out of these routines?
  //
  var myBucketedKeys = bucketizeLocalKeys(myKeys, sendOffsets);
  exchangeKeys(sendOffsets, bucketSizes, myBucketedKeys);

  //
  // TODO: discussed with Jake a version in which the histogramming
  // (countLocalKeys) was done in parallel with the exchangeKeys;
  // the exchange keys task would write a "done"-style sync variable
  // when a put was complete and the task could begin aggressively
  // histogramming the next buffer's worth of data.  Use a cobegin
  // to kick off both of these tasks in parallel and know when they're
  // both done.
  //

  const keysInMyBucket = recvOffset[here.id].read();
  var myLocalKeyCounts = countLocalKeys(keysInMyBucket);

  if (verify) then
    verifyResults(keysInMyBucket, myLocalKeyCounts);

  //
  // reset the receive offsets for the next iteration
  //
  recvOffset[here.id].write(0);
*/
}


// TODO: Is all this returning of local arrays going to cause problems?


//
// TODO: introduce BucketSpace domain instead of LocaleSpace
//
// const BucketSpace = {0..#numBuckets);


// TODO: What's best order for these procs?

proc bucketizeLocalKeys(myKeys, sendOffsets) {
  var bucketOffsets: [LocaleSpace] atomic int;

  bucketOffsets.write(sendOffsets);

  var myBucketedKeys: [0..#keysPerBucket] keyType;
  
  forall key in myKeys {
    const bucketIndex = key / bucketWidth;
    const idx = bucketOffsets[bucketIndex].fetchAdd(1);
    myBucketedKeys[idx] = key; 
  }

  if debug then
    writeln(here.id, ": myBucketedKeys = ", myBucketedKeys);

  return myBucketedKeys;
}


proc countLocalBucketSizes(keys) {
  // TODO: if adding numBuckets, change to that here
  /*
  var bucketSizes: [LocBucketSpace] atomic int;
  var localKeys = 

  forall key in keys {
    const bucketIndex = key / bucketWidth;
    bucketSizes[bucketIndex].add(1);
  }

  return bucketSizes;
*/
}

// TODO: does emacs not highlight 'here'?


proc exchangeKeys(sendOffsets, bucketSizes, myBucketedKeys) {
  forall locid in LocaleSpace {
    //
    // perturb the destination locale by our ID to avoid bottlenecks
    //
    const dstlocid = (locid+here.id) % numBuckets;
    const transferSize = bucketSizes[dstlocid].read();
    const dstOffset = recvOffset[dstlocid].fetchAdd(transferSize);
    const srcOffset = sendOffsets[dstlocid];
    //
    // TODO: are we implementing this with one communication?
    // If not, and we turn on Rafa's optimization, is it better?
    //
    allBucketKeys[dstlocid][dstOffset..#transferSize] = 
             myBucketedKeys[srcOffset..#transferSize];
  }

}


proc countLocalKeys(myBucketSize) {
  // TODO: what if we used a global histogram here instead?
  const myMinKeyVal = here.id * bucketWidth;
  var myLocalKeyCounts: [myMinKeyVal..#bucketWidth] atomic int;
  //
  // TODO: Can we use a ref/array alias to allBucketKeys[here.id] to avoid
  // redundant indexing?
  //
  forall i in 0..#myBucketSize do
    myLocalKeyCounts[allBucketKeys[here.id][i]].add(1);

  if debug then
    writeln(here.id, ": myLocalKeyCounts[", myMinKeyVal, "..] = ", 
            myLocalKeyCounts);

  return myLocalKeyCounts;
}


proc verifyResults(myBucketSize, myLocalKeyCounts) {
  //
  // verify that all of my keys are in the expected range (myKeys)
  //
  const myMinKeyVal = here.id * bucketWidth;
  const myKeys = myMinKeyVal..#bucketWidth;
  forall i in 0..#myBucketSize {
    const key = allBucketKeys[here.id][i];
    if !myKeys.member(key) then
      halt("got key value outside my range: "+key + " not in " + myKeys);
  }

  //
  // verify that histogram sums properly
  //
  const myTotalLocalKeys = + reduce myLocalKeyCounts.read();
  if myTotalLocalKeys != myBucketSize then
    halt("local key count mismatch:" + myTotalLocalKeys + " != " + myBucketSize);

  //
  //
  //
  verifyKeyCount.add(myBucketSize);
  if verifyKeyCount.read() != totalKeys then
    halt("total key count mismatch: " + verifyKeyCount.read() + " != " + totalKeys);

  if (!quiet && here.id == 0) then
    writeln("Verification successful!");
}


proc makeInput() {
  //
  // TODO: can we get this to work?
  // extern {
  // #include "pcg_basic.h"
  // }
  require "ref-version/pcg_basic.h", "ref-version/pcg_basic.c";

  extern type pcg32_random_t;
  extern proc pcg32_srandom_r(ref rng: pcg32_random_t, 
                              initstate: uint(64),
                              initseq: uint(64));
  extern proc pcg32_boundedrand_r(ref rng: pcg32_random_t, 
                                  bound: uint(32)
                                 ): uint(32);

  var keys: [KeySpace] keyType;

  coforall loc in keys.targetLocales() do on loc {
    var rng: pcg32_random_t;

    //
    // Seed RNG
    //
    if debug then
      writeln(here.id, ": Calling pcg32_srandom_r with ", here.id);

    pcg32_srandom_r(rng, here.id:uint(64), here.id:uint(64));

    assert(keys.hasSingleLocalSubdomain());

    const myKeyInds = keys.localSubdomain();

    //
    // Fill local array
    //
    for k in myKeyInds do
      keys.localAccess[k] = pcg32_boundedrand_r(rng, 
						maxKeyVal.safeCast(uint(32))
						).safeCast(keyType);
  }

  if debug then
    writeln("keys = ", keys);

  return keys;
}


//
// Compute which keys in KeySpace each bucket "owns"
//
proc computeBucketsToKeys(keys) {
  var bucket2KeyInds: [BucketSpace] range;
  forall b in BucketSpace do
    bucket2KeyInds[b] = computeBlock(totalKeys, numBuckets, b);

  if debug then
    writeln("bucket2KeyInds = ", bucket2KeyInds);

  return bucket2KeyInds;
}

proc computeBlock(a,b,c) {
  const (lo,hi) = _computeBlock(a,b,c,a-1,0,0);
  return lo..hi;
}


proc printConfiguration() {
  writeln("scaling mode = ", mode);
  writelnPotentialPowerOfTwo("total keys = ", totalKeys);
  writelnPotentialPowerOfTwo("keys per bucket = ", keysPerBucket);
  writelnPotentialPowerOfTwo("maxKeyVal = ", maxKeyVal);
  writelnPotentialPowerOfTwo("bucketWidth = ", bucketWidth);
  writeln("numTrials = ", numTrials);
  writeln("numBuckets = ", numBuckets);
}


proc writelnPotentialPowerOfTwo(desc, n) {
  write(desc, n);
  const lgn = log2(n);
  if 2**lgn == n then
    write(" (2**", lgn, ")");
  writeln();
}
