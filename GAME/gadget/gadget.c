#include <stdio.h>
#include <stdlib.h>
#include "gadget.h"

void KainPembungkusWaktu(Stack b) {
  int i, idx;
  boolean found = false;
  for (i = IDX_TOP_STACK(b); i >= 0; i--) {
    if (b.buffer[i].itemTASK == 'P') {
      found = true;
      idx = i;
      break;
    }
  }
  if (found == true) {
    // Mengembalikan time perishable item ke waktu semula
    b.buffer[idx].timeExpTASK = b.buffer[idx].initTimeExpTASK;
  }
}

void SenterPembesar(Stack *b) {
  int newCap = CURRENT_CAP_STACK(*b) * 2;
  UpdateBAGsize(b, newCap);
}

void PintuKemanaSaja(TIME *t) {
  // Kondisi move ke lokasi tertentu
  (*t).incTime = 0;
}

void MesinWaktu(TIME *t) {
  if ((*t).currentTime > 50) {
    (*t).currentTime -= 50;
  } else {
    (*t).currentTime = 0;
  }
}