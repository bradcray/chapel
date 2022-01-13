if CHPL_COMM == "none" then
  compilerWarning("This program will only work if CHPL_COMM != none");

if numLocales < 3 then
  warning("This program will only work when run with >= 3 locales");

writeln("Hello from locale 0!");
on Locales[1] do writeln("Hello from locale 1!");
on Locales[2] {
  writeln("Hello from locale 2!");
  on Locales[0] do writeln("Hello from locale 0!");
}
writeln("Back on locale 0");
