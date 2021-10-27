#include <stdio.h>
#include "listdin.h"

int main() {
    ListDin l1, l2, l3, l4;
    ElType maxL1, minL1, temp;
    IdxType i;

    CreateLISTDIN(&l1, 100);
    CreateLISTDIN(&l2, 100);

    printf("Masukkan banyak elemen list dinamis 1: ");
    readListLISTDIN(&l1);
    printf("list dinamis 1: ");
    displayListLISTDIN(l1);
    printf("\n");
    printf("--------------------- L 1 ---------------------\n");
    printf("panjang list: %d\n", lengthLISTDIN(l1));
    printf("last index: %d\n", getLastIdxLISTDIN(l1));
    printf("idx ke 1 valid:");
    isIdxValidLISTDIN(l1,1)? printf("true"): printf("false");
    printf("\n");
    printf("idx ke 1000 valid:");
    isIdxValidLISTDIN(l1,1000)? printf("true"): printf("false");
    printf("\n");
    printf("idx ke 1 terdefinisi:");
    isIdxEffLISTDIN(l1, 1)? printf("true"): printf("false");
    printf("\n");
    printf("idx ke 1000 terdefinisi:");
    isIdxEffLISTDIN(l1, 1000)? printf("true"): printf("false");
    printf("\n");
    printf("elemen kosong:");
    isEmptyLISTDIN(l1)? printf("true"): printf("false");
    printf("\n");
    printf("elemen bernilai 1 ada di: %d\n", indexOfLISTDIN(l1,1));
    extremesLISTDIN(l1, &maxL1, &minL1 );
    printf("penjumlahan seluruh elemen: %d\n", sumListLISTDIN(l1));
    printf("banyak elemen bernilai 1 di list 1: %d\n",countValLISTDIN(l1,1) );
    printf("semua elemen genap: ");
    isAllEvenLISTDIN(l1)? printf("true"): printf("false");
    printf("\n");
    sortLISTDIN(&l1, true);
    printf("hasil sort elemen ascending:\n");
    displayListLISTDIN(l1);
    printf("\n");
    sortLISTDIN(&l1, false);
    printf("hasil sort elemen descending:\n");
    displayListLISTDIN(l1);
    printf("\n");
    printf("hasil menambah elemen 1 di paling belakang:\n");
    insertLastLISTDIN(&l1, 1);
    displayListLISTDIN(l1);
    printf("\n");
    printf("hasil mengurangi elemen 1 di paling belakang:\n");
    deleteLastLISTDIN(&l1, &temp);
    displayListLISTDIN(l1);
    printf("\n");


    printf("Masukkan banyak elemen list dinamis 2: ");
    readListLISTDIN(&l2);
    printf("list dinamis 2: ");
    displayListLISTDIN(l2);
    printf("\n--------------------- L 1 & L 2 ---------------------\n");
    printf("pengecekan panjang dan isi l2 sama dengan l1: ");
    isListEqualLISTDIN(l1,l2)? printf("true"): printf("false");
    if (lengthLISTDIN(l1)==lengthLISTDIN(l2)){
        printf("Hasil penambahan elemen l1 dan l2: ");
        l3 = plusMinusListLISTDIN(l1,l2, true);
        displayListLISTDIN(l3);
        printf("\n");

        printf("Hasil pengurangan elemen l1 dan l2: ");
        l4 = plusMinusListLISTDIN(l1,l2, false);
        displayListLISTDIN(l4);
        printf("\n");

    }









    
}