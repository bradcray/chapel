config const verbose = false;
var total = 0,
    done = false; 

writeln((verbose, total, done), " live on ",
        (verbose.locale, total.locale, done.locale));

on Locales[1] {
  var x, y, z: int;

  writeln((x, y, z), " live on ", (x.locale, y.locale, z.locale));

  // NOTE: module-scope constants are replicated on all locales
  writeln((verbose, total, done), " live on ",
          (verbose.locale, total.locale, done.locale));
}
