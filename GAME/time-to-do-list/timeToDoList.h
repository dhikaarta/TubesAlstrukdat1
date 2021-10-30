#include "../../ADT List Statis/listtask.h"
#include <math.h>

#ifndef TIME_TO_DO_LIST
#define TIME_TO_DO_LIST

typedef struct
{
    float currentTime;
    float incTime;
} TIME;

void timeInitial(TIME *t);

void updateTimeToDoList(ListTASK *l, TIME *t);

void displayCurrentTimeAndMoney(TIME t, long money);

#endif