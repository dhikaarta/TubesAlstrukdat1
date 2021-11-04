#include <stdio.h>
#include <stdlib.h>
#include "ability.h"

void speedBoost(TIME *t, ElTypeTASK item) {
  // Setiap berpindah 2 lokasi, waktu bertambah 1 unit
  int n = 10;
  int i;
  (*t).incTime = 0.5;
  if (item.itemTASK == 'H') {
    (*t).incTime = 1;
  }
}

void increaseCapacity(Stack *b) {
  UpdateBAGsize(b, 1);
}