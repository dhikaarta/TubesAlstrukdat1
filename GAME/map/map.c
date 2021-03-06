#include <stdio.h>
#include <stdlib.h>
#include "../../ADT Point/location.h"
#include "../../ADT matriks/matrix.c"
#include "../../ADT Linked List/list_linked.h"
#include "../../ADT Stack/bag.h"
#include "../move/move.c"
#include "../../boolean.h"
#include "../pcolor/pcolor.h"


// FUNCTION TAMBAHAN UNTUK GAME
void CreateMAP(int nRow, int nCol, Matrix *m)
{
    ROWSMATRIX(*m) = nRow+2;
    COLSMATRIX(*m) = nCol+2;

}
    // HARUS JADI PARAMETER
    // - posisi nobita (kerjaan aq)
    // - pick up 
    // - drop off  
    // array of loc --> DONE!!
void displayMAP(Matrix m)
{   
    int i,j;
    for (i=0; i<ROWSMATRIX(m);i++){
        for (j=0; j<COLSMATRIX(m);j++){
            printf("%c", ELMTMATRIX(m, i,j));
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

// BELOM NERIMA PARAMETER TMPT PICK UP AND DROP OFF
void displayMAPColor(Matrix m, LOCATION nobita, LOCATION* ArrayOfPosMoves, int nPossibleMoves, List todo, Stack bag)
{   
    int i,j;
    
    for (i=0; i<ROWSMATRIX(m);i++){
        for (j=0; j<COLSMATRIX(m);j++){
            if (i!=0 && i != ROWSMATRIX(m)-1 &&j!=0 && j!=COLSMATRIX(m)-1 && ELMTMATRIX(m,i,j)!='\0'){
                boolean bool = checkLocationInPossibleMoves(i, j, ArrayOfPosMoves, nPossibleMoves);
                boolean blue, red;
                ElTypeTASK p; 
                Address q;
                blue = false;
                red = false;
                p = TOP_STACK(bag);
                q = FIRST(todo);
                if (ELMTMATRIX(m,i,j) == p.dropOffTASK) {
                    blue = true; 
                }
                while (!red && q != NULL){
                    if (ELMTMATRIX(m,i,j) == INFO(q).pickUpTASK) {
                        red = true;
                    } else {
                        q = NEXT(q);
                    }
                }
                if(LOC_X(nobita) == i && LOC_Y(nobita) == j){
                    print_yellow(ELMTMATRIX(m, i,j));
                } 
                
                if (blue && !(LOC_X(nobita) == i && LOC_Y(nobita) == j)){
                    print_blue(ELMTMATRIX(m, i,j));
                }
                if (red && !blue && !(LOC_X(nobita) == i && LOC_Y(nobita) == j)){
                    print_red(ELMTMATRIX(m, i,j));
                }
                if (bool && !red && !blue && !(LOC_X(nobita) == i && LOC_Y(nobita) == j)){
                    print_green(ELMTMATRIX(m, i,j));
                }
                if (!bool && !red && !blue && !(LOC_X(nobita) == i && LOC_Y(nobita) == j)){
                    printf("%c",ELMTMATRIX(m, i,j));
                }
            }else{
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
        }
        if (i < getLastIdxRowMATRIX(m)){
            printf("\n");
        }
    }   
}

void readMAPConfiguration(Matrix *m, LOCATION* tempat, int n){
    int indexArray;
    for(indexArray=0; indexArray<n;indexArray++){
        // UNTUK MENGECEK
        // printf("loc_x %d = %d\n",indexArray, LOC_X(tempat[indexArray]));
        // printf("loc_y %d = %d\n",indexArray, LOC_Y(tempat[indexArray]));
        // printf("char %d = %c\n",indexArray, CHAR(tempat[indexArray]));
        ELMTMATRIX(*m, LOC_X(tempat[indexArray]), LOC_Y(tempat[indexArray])) = CHAR(tempat[indexArray]);
    }
}

LOCATION getLocHQ(LOCATION *tempat ){
    return tempat[0];
}

LOCATION getLocKeX(LOCATION *tempat, int x){
    return tempat[x];
}

