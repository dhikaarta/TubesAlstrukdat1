#include <stdio.h>
#include <stdlib.h>
#include "move.c"
#include "../../ADT matriks/matrix.h"
#include "../../ADT Point/point.h"
#include "../map/map.c"
#include "../../ADT Point/location.c"




int main(){
    List todo;
    Stack bag;
    CreateLINKEDLIST(&todo);
    CreateBAG(&bag);
    // INSIASI TEMPAT-TEMPAT
    LOCATION* tempat ;
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

//////////////////////////////////////////////////////////////////

    Matrix adjacency;
    int nPoint = 17;
    // ADJ MAT PSTI NXN
    // headquarter(1) + nPoint(17) = 18

    readMATRIX(&adjacency, nPoint+1 ,nPoint+1);
    printf("\n");
    displayMATRIX(adjacency);

    // INI HARUS ADA DI GLOBAL
    // - posisi nobita (kerjaan aq)
    // - pick up 
    // - drop off  
    // array of loc --> DONE!!

    LOCATION nobita;
    // SET DI HEADQUARTER BUAT YANG PALING AWAL
    nobita = getLocHQ(tempat);
    // nobita = getLocKeX(tempat,5);

    //INI BUAT JUMLAH POSSIBLE MOVES, DI SET DI 0 TERUS TIAP PANGGIL ARRAY OF POSSIBLE MOVES
    int lokasiDipilih;
    do{
        int nPossibleMoves;
        LOCATION* arrayPosMove;
        arrayPosMove = makeArrayOfPossibleMoves(adjacency, tempat, nobita, nPoint, &nPossibleMoves);
        printf("\nPosisi yang dapat dicapai:\n");
        for (i=0;i<nPossibleMoves;i++){
            printf("%d. %c (%d,%d)\n", i+1, CHAR(arrayPosMove[i]), LOC_X(arrayPosMove[i]), LOC_Y(arrayPosMove[i]));
        }
        displayMAPColor(MAP,nobita, arrayPosMove, nPossibleMoves, todo, bag);
        printf("\nPosisi yang dipilih? (ketik 0 jika ingin kembali) ");
        scanf("%d", &lokasiDipilih);
        nobita = arrayPosMove[lokasiDipilih-1];
        printf("\nMobita sekarang berada di titik ");
        TulisLOCATION(nobita);
        printf("!");
        printf("\n");
    }while (lokasiDipilih!=0);
    return 0;
}