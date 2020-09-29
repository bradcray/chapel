use Version;

param v2_1_0 = 2.1;
const v2_1_1 = version(2,1,1);
const v2_2_0 = version(2,2,0);
const v2_2_1 = version(2,2,1);
param v3_1_0 = 3.1;
const v3_1_1 = version(3,1,1);

const v2_1_0_p = version(2,1,0,"aaa");
const v2_1_1_p = version(2,1,1,"bbb");
const v2_2_0_p = version(2,2,commit="ccc");
const v2_2_1_p = version(2,2,1,"ddd");
const v3_1_0_p = version(3,1,0,"eee");
const v3_1_1_p = version(3,1,1,"fff");

compareBothVersions(v2_1_0, v2_1_0_p);
//compareGTVersions(v2_1_0_p, v2_1_0);

compareBothVersions(v2_1_0, v2_1_1);
compareBothVersions(v2_1_0, v2_2_0);
compareBothVersions(v2_1_0, v2_2_1);
compareBothVersions(v2_1_0, v3_1_1);

compareBothVersions(v2_1_0, v2_1_1_p);
compareBothVersions(v2_1_0, v2_2_0_p);
compareBothVersions(v2_1_0, v2_2_1_p);
compareBothVersions(v2_1_0, v3_1_0_p);
compareBothVersions(v2_1_0, v3_1_1_p);

compareBothVersions(v3_1_0, v2_1_1);
compareBothVersions(v3_1_0, v2_2_0);
compareBothVersions(v3_1_0, v2_2_1);
compareBothVersions(v3_1_0, v3_1_1);
compareBothVersions(v3_1_0, v3_1_1_p);

proc compareBothVersions(param v1, v2) {
  writeln("Comparing versions:");
  writeln(v1);
  writeln(v2);
  writeln("------------------");
  writeln("== : ", v1 == v2);
  writeln("!= : ", v1 != v2);
  writeln("<  : ", v1 < v2);
  writeln("<= : ", v1 <= v2);
  writeln(">  : ", v1 > v2);
  writeln(">= : ", v1 >= v2);
  writeln();

  writeln("Comparing versions:");
  writeln(v2);
  writeln(v1);
  writeln("------------------");
  writeln("== : ", v2 == v1);
  writeln("!= : ", v2 != v1);
  writeln("<  : ", v2 < v1);
  writeln("<= : ", v2 <= v1);
  writeln(">  : ", v2 > v1);
  writeln(">= : ", v2 >= v1);
  writeln();
}

proc compareLTVersions(param v1, v2) {
  writeln("Comparing versions:");
  writeln(v1);
  writeln(v2);
  writeln("------------------");
  writeln("== : ", v1 == v2);
  writeln("!= : ", v1 != v2);
  writeln("<  : ", v1 < v2);
  writeln("<= : ", v1 <= v2);
  writeln();
}

proc compareGTVersions(v1, param v2) {
  writeln("Comparing versions:");
  writeln(v1);
  writeln(v2);
  writeln("------------------");
  writeln("== : ", v1 == v2);
  writeln("!= : ", v1 != v2);
  writeln(">  : ", v1 > v2);
  writeln(">= : ", v1 >= v2);
  writeln();
}

