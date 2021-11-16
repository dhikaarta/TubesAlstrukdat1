#include <stdio.h>
#include <stdlib.h>
#include "ability.h"

void speedBoost(TIME *t, int *moveFreq, Stack b) {
  int i;
  boolean found = false;
  if (IDX_TOP_STACK(b) > 0) {
    for (i = IDX_TOP_STACK(b) - 1; i >= 0; i--) {
      if (b.buffer[i].itemTASK == 'H') {
        found = true;
      } 
    }
  }
  if (found == false) {
    if (*moveFreq <= 10) {
      (*t).incTime = 0.5;
    } else {
      (*t).incTime = 1;
      *moveFreq = 0;
    }
  }
}

void increaseCapacity(Stack *b) {
  UpdateBAGsize(b, 1);
}

void returnToSender(Stack *b, List *l) {
  ElTypeTASK x;
  if (TOP_STACK(*b).itemTASK != 'V') {
    // Item di atas tas dikembalikan ke To Do List di urutan terakhir
    PopBAG(b, &x);
    insertLastLINKEDLIST(l, x);
  }
  // Time limit yang terdapat pada pesanan dengan Perishable Item akan di-reset sebelum dikembalikan
  int i;
  for (i = IDX_TOP_STACK(*b); i >= 0; i--) {
    if ((*b).buffer[i].itemTASK == 'P') {
      (*b).buffer[i].timeExpTASK = (*b).buffer[i].initTimeExpTASK;
    }
  }
}