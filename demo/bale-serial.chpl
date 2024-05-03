use Random; 

config const n = 10,
             m = 4;
 
  


var Src: [0..<n] int,
    Inds, Dst: [0..<m] int;

Src = [i in 0..<n] i*11;
fillRandom(Inds, min=0, max=n-1); 

for i in 0..<m do
  Dst[i] = Src[Inds[i]];


config const printArrays = true;

if printArrays {
  writeln("Src is:  ", Src);
  writeln("Inds is: ", Inds);
  writeln("Dst is:  ", Dst);
}
