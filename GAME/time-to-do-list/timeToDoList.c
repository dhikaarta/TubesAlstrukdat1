#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "timeToDoList.h"

void timeInitial(TIME *t)
{
    (*t).currentTime = 0;
    (*t).incTime = 1;
}

void updateTimeToDoList(QueueTASK *qTask, TIME *t, List *LinkedToDoList)
{
    (*t).currentTime = (*t).currentTime + (*t).incTime;
    
    
    while (HEAD_QUEUETASK(*qTask).timeTASK == (int)floor((*t).currentTime) && LengthQUEUETASK(*qTask) != 0)
    {
        ElTypeTASK val;
        DequeueQUEUETASK(qTask, &val);
        if (val.itemTASK == 'V'){
            int i;
            i = 0;
            Address p;
            p = *LinkedToDoList;
            while(ITEMTASK(p) == 'V' && p != NULL){
                p = NEXT(p);
                i++;
            }
            insertAtLINKEDLIST(LinkedToDoList, val, i);
        } else {
            insertLastLINKEDLIST(LinkedToDoList, val);
        }
    }
}

void displayCurrentTimeAndMoney(TIME t, long money)
{
    printf("Waktu: %.f\n", floor(t.currentTime));
    printf("Uang yang dimiliki: %ld Yen\n", money);
}