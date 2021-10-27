#include <stdio.h>
#include "listpos.h"

int main() {
    ListPos l1, l2, l3, l4;
    ElType maxL1, minL1, temp;

    CreateLISTPOS(&l1);
    CreateLISTPOS(&l2);

    printf("Masukkan banyak elemen list dinamis 1: ");
    readListLISTPOS(&l1);
    printf("list dinamis 1: ");
    displayListLISTPOS(l1);
    printf("\n");
    printf("--------------------- L 1 ---------------------\n");
    printf("panjang list: %d\n", lengthLISTPOS(l1));
    printf("idx ke 1 valid:");
    isIdxValidLISTPOS(l1,1)? printf("true"): printf("false");
    printf("\n");
    printf("idx ke 1000 valid:");
    isIdxValidLISTPOS(l1,1000)? printf("true"): printf("false");
    printf("\n");
    printf("idx ke 1 terdefinisi:");
    isIdxEffLISTPOS(l1, 1)? printf("true"): printf("false");
    printf("\n");
    printf("idx ke 1000 terdefinisi:");
    isIdxEffLISTPOS(l1, 1000)? printf("true"): printf("false");
    printf("\n");
    printf("elemen kosong:");
    isEmptyLISTPOS(l1)? printf("true"): printf("false");
    printf("\n");
    printf("elemen bernilai 1 ada di: %d\n", indexOfLISTPOS(l1,1));
    extremesLISTPOS(l1, &maxL1, &minL1 );
    printf("semua elemen genap: ");
    isAllEvenLISTPOS(l1)? printf("true"): printf("false");
    printf("\n");
    sortLISTPOS(&l1, true);
    printf("hasil sort elemen ascending:\n");
    displayListLISTPOS(l1);
    printf("\n");
    sortLISTPOS(&l1, false);
    printf("hasil sort elemen descending:\n");
    displayListLISTPOS(l1);
    printf("\n");
    printf("hasil menambah elemen 1 di paling belakang:\n");
    insertLastLISTPOS(&l1, 1);
    displayListLISTPOS(l1);
    printf("\n");
    printf("hasil mengurangi elemen 1 di paling belakang:\n");
    deleteLastLISTPOS(&l1, &temp);
    displayListLISTPOS(l1);
    printf("\n");


    printf("Masukkan banyak elemen list dinamis 2: ");
    readListLISTPOS(&l2);
    printf("list dinamis 2: ");
    displayListLISTPOS(l2);
    printf("\n--------------------- L 1 & L 2 ---------------------\n");
    printf("pengecekan panjang dan isi l2 sama dengan l1: ");
    isListEqualLISTPOS(l1,l2)? printf("true"): printf("false");
    if (lengthLISTPOS(l1)==lengthLISTPOS(l2)){
        printf("Hasil penambahan elemen l1 dan l2: ");
        displayListLISTPOS(plusMinusTabLISTPOS(l1, l2, true));
        printf("\n");

        printf("Hasil pengurangan elemen l1 dan l2: ");
        displayListLISTPOS(plusMinusTabLISTPOS(l1, l2, false));
        printf("\n");
    }









    
}