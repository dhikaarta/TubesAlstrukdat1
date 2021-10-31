#include "location.h"
#include <stdio.h>
#include <stdlib.h>
#include "../ADT mesin karakter & kata/wordmachine.h"
#include "../ADT mesin karakter & kata/wordmachine.c"
#include "../ADT mesin karakter & kata/charmachine.h"
#include "../ADT mesin karakter & kata/charmachine.c"

LOCATION MakeLOCATION (char* A, float X, float Y){
    LOCATION p;
    CHAR(p) = A;
    LOC_X(p) = X;
    LOC_Y(p)= Y;
    return p;
}
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaLOCATION (LOCATION* p){
    char* a;
    int x,y;
    scanf("%c", &a);
    while (getchar()!='\n' ){
            scanf("%d %d", &x, &y);
        }
    *p = MakeLOCATION(a,x,y);
}

void BacaLOCATIONfile (LOCATION* p)
{
    char* a;
    float x,y;
    advWORDfile();
    printf("%s\n", currentWordfile.contents);
    a = currentWordfile.contents;
    printf("%s\n", a);
    advWORDfile();
    printf("%s\n", currentWordfile.contents);
    x = atof(currentWordfile.contents);
    printf("%f\n", x);
    advWORDfile();
    printf("%s\n", currentWordfile.contents);
    y = atof(currentWordfile.contents);
    printf("%f\n", y);
    *p = MakeLOCATION(a,x,y);
}

void TulisLOCATION (LOCATION P){
    printf("%c (%.d,%d)", CHAR(P),LOC_X(P), LOC_Y(P));
}           

LOCATION* makeArrayOfLOCATION(int n){
    int i;
    LOCATION *arrayOfLoc = malloc(sizeof(LOCATION)*n);
    for(i=0;i<n;i++){
            BacaLOCATIONfile(&arrayOfLoc[i]);
    } 
    return arrayOfLoc;

}

void displaylistLOCATION(LOCATION* arrayOfLoc, int L)
{
    for (int i = 0; i < L; i++)
    {
        printf("[");
        printf("%s, (%f, %f)", CHAR(arrayOfLoc[i]), LOC_X(arrayOfLoc[i]), LOC_Y(arrayOfLoc[i]));
        printf("]\n");
    }
}