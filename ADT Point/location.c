#include "location.h"
#include <stdio.h>
#include <stdlib.h>
#include "../ADT mesin karakter & kata/wordmachine.h"
#include "../ADT mesin karakter & kata/wordmachine.c"
#include "../ADT mesin karakter & kata/charmachine.h"
#include "../ADT mesin karakter & kata/charmachine.c"

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

void BacaLOCATIONfile (LOCATION* p)
{
    char a;
    int x,y;
    advWORDfile();
    a = currentWordfile.contents[0];
    advWORDfile();
    x = atoi(currentWordfile.contents);
    advWORDfile();
    y = atoi(currentWordfile.contents);
    *p = MakeLOCATION(a,x,y);
}

void TulisLOCATION (LOCATION P){
    printf("%c (%.d,%d)", CHAR(P),LOC_X(P), LOC_Y(P));
}           

LOCATION* makeArrayOfLOCATION(int n, int i_headquarters, int j_headquarters){
    int i;
    LOCATION *arrayOfLoc = malloc(sizeof(LOCATION)*(n+1));
    arrayOfLoc[0] = MakeLOCATION('8', i_headquarters,j_headquarters);
    for(i=1;i<n+1;i++){
            BacaLOCATIONfile(&arrayOfLoc[i]);
    } 
    return arrayOfLoc;

}

void displaylistLOCATION(LOCATION* arrayOfLoc, int L)
{
    printf("[");
    for (int i = 0; i < L; i++)
    {
        printf("%c(%i, %i) ,", CHAR(arrayOfLoc[i]), LOC_X(arrayOfLoc[i]), LOC_Y(arrayOfLoc[i]));
        
    }
    printf("%c(%i, %i)", CHAR(arrayOfLoc[L]), LOC_X(arrayOfLoc[L]), LOC_Y(arrayOfLoc[L]));
    printf("]\n");
}