#ifndef GADGET_H
#define GADGET_H

#include "../../ADT Stack/stack.h"
#include "../../ADT Stack/bag.h"
#include "../time-to-do-list/timeToDoList.h"
#include "../../ADT Linked List/list_linked.h"

/* Waktu dari perishable item teratas dalam tas kembali ke durasi semula */
void KainPembungkusWaktu(Stack *b, List *l);

/* Memperbesar kapasitas tas menjadi dua kali lipat, tidak melebihi batas maksimum
kapasitas tas */
void SenterPembesar(Stack *b);

/* Berpindah ke lokasi yang diinginkan tanpa menambahkan unit waktu */
void PintuKemanaSaja(TIME *t);

/* Mengurangi waktu sebanyak 50 unit */
/*
  ** Pesanan yang masuk dalam jangka waktu 50 unit tersebut tidak akan hilang/kembali ke To Do List
  ** Tidak akan muncul kembali ke To Do List ketika waktu masuknya dilampaui lagi
*/
void MesinWaktu(TIME *t);

/* Menghilangkan efek dari satu heavy item jika terdapat pada tumpukan teratas tas. Efek ini akan berlangsung sampai melakukan drop off / return pertama kali setelah penggunaan gadget ini */
void senterPengecil(Stack b, TIME *t, boolean *senterPengecilAktif) ;

#endif