/* Modul ADT list berkait dengan representasi fisik pointer  */
/* Representasi Address dengan pointer */
/* ElType merupakan ADT */

#ifndef LIST_H
#define LIST_H

#include "../boolean.h"
#include "node.h"

typedef Address List;

#define FIRST(l) (l)
#define TIMETASK(l) INFO(l).timeTASK
#define PICKUPTASK(l) INFO(l).pickUpTASK
#define DROPOFFTASK(l) INFO(l).dropOffTASK
#define ITEMTASK(l) INFO(l).itemTASK
#define TIMEEXPTASK(l) INFO(l).timeExpTASK

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap pesanan dengan Address p dapat diacu INFO(p), NEXT(p) */
/* pesanan terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateLINKEDLIST(List *l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmptyLINKEDLIST(List l);
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElTypeTASK getTASKLINKEDLIST(List l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan pesanan l pada indeks idx */

void setTASKLINKEDLIST(List *l, int idx, ElTypeTASK task);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah pesanan l pada indeks ke-idx menjadi val */

int indexOfLINKEDLIST(List l, ElTypeTASK task);
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada pesanan list l yang bernilai task */
/* Jika ada, mengembalikan indeks pesanan pertama l yang bernilai task */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

void ReadLINKEDLISTTASKfile(List *l);
/* Prosedur baca 1 pesanan lewat file */
/* Harus melakukan traversal untuk membaca semua file yang ada */
/* Proses: insertlast pesanan pada l  */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN pesanan ***/
void insertFirstLINKEDLIST(List *l, ElTypeTASK task);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah pesanan dan */
/* menambahkan pesanan pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastLINKEDLIST(List *l, ElTypeTASK task);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah pesanan dan */
/* menambahkan pesanan list di akhir: pesanan terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtLINKEDLIST(List *l, ElTypeTASK task, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah pesanan dan */
/* menyisipkan pesanan dalam list pada indeks ke-idx (bukan menimpa pesanan di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN pesanan ***/
void deleteFirstLINKEDLIST(List *l, ElTypeTASK *task);
/* I.S. List l tidak kosong  */
/* F.S. pesanan pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat pesanan pertama di-dealokasi */
void deleteLastLINKEDLIST(List *l, ElTypeTASK *task);
/* I.S. list tidak kosong */
/* F.S. pesanan terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat pesanan terakhir di-dealokasi */

void deleteAtLINKEDLIST(List *l, int idx, ElTypeTASK *task);
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan pesanan l pada indeks ke-idx. */
/*      pesanan l pada indeks ke-idx dihapus dari l */

/****************** PROSES SEMUA pesanan LIST ******************/
void displayLINKEDLIST(List l);
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga pesanan bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

void displayToDoList(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, akan mencetak tempat pick up, drop off, dan
        jenis item yang harus diambil pada to do list */

int lengthLINKEDLIST(List l);
/* Mengirimkan banyaknya pesanan list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concatLINKEDLIST(List l1, List l2);
/* I.S. l1 dan l2 sembarang */
/* F.S. l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan pesanan list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

#endif