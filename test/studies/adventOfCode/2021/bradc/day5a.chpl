use IO;

var xmax, ymax: int;

iter readCoords() {
  var x1, y1, x2, y2: int;
  while readf("%i,%i -> %i,%i", x1, y1, x2, y2) {
    if x1 > xmax then xmax = x1;
    if x2 > xmax then xmax = x2;
    if y1 > ymax then ymax = y1;
    if y2 > ymax then ymax = y2;
    yield ((x1,y1),(x2,y2));
  }
}

var coords = readCoords();
config const debug = (max(xmax,ymax) < 20),
             verbose = false;
if debug then writeln(coords);

param X = 0, Y = 1;

var count: [0..xmax, 0..ymax] atomic int;

forall ((x1,y1),(x2,y2)) in coords with (ref count) {
  const minx = min(x1, x2);
  const maxx = max(x1, x2);
  const miny = min(y1, y2);
  const maxy = max(y1, y2);
  if verbose then
    writeln("Doing: ", (x1,x2), " ", (y1, y2));
  if x1 == x2 {
    if y1 <= y2 {
      count[x1..x2, y1..y2].add(1);
    }  else {
      count[x1..x2, y2..y1].add(1);
    }
  } else if y1 == y2 {
    if x1 <= x2 {
      count[x1..x2, y1..y2].add(1);
    }  else {
      count[x2..x1, y1..y2].add(1);
    }
  } else {
    const xstride = if x1 < x2 then 1 else -1;
    const ystride = if y1 < y2 then 1 else -1;
    if verbose {
      writeln("Trying ", (x1..x2 by xstride), " ", (y1..y2 by ystride));       
      writeln((x1..x2 by xstride).size);                                       
      writeln((y1..y2 by ystride).size); 
    }
    for (x,y) in zip(minx..maxx by xstride, miny..maxy by ystride) do
      count[x,y].add(1);
  }
}

if debug then writeln(count);

writeln(+ reduce (count.read() >= 2));

