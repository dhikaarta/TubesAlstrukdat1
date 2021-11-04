#include <stdio.h>
#include <stdlib.h>
#include "timeToDoList.h"

void timeInitial(TIME *t)
{
    (*t).currentTime = 0;
    (*t).incTime = 1;
}

void updateTimeToDoList(ListTASK *l, TIME *t, List *LinkedToDoList)
{
    (*t).currentTime = (*t).currentTime + (*t).incTime;

    while ((*l).contents[0].timeTASK == (int)floor((*t).currentTime))
    {
        ElTypeTASK val;
        deleteAtLISTTASK(l, &val, 0);
        insertLastLINKEDLIST(LinkedToDoList, val);
    }
}

void displayCurrentTimeAndMoney(TIME t, long money)
{
    printf("Waktu: %.f\n", floor(t.currentTime));
    printf("Uang yang dimiliki: %ld Yen\n\n", money);
}