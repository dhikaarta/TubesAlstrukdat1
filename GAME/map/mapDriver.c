#include "map.c"
#include "../../ADT Point/location.c"
#include "../../ADT matriks/matrix.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    // INSIASI TEMPAT-TEMPAT
    LOCATION* tempat;
    int N, M, x_hq, y_hq, nTempat;
    // SESUAI INPUTAN DI MAIN MENU
    N = 10;
    M = 15;
    x_hq = 1;
    y_hq = 1 ;
    nTempat = 17;
    
    //MEMBUAT ARRAY OF LOC
    tempat = makeArrayOfLOCATION(nTempat, x_hq, y_hq);
    // MEMBUAT MAP SESUAI NXM
    Matrix MAP;
    CreateMAP(N,M, &MAP);
    int i;

    // BUAT STRUKTUR MAP SESUAI ELMT
    readMAPConfiguration(&MAP, tempat, nTempat);

    // DISPLAY ALAMAT MAP
    displayMAP(MAP);


    return 0;
}