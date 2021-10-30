#include <stdio.h>
#include <stdlib.h>
#include "move.c"
#include "../../ADT matriks/matrix.c"
#include "../../ADT Point/point.h"
#include "../map/map.c"


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
///////////////////////////////////////////////////////////////
    Matrix adjacency;
    int nPoint = 17;
    // ADJ MAT PSTI NXN
    // headquarter(1) + nPoint(17) = 18
    readMATRIX(&adjacency, 18,18);
    printf("\n");
    displayMATRIX(adjacency);
    return 0;

    // INI HARUS ADA DI GLOBAL
    // - posisi nobita (kerjaan aq)
    // - pick up 
    // - drop off  
    // array of loc --> DONE!!

    LOCATION nobita;
    // SET DI HEADQUARTER BUAT YANG PALING AWAL
    nobita = getLocHQ(tempat);
    

}