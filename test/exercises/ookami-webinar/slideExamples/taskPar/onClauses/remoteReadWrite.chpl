config const verbose = false;
var total = 0,
    done = false; 


on Locales[1] {
  if !done {
    if verbose then
      writef("Adding locale 1’s contribution");
    total += computeMyContribution();
  }
}

writeln(total);


proc computeMyContribution() {
  // pretend we're doing something interesting here
  return 42;
}
