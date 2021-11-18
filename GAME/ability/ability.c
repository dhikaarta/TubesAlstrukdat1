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
      printf("Anda telah bergerak sebanyak 10 kali ! Ability Speed Boost hangus!\n");
      (*t).incTime = 1;
      *moveFreq = 0;
    }
  }
}

void increaseCapacity(Stack *b) {
  UpdateBAGsize(b, 1);
}

void returnToSender(Stack *b, List *l, List *inProgress, int *rtsCounter, TIME *t, boolean *senterPengecilAktif) {
  if (*rtsCounter > 0) {
    ElTypeTASK x,deleted;
    if (TOP_STACK(*b).itemTASK != 'V') {
      // Item di atas tas dikembalikan ke To Do List di urutan terakhir
      PopBAG(b, &x);
      x.timeExpTASK = x.initTimeExpTASK;
      insertLastLINKEDLIST(l, x);
      deleteFirstLINKEDLIST(inProgress, &deleted);

      // Time limit yang terdapat pada pesanan dengan Perishable Item akan di-reset sebelum dikembalikan
      /*if (TOP_STACK(*b).itemTASK == 'P') {
        x.timeExpTASK = x.initTimeExpTASK;
        PopBAG(b, &x);
        insertLastLINKEDLIST(l,x);
      }*/
      }
      else 
      { 
      printf("Anda tidak bisa melakukan return pada VIP item !\n");
      }
      // JIKA RETURN HEAVY ITEM, INCTIME - 1
      if (TOP_STACK(*b).itemTASK == 'H' && *senterPengecilAktif == false) {
        (*t).incTime -= 1;
      } else if (TOP_STACK(*b).itemTASK == 'H' && *senterPengecilAktif == true) {
        *senterPengecilAktif = false;
      }
      printf("ITEM BERHASIL DIKEMBALIKAN");
      *rtsCounter -= 1;
    }
    else
    {
      printf("Mobita tidak memiliki ability Return to Sender\n");
    }
    
  }
  
