#include <stdio.h>
#include "point.h"

int main() {
  POINT p1, p2;
  p1 = MakePOINT(1,2);

  BacaPOINT(&p2);

  TulisPOINT(p1); 
  TulisPOINT(p2);

  if (EQPOINT(p1,p2)) {
    printf("equal\n");
  }
  if (NEQPOINT(p1,p2)) {
    printf("not equal\n");
  }
  if (IsOriginPOINT(p2)) {
    printf("origin\n");
  }

  printf("kuadran p1 %d\n", KuadranPOINT(p1));

  printf("Next x point p2\n");
  TulisPOINT(NextXPOINT(p2));
  printf("Point p2 plus 3\n");
  TulisPOINT(PlusDeltaPOINT(p2,3,3));
  printf("Mirror Point p1\n");
  TulisPOINT(MirrorOfPOINT(p1, true));

  printf("Jarak 0 point p2 %d\n", Jarak0POINT(p2));
  printf("Panjang point p1 dan p2 %d\n", PanjangPOINT(p1,p2));


  return 0;
}