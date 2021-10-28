#include "listgadget.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateLISTGADGET(ListGADGET *l)
{
    /* I.S. l sembarang */
    /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
    /* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
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
    /* Mengirimkan banyaknya elemen efektif List */
    /* Mengirimkan nol jika List kosong */
    return l.Neff;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidLISTGADGET(ListGADGET l, int i)
{
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return (i < CAPACITY_LISTGAGDET && i >= 0);
}
boolean isIdxEffLISTGADGET(ListGADGET l, int i)
{
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
    /* yaitu antara 0..lengthLISTGADGET(l)-1 */
    return (i >= 0 && i < lengthLISTGADGET(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyLISTGADGET(ListGADGET l)
{
    /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    /* *** Test List penuh *** */
    return lengthLISTGADGET(l) == 0;
}
boolean isFullLISTGADGET(ListGADGET l)
{
    ;
    /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return lengthLISTGADGET(l) == CAPACITY_LISTGAGDET;
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void displayLISTINVENTORY(ListGADGET l)
{
    /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika List kosong : menulis [] */
    int i;
    for (int i = 0; i < CAPACITY_LISTGAGDET; i++)
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
    }
}
void displayLISTGADGETSTORE(ListGADGET l)
{
    /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika List kosong : menulis [] */
    int i;
    for (int i = 0; i < CAPACITY_LISTGAGDET; i++)
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
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastLISTGADGET(ListGADGET *l, int id, long price)
{
    /* Proses: Menambahkan val sebagai elemen terakhir List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
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
    /* Proses : Menghapus elemen terakhir List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    (*l).contents[id - 1].idGADGET = VAL_UNDEF;
    (*l).Neff--;
}