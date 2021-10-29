#include <stdio.h>
#include <stdlib.h>
#include "../../ADT Point/location.h"
#include "../../ADT matriks/matrix.c"
#include "../../boolean.h"

// FUNCTION TAMBAHAN UNTUK GAME
void CreateMAP(int nRow, int nCol, Matrix *m)
{
    ROWSMATRIX(*m) = nRow+2;
    COLSMATRIX(*m) = nCol+2;

}
void displayMAP(Matrix m)
{   
    int i,j;
    boolean bool= true;
    for (i=0; i<ROWSMATRIX(m);i++){
        for (j=0; j<COLSMATRIX(m);j++){
            print("%c", ELMTMATRIX(m, i,j));
            if (i==0){
                printf("*");
            }else if (i == ROWSMATRIX(m)-1){
                printf("*");
            }else if (j==0){
                printf("*");
            }else if (j==COLSMATRIX(m)-1){
                printf("*");
            }else if (ELMTMATRIX(m,i,j)=='\0'){
                printf(" ");
            }
        }
        if (i < getLastIdxRowMATRIX(m)){
            printf("\n");
        }
    }   
}

void readMAPConfiguration(Matrix *m, LOCATION* tempat, int n, int x_hq, int y_hq){
    int nobitaSymbol = 8;
    char nobita = nobitaSymbol+'0';
    ELMTMATRIX(*m, x_hq, y_hq) = nobita;
    int indexArray;
    for(indexArray=0; indexArray<n;indexArray++){
        // UNTUK MENGECEK
        // printf("loc_x %d = %d\n",indexArray, LOC_X(tempat[indexArray]));
        // printf("loc_y %d = %d\n",indexArray, LOC_Y(tempat[indexArray]));
        // printf("char %d = %c\n",indexArray, CHAR(tempat[indexArray]));
        ELMTMATRIX(*m, LOC_X(tempat[indexArray]), LOC_Y(tempat[indexArray])) = CHAR(tempat[indexArray]);
    }
}

