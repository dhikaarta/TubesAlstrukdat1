#ifndef ABILITY_H
#define ABILITY_H
#include "../time-to-do-list/timeToDoList.h"
#include "../../ADT List Statis/listtask.h"
#include "../../ADT Stack/stack.h"
#include "../../ADT Stack/bag.h"

/* Waktu akan bertambah 1 unit setiap Mobita berpindah 2 lokasi. Efek berlangsung
hingga Mobita telah melewati 10 lokasi */
void speedBoost(TIME *t, ElTypeTASK item);
/* Kapasitas tas bertambah 1 */
void increaseCapacity(Stack *b);

#endif