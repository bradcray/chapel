config param testError = 0, testDisplayRepresentation = false;

proc testRangeAPI(lbl, r: range(?), idx, subr) {
  proc testHi() {
    writeln(r.low);
    writeln(r.high);
    writeln(r.alignment);
  }
  writeln(lbl);
  writeln("------------");
  writeln(r);
    testHi();
  writeln("idxType          = ", r.idxType:string);
    testHi();
  writeln("stridable        = ", r.stridable);
    testHi();
  writeln("boundedType      = ", r.boundedType);
    testHi();
  writeln("isRangeType()    = ", isRangeType(r.type));
    testHi();
  writeln("isBoundedRange() = ", isBoundedRange(r));
    testHi();
  writeln("hasLowBound()    = ", r.hasLowBound());
    testHi();
  writeln("hasHighBound()   = ", r.hasHighBound());
    testHi();
  writeln("stride           = ", r.stride);
    testHi();
  writeln("alignment        = ", r.alignment);
    testHi();
  writeln("aligned          = ", r.aligned);
    testHi();
  writeln("first            = ", r.first);
    testHi();
  writeln("last             = ", r.last);
    testHi();
  writeln("low              = ", r.low);
    testHi();
  writeln("high             = ", r.high);
  /*
  writeln("alignedLow       = ", r.alignedLow);
  writeln("alignedHigh      = ", r.alignedHigh);
  writeln("isEmpty()        = ", r.isEmpty());
  writeln("size             = ", r.size);
  writeln("length           = ", r.length);
  writeln("hasFirst()       = ", r.hasFirst());
  writeln("hasLast()        = ", r.hasLast());
  writeln("isNat.Algned()   = ", r.isNaturallyAligned());
  writeln("isAmbiguous      = ", r.isAmbiguous());
  writeln("member(", idx, ") = ", r.member(idx));
  writeln(subr.stride);
  writeln(subr.stride < 0);
  writeln("member(", subr, ") = ", r.member(subr));
  writeln("ident(self)      = ", ident(r, r));
  writeln("ident(other)     = ", ident(r, subr));
  writeln("boundsCheck(", idx, ") = ", r.boundsCheck(idx));
  writeln("boundsCheck(", subr, ") = ", r.boundsCheck(subr));
  writeln("indexOrder(", idx, ") = ", r.indexOrder(idx));
  writeln("orderToIndex(3)  = ", r.orderToIndex(3));
  writeln("translate(2)     = ", r.translate(2));
  writeln("translate(2)     = ", r.translate(-2));
  writeln("interior(2)      = ", r.interior(2));
  writeln("interior(-2)     = ", r.interior(-2));
  writeln("exterior(2)      = ", r.exterior(2));
  writeln("exterior(-2)     = ", r.exterior(-2));
  writeln("expand(2)        = ", r.expand(2));
  writeln("offset(1)        = ", r.offset(1));
          
  writeln("serial iteration = ");
  for i in r do
    write(i, " ");
  writeln();

  writeln("r#2               = ", r#2);
  writeln("r#-2              = ", r#-2);
  writeln("r == subr         = ", r == subr);
  writeln("r != subr         = ", r != subr);
  writeln("r[subr]           = ", r[subr]);
  writeln("r[subr] == subr[r]= ", r[subr] == subr[r]);
  
  var r2 = r;
  writeln("Copying...        = ", r2);
  */
}
