use BlockDist, Random; 

config const n = 10,
             m = 4;
 
const SrcInds = blockDist.createDomain(0..<n),
      DstInds = blockDist.createDomain(0..<m);

var Src: [SrcInds] int,
    Inds, Dst: [DstInds] int;

Src = [i in 0..<n] i*11;
fillRandom(Inds, min=0, max=n-1); 

forall (d, i) in zip(Dst, Inds) do {
  d = Src[i];


config const printArrays = true;

if printArrays {
  writeln("Src is:  ", Src);
  writeln("Inds is: ", Inds);
  writeln("Dst is:  ", Dst);
}
