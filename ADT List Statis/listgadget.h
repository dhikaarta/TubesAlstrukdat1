/* MODUL LIST GADGET */
/* Berisi definisi dan semua primitif pemrosesan list gadget dengan elemen 
   berupa idGadget (integer) dan harga (long) */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori array statik */

#ifndef LISTGADGET_H
#define LISTGADGET_H

#include "../boolean.h"

/*  Kamus Umum */
#define CAPACITY_LISTGAGDET 6
/* Kapasitas penyimpanan */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define VAL_UNDEF -999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct
{
   int idGADGET;
   long priceGADGET;
} ElTypeGadget; /* type elemen List */

typedef struct
{
   ElTypeGadget contents[CAPACITY_LISTGAGDET]; /* memori tempat penyimpan elemen (container) */
   int Neff;
} ListGADGET;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListGADGET, cara deklarasi dan akses: */
/* Deklarasi : l : ListGADGET */
/* Definisi : 
   List kosong: semua elemen idGadget bernilai VAL_UNDEF */

/* ********** SELEKTOR ********** */
#define ELMT_LISTGADGET(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateLISTGADGET(ListGADGET *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen idGadget pada content dengan VAL_UNDEF */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthLISTGADGET(ListGADGET l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyLISTGADGET(ListGADGET l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFullLISTGADGET(ListGADGET l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void displayLISTINVENTORY(ListGADGET l);
/* Proses : Menuliskan isi List, idGadget, dengan traversal, List ditulis dengan numbering dari 1..5 */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: 1. idGadget 2. idGadget ... (jika kosong) 3. - */

void displayLISTGADGETSTORE(ListGADGET l);
/* Proses : Menuliskan isi List, idGadget dan harga gadget, dengan traversal, 
   List ditulis dengan numbering dari 1..4 */
/* I.S. l tidak kosong */
/* F.S. 1. idGadget1 (harga1) 2. idGadget2 (harga2) ... */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastLISTGADGET(ListGADGET *l, int id, long price);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLISTGADGET(ListGADGET *l, int id);
/* Proses : Menghapus elemen dimana id berada */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen dengan id sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

#endif