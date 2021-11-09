#include <stdio.h>
#include <stdlib.h>
#include "ability.h"

void speedBoost(TIME *t, int moveFreq) {
  if (moveFreq != 10) {
    (*t).incTime = 0.5;
  } else if (moveFreq == 10) {
    (*t).incTime = 1;
    moveFreq = 0;
  }
}

void increaseCapacity(Stack *b) {
  UpdateBAGsize(b, 1);
}