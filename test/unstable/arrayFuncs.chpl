// We were considering deprecating these but have since pulled back the change
// and marked them unstable (going forward we might decide to continue
// deprecating these or moving them to another module or keeping them on the
// array)

var A = [1, 2, 1, 3, 1, 4, 1, 5];
writeln("Count of 1's in A = ", A.count(1));
writeln("A sorted is = ", A.sorted());
writeln("Finding 3 in A = ", A.find(3));
A.reverse();
writeln("Reversing A: ", A);