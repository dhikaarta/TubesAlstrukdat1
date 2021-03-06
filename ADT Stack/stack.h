/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef STACK_H
#define STACK_H

#include "../ADT Queue/queuetask.h"
#include "../boolean.h"

#define IDX_UNDEF -1
#define MAX_CAPACITY_STACK 100

typedef struct
{
  int currentCAPACITYSTACK;
  ElTypeTASK buffer[MAX_CAPACITY_STACK]; /* tabel penyimpan elemen */
  int idxTop;                    /* alamat TOP: elemen puncak */
} Stack;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Stack, maka akses elemen : */
#define CURRENT_CAP_STACK(s) (s).currentCAPACITYSTACK
#define IDX_TOP_STACK(s) (s).idxTop
#define TOP_STACK(s) (s).buffer[(s).idxTop]


/* *** Konstruktor/Kreator *** */
void CreateSTACK(Stack *s);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean IsEmptySTACK(Stack s);
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean IsFullSTACK(Stack s);
/* Mengirim true jika tabel penampung nilai s stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushSTACK(Stack *s, ElTypeTASK task);
/* Menambahkan task sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. task menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopSTACK(Stack *s, ElTypeTASK *task);
/* Menghapus task dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. task adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

#endif
