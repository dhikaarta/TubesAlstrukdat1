#include "listgadget.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateLISTGADGET(ListGADGET *l)
{
    (*l).Neff = 0;
    int i;
    for (i = 0; i < CAPACITY_LISTGAGDET; i++)
    {
        (*l).contents[i].idGADGET = VAL_UNDEF;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthLISTGADGET(ListGADGET l)
{
    return l.Neff;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyLISTGADGET(ListGADGET l)
{
    return lengthLISTGADGET(l) == 0;
}
boolean isFullLISTGADGET(ListGADGET l)
{
    return lengthLISTGADGET(l) == CAPACITY_LISTGAGDET;
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void displayLISTINVENTORY(ListGADGET l)
{
    int i;
    for (i = 0; i < CAPACITY_LISTGAGDET; i++)
    {
        int id = l.contents[i].idGADGET;
        if (id == VAL_UNDEF)
        {
            printf("%d. -\n", i + 1);
        }
        else if (id == 1)
        {
            printf("%d. Kain Pembungkus Waktu\n", i + 1);
        }
        else if (id == 2)
        {
            printf("%d. Senter Pembesar\n", i + 1);
        }
        else if (id == 3)
        {
            printf("%d. Pintu Kemana Saja\n", i + 1);
        }
        else if (id == 4)
        {
            printf("%d. Mesin Waktu\n", i + 1);
        }
        else if (id == 5)
        {
            printf("%d. Senter Pengecil\n", i + 1);
        }
    }
}
void displayLISTGADGETSTORE(ListGADGET l)
{
    int i;
    for (i = 0; i < CAPACITY_LISTGAGDET; i++)
    {
        int id = l.contents[i].idGADGET;
        if (id == 1)
        {
            printf("%d. Kain Pembungkus Waktu (800 Yen)\n", i + 1);
        }
        else if (id == 2)
        {
            printf("%d. Senter Pembesar (1200 Yen)\n", i + 1);
        }
        else if (id == 3)
        {
            printf("%d. Pintu Kemana Saja (1500 Yen)\n", i + 1);
        }
        else if (id == 4)
        {
            printf("%d. Mesin Waktu  (3000 Yen)\n", i + 1);
        }
        else if (id == 5)
        {
            printf("%d. Senter Pengecil  (800 Yen)\n", i + 1);
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastLISTGADGET(ListGADGET *l, int id, long price)
{
    int i = 0;
    while (i < CAPACITY_LISTGAGDET && (*l).contents[i].idGADGET != VAL_UNDEF)
    {
        i++;
    }

    (*l).contents[i].idGADGET = id;
    (*l).contents[i].priceGADGET = price;
    (*l).Neff++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLISTGADGET(ListGADGET *l, int id)
{
    (*l).contents[id - 1].idGADGET = VAL_UNDEF;
    (*l).Neff--;
}