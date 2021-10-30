/* MODUL LIST GADGET */
/* Berisi definisi dan semua primitif pemrosesan list gadget dengan elemen 
   berupa idGadget (integer) dan harga (long) */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#ifndef LISTTASK_H
#define LISTTASK_H

#include "../boolean.h"

/*  Kamus Umum */
#define CAPACITY_LISTTASK 100
/* Kapasitas penyimpanan */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define VAL_UNDEF -999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct
{
    int timeTASK;
    char pickUpTASK;
    char dropOffTASK;
    char itemTASK;
    int timeExpTASK;
} ElTypeTASK; /* type elemen List */

typedef struct
{
    ElTypeTASK contents[CAPACITY_LISTTASK]; /* memori tempat penyimpan elemen (container) */
    int Neff;
} ListTASK;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListTASK, cara deklarasi dan akses: */
/* Deklarasi : l : ListTASK */
/* Definisi : 
   List kosong: semua elemen idGadget bernilai VAL_UNDEF */

/* ********** SELEKTOR ********** */
#define ELMT_LISTTASK(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateLISTTASK(ListTASK *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen idGadget pada content dengan VAL_UNDEF */

void ReadLISTTASK(ListTASK *l);

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthLISTTASK(ListTASK l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyLISTTASK(ListTASK l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFullLISTTASK(ListTASK l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void displayLISTTASK(ListTASK l);
/* Proses : Menuliskan isi List, idGadget, dengan traversal, List ditulis dengan numbering dari 1..5 */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: 1. idGadget 2. idGadget ... (jika kosong) 3. - */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void deleteFirstLISTTASK(ListTASK *l);
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

void deleteAtLISTTASK(ListTASK *l, ElTypeTASK *val, int idx);

ListTASK sortLISTTASK(ListTASK l);

#endif