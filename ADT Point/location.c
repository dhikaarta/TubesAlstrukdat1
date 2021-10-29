#include "location.h"
#include <stdio.h>
#include <stdlib.h>

LOCATION MakeLOCATION (char A, int X, int Y){
    LOCATION p;
    CHAR(p) = A;
    LOC_X(p) = X;
    LOC_Y(p)= Y;
    return p;
}
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaLOCATION (LOCATION* p){
    char a;
    int x,y;
    scanf("%c", &a);
    while (getchar()!='\n' ){
            scanf("%d %d", &x, &y);
        }
    *p = MakeLOCATION(a,x,y);
}

void TulisLOCATION (LOCATION P){
    printf("%c (%.d,%d)", CHAR(P),LOC_X(P), LOC_Y(P));
}           

LOCATION* makeArrayOfLOCATION(int n){
    int i;
    LOCATION *arrayOfLoc = malloc(sizeof(LOCATION)*n);
    for(i=0;i<n;i++){
            BacaLOCATION(&arrayOfLoc[i]);
    } 
    return arrayOfLoc;

}
