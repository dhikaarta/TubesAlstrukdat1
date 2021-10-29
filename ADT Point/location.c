#include "location.h"
#include <stdio.h>
#include <stdlib.h>

LOCATION MakeLOCATION (char A, float X, float Y){
    LOCATION p;
    CHAR(p) = A;
    LOC_X(p) = X;
    LOC_Y(p)= Y;
    return p;
}
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaLOCATION (LOCATION* p){
    char a;
    float x,y;
    scanf("%c", &a);
    while (getchar()!='\n' ){
            scanf("%f %f", &x, &y);
        }
    *p = MakeLOCATION(a,x,y);
}

void TulisLOCATION (LOCATION P){
    printf("%c (%.0f,%.0f)", CHAR(P),LOC_X(P), LOC_Y(P));
}           

LOCATION* makeArrayOfLOCATION(int n){
    int i;
    LOCATION *arrayOfLoc = malloc(sizeof(LOCATION)*n);
    for(i=0;i<n;i++){
            BacaLOCATION(&arrayOfLoc[i]);
    } 
    return arrayOfLoc;

}
