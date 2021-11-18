#ifndef ABILITY_H
#define ABILITY_H
#include "../time-to-do-list/timeToDoList.h"
#include "../../ADT List Statis/listtask.h"
#include "../../ADT Stack/stack.h"
#include "../../ADT Stack/bag.h"
#include "../../ADT Linked List/list_linked.h"
#include "../in_progress/in_progress.h"

/* Waktu akan bertambah 1 unit setiap Mobita berpindah 2 lokasi. Efek berlangsung
hingga Mobita telah melewati 10 lokasi */
void speedBoost(TIME *t, int *moveFreq, Stack b);

/* Kapasitas tas bertambah 1 */
void increaseCapacity(Stack *b);

/* Ability ini digunakan dengan command RETURN
  - Efek: Pesanan paling atas akan dikembalikan ke To Do List di urutan terakhir
  - Efek: Time limit yang terdapat pada pesanan dengan Perishable Item akan di-reset sebelum dikembalikan
  - Ability ini tidak dapat digunakan untuk pesanan VIP item
*/
void returnToSender(Stack *b, List *l, int *rtsCounter, TIME *t, boolean *senterPengecilAktif);

#endif