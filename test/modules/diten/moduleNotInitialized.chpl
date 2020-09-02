module OuterModule {
  var lock1: sync bool;
  var lock2: sync bool;

  module M1 {
    use OuterModule;
    class C {
      var field: int;
    }
    var a: unmanaged C?;
    var raninit = false;
    proc init() {
      if (!raninit) {
        raninit = true;
        lock1.writeEF(false);
        lock2.readFE();
        a = new unmanaged C(1);
      }
    }
  }

  module M2 {
    use OuterModule;
    proc main {
      var b, c: sync borrowed object?;
      begin {
        use M1;
        M1.init();
        b.writeEF(a);
      }
      lock1.readFE();
      use M1;
      M1.init();
      c = a;
      lock2.writeEF(false);

      writeln(b.readFF());
      writeln(c.readFF());
      delete M1.a;
    }
  }
}
