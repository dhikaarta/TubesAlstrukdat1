#include <stdio.h>
#include <stdlib.h>
#include "../../ADT Point/location.h"
#include "../../ADT matriks/matrix.h"
#include "../../boolean.h"
#include "../pcolor/pcolor.h"


LOCATION* makeArrayOfPossibleMoves(Matrix adjagency,LOCATION* tempat, LOCATION nobita, int nPoint, int *nPossibleMoves){
    //checking element of array position of nobita
    int i,urutanPoint;
    for (i=0;i<nPoint+1; i++){
        if (LOC_X(nobita)== LOC_X(tempat[i] )&& LOC_Y(nobita)==LOC_Y(tempat[i])){
            urutanPoint = i;
        }
            
    }
    //making array of possible moves
    int j, idx = 0;
    LOCATION* possibleMoves = malloc(sizeof(LOCATION)*(nPoint+1));
    for (j=0;j<nPoint+1; j++){
        if (ELMTMATRIX(adjagency,urutanPoint,j) == 1){
            possibleMoves[idx] = tempat[j];
            idx++;
        }
    }
    *nPossibleMoves = idx;
    return possibleMoves;
}

boolean checkLocationInPossibleMoves(int i, int j, LOCATION* ArrayOfPosMoves, int nPossibleMoves){
    int idx;
    for(idx=0; idx<nPossibleMoves;idx++){
        if ( i == LOC_X(ArrayOfPosMoves[idx])&& j == LOC_Y(ArrayOfPosMoves[idx])){
            return true;
        }
    }
    return false;
}