#ifndef GADGET_H
#define GADGET_H

#include "../../ADT Stack/stack.h"
#include "../../ADT Stack/bag.h"
#include "../time-to-do-list/timeToDoList.h"

/* Waktu dari perishable item teratas dalam tas kembali ke durasi semula */
void KainPembungkusWaktu(Stack *b);
/* Memperbesar kapasitas tas menjadi dua kali lipat, tidak melebihi batas maksimum
kapasitas tas */
/*
  Required:
  - spek tas
*/
void SenterPembesar(Stack *b);
/* Berpindah ke lokasi yang diinginkan tanpa menambahkan unit waktu */
void PintuKemanaSaja(TIME *t);
/* Mengurangi waktu sebanyak 50 unit */
/*
  ** Pesanan yang masuk dalam jangka waktu 50 unit tersebut tidak akan hilang/kembali ke To Do List
  ** Tidak akan muncul kembali ke To Do List ketika waktu masuknya dilampaui lagi
*/
void MesinWaktu(TIME *t);

#endif