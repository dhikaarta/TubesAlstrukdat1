/* MODUL QUEUE TASK */


#ifndef QUEUETASK_H
#define QUEUETASK_H
#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../ADT List Statis/listtask.h"
/* KAMUS UMUM */
#define IDX_UNDEF -1
#define VAL_UNDEF -999
/* Definisi tipe elemen pesanan */


/* Definisi Queue Task (Dinamis) */
typedef struct {
    ElTypeTASK* bufferQUEUETASK;
    int idxHeadTASK;
    int idxTailTASK;
    int capacityQUEUETASK;
} QueueTASK;

/* ********** SELEKTOR ********** */
#define IDX_HEAD_QUEUETASK(qt) (qt).idxHeadTASK
#define IDX_TAIL_QUEUETASK(qt) (qt).idxTailTASK
#define HEAD_QUEUETASK(qt) (qt).bufferQUEUETASK[(qt).idxHeadTASK]
#define TAIL_QUEUETASK(qt) (qt).bufferQUEUETASK[(qt).idxTailTASK]
#define CAP_QUEUETASK(qt) (qt).capacityQUEUETASK
#define BUFFER_QUEUETASK(qt) (qt).bufferQUEUETASK
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create Queue kosong  */
void CreateQUEUETASK(QueueTASK *qt, int CAPACITY_QUEUETASK);
/* I.S. q sembarang, CAPACITY_QUEUETASK > 0 */
/* F.S. Terbentuk queue dinamis q kosong dengan kapasitas CAPACITY_QUEUETASK */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

void dealocateQUEUETASK(QueueTASK *qt);
/* I.S. q terdefinisi */
/* F.S. qt dikembalikan ke system, idxHeadTASK = IDX_UNDEF, idxTailTASK = IDX_UNDEF */

/* ********* Prototype ********* */
boolean IsEmptyQUEUETASK(QueueTASK qt);
/* Mengirim true jika qt kosong: lihat definisi di atas */
boolean IsFullQUEUETASK(QueueTASK qt);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai CAPACITY-1 */
int LengthQUEUETASK(QueueTASK qt);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika qt kosong. */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 

void ReadQUEUETASK(QueueTASK *qt, int nTask);
/* I.S. qt terdefinisi */
/* F.S. Memasukkan elemen ElTypeTASK ke dalam qt */

void ReadQUEUETASKfile(QueueTASK *qt);
/* I.S. qt terdefinisi */
/* F.S. Memasukkan elemen ElTypeTASK ke dalam qt dari file */

void displayQUEUETASK(QueueTASK qt);
/* Display task yang ada */


/* *** Primitif Add/Delete *** */
void EnqueueQUEUETASK(QueueTASK *qt, ElTypeTASK task);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void DequeueQUEUETASK(QueueTASK *qt, ElTypeTASK *task);
/* Proses: Menghapus task pada qt dengan aturan FIFO */
/* I.S. qt tidak mungkin kosong */

#endif