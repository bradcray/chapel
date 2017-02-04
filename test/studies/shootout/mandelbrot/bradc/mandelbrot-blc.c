#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int n = 200;
int maxIter = 50;
double limit = 4.0;

#define bitsPerElt (8)
typedef uint8_t eltType;

int greaterThan(double x[8], double y[8], double z) {
  if ((x[0] + y[0]) <= z)
    return 0;
  if ((x[1] + y[1]) <= z)
    return 0;
  if ((x[2] + y[2]) <= z)
    return 0;
  if ((x[3] + y[3]) <= z)
    return 0;
  if ((x[4] + y[4]) <= z)
    return 0;
  if ((x[5] + y[5]) <= z)
    return 0;
  if ((x[6] + y[6]) <= z)
    return 0;
  if ((x[7] + y[7]) <= z)
    return 0;
  return 1;
}

int main(int argc, char* argv[]) {
  if (argc > 1) {
    n = atoi(argv[1]);
  }

  const int xdimSize = (n - 1) / bitsPerElt + 1;
  const double inv = 2.0 / n;
  double xvals[n];
  for (int i=0; i<n; i++) {
    xvals[i] = inv*i - 1.5;
  }
  double yvals[n];
  for (int i=0; i<n; i++) {
    yvals[i] = inv*i - 1.0;
  }

  eltType image[n*xdimSize];

  for (int y=0; y<n; y++) {
    for (int xelt=0; xelt<xdimSize; xelt++) {
      const double ci = yvals[y];
      const int xbase = xelt*bitsPerElt;
      double cr[8] = {xvals[xbase+0], xvals[xbase+1], xvals[xbase+2], xvals[xbase+3],
                      xvals[xbase+4], xvals[xbase+5], xvals[xbase+6], xvals[xbase+7]};
      double Zr[8], Zi[8], Tr[8], Ti[8];

      for (int iter=0; iter<maxIter; iter++) {
        for (int i=0; i<8; i++) {
          Zi[i] = 2.0*Zr[i]*Zi[i] + ci;
        }
        for (int i=0; i<8; i++) {
          Zr[i] = Tr[i] - Ti[i] + cr[i];
        }
        for (int i=0; i<8; i++) {
          Tr[i] = Zr[i]*Zr[i];
        }
        for (int i=0; i<8; i++) {
          Ti[i] = Zi[i]*Zi[i];
        }

        if (greaterThan(Tr, Ti, limit))
          break;
      }

      eltType buff;
      if (Tr[0] + Ti[0] <= limit)
        buff |= 0x1 << 7;
      if (Tr[1] + Ti[1] <= limit)
          buff |= 0x1 << 6;
      if (Tr[2] + Ti[2] <= limit)
        buff |= 0x1 << 5;
      if (Tr[3] + Ti[3] <= limit)
        buff |= 0x1 << 4;
      if (Tr[4] + Ti[4] <= limit)
        buff |= 0x1 << 3;
      if (Tr[5] + Ti[5] <= limit)
        buff |= 0x1 << 2;
      if (Tr[6] + Ti[6] <= limit)
        buff |= 0x1 << 1;
      if (Tr[7] + Ti[7] <= limit)
        buff |= 0x1 << 0;
                                      
      image[y*xdimSize + xelt] = buff;
    }
  }
  printf("P4\n");
  printf("%d %d\n", n, n);
  for (int i=0; i<n*xdimSize; i++) {
    printf("%d", image[i]);
  }
}
