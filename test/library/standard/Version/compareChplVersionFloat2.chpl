use Version;

for param i in 0..9 {
  var version = new sourceVersion(2, i, 0, "");
  param realVersion = 2 + i:real/10.0;
  writeln("testing ", version, ": ");
  if (realVersion == version) then
    writeln("passed");
  else
    compilerWarning("Problem with version: " + realVersion:string + " " + version:string);
}
/*
for param i in 10..99 {
  var version = new sourceVersion(2, i, 0, "");
  param realVersion = 2 + i:real/100.0;
  writeln("testing ", version, ": ");
  if (realVersion == version) then
    writeln("passed");
  else
    compilerWarning("Problem with version: " + realVersion:string + " " + version:string);
}
for param i in 100..104 {
  var version = new sourceVersion(2, i, 0, "");
  param realVersion = 2 + i:real/1000.0;
  writeln("testing ", version, ": ");
  if (realVersion == version) then
    writeln("passed");
  else
    compilerWarning("Problem with version: " + realVersion:string + " " + version:string);
}
*/
