class C {
  var y: int;
}

pragma "always RVF"
record R {
  var x: int = 42;
  var c: unmanaged C = new unmanaged C(23);

  record RserHelper {
    var x: int;
    var y: int;
  }
  
  proc chpl__serialize() {
    writeln("In my serialize");
    return new RserHelper(x, c.y);
  }

  proc type chpl__deserialize(data) {
    writeln("In my deserialize");
    return new R(x=data.x, c = new unmanaged C(y=data.y));
  }
}


config param modInLoop = false;


proc main() {
  var myR: R;

  //  var data = myR.chpl__serialize();

  writeln(myR);
  writeln(myR.locale);
  writeln(myR.c.locale);
  on Locales[1] {
    writeln(myR);
    writeln(myR.locale);
    writeln(myR.c.locale);

    /*
    var myRCopy = R.chpl__deserialize(data);
    writeln(myRCopy);
    writeln(myRCopy.locale);
    writeln(myRCopy.c.locale);
    */

    if modInLoop {
      myR.x = -1;
      myR.c.y = -2;
      writeln(myR);
    }
  }
  writeln(myR);
  writeln(myR.locale);
  writeln(myR.c.locale);
}

