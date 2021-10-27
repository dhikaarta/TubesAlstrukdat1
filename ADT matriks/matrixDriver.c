#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


int main()
{
    int i,j,count;
    Matrix M1,M2,Mres, temp;
    printf("Masukkan baris dan kolom Matriks Pertama\n");
    scanf("%d %d", &i,&j);
    readMATRIX(&M1,i,j);
    printf("\n");
    count = countMATRIX(M1);
    printf("M1 memiliki %d elemen\n", count);

    printf("Masukkan baris dan kolom Matriks Kedua\n");
    scanf("%d %d", &i,&j);
    readMATRIX(&M2,i,j);
    printf("\n");
    count = countMATRIX(M2);
    printf("M2 memiliki %d elemen\n", count);

    
    if (isSquareMATRIX(M1)) {
        printf("Transpose M1 =\n");
        copyMATRIX(M1, &temp);
        transposeMATRIX(&temp);
        displayMATRIX(temp);
        printf("\n\n");

        printf("Determinan M1 = %.2f\n", determinantMATRIX(M1));
        printf("\n");
    }

    if (isSquareMATRIX(M2)) {
        printf("Transpose M2 =\n");
        copyMATRIX(M2, &temp);
        transposeMATRIX(&temp);
        displayMATRIX(temp);
        printf("\n\n");

        printf("Determinan M2 = %.2f\n", determinantMATRIX(M2));
        printf("\n");
    }




    CreateMATRIX(i,j,&Mres);
    if (isSizeEqualMATRIX(M1, M2))
    {
        Mres = addMATRIX(M1,M2);
        printf("Hasil penjumlahan kedua matriks adalah : \n");
        displayMATRIX(Mres);
        printf("\n");
        Mres = subtractMATRIX(M1,M2);
        printf("Hasil pengurangan matrix (M1 - M2) : \n");
        displayMATRIX(Mres);
        printf("\n");
    }
    if (COLSMATRIX(M1) == ROWSMATRIX(M2))
    {
    Mres = multiplyMATRIX(M1,M2);
    printf("Hasil M1 x M2 : \n");
    displayMATRIX(Mres);
    printf("\n");
    }
    Mres = multiplyConstMATRIX(M1,5);
    printf("Apabila matriks M1 dikalikan dengan konstanta 5 :\n");
    displayMATRIX(Mres);
    printf("\n");
    Mres = multiplyConstMATRIX(M2,5);
    printf("Apabila matriks M2 dikalikan dengan konstanta 5 :\n");
    displayMATRIX(Mres);
    printf("\n");


    if (isEqualMATRIX(M1, M2)) {
        printf("M1 sama dengan M2\n");
        printf("\n");
    }

    if (isSymmetricMATRIX(M1)) {
        printf("M1 adalah matriks simetrik\n");
        printf("\n");
    }

    if (isSymmetricMATRIX(M2)) {
        printf("M2 adalah matriks simetrik\n");
        printf("\n");
    }

    if (isIdentityMATRIX(M1)) {
        printf("M1 adalah matriks identitas\n");
        printf("\n");
    }

    if (isIdentityMATRIX(M2)) {
        printf("M2 adalah matriks identitas\n");
        printf("\n");
    }

    if (isSparseMATRIX(M1)) {
        printf("M1 adalah matriks sparse\n");
        printf("\n");
    }

    if (isSparseMATRIX(M2)) {
        printf("M2 adalah matriks sparse\n");
        printf("\n");
    }


    


}