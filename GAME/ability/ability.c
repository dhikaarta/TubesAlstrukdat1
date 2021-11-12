#include <stdio.h>
#include <stdlib.h>
#include "ability.h"

void speedBoost(TIME *t, int *moveFreq) {
  if (*moveFreq <= 10) {
    (*t).incTime = 0.5;
  } else {
    (*t).incTime = 1;
    *moveFreq = 0;
    printf("Ability Speed Boost telah hilang\n");
  }
}

void increaseCapacity(Stack *b) {
  UpdateBAGsize(b, 1);
}