#include <stdio.h>
#include <stdlib.h>
#include "timeToDoList.h"

int main()
{
    // Di Mainn
    ListTASK l, l2;
    CreateLISTTASK(&l);
    CreateLISTTASK(&l2);
    ReadLISTTASK(&l);
    l2 = sortLISTTASK(l);

    // TIME
    TIME time;
    timeInitial(&time);
    long money = 20;

    // Setiap melakukan MOVE:
    updateTimeToDoList(&l2, &time);
    displayCurrentTimeAndMoney(time, money);
    updateTimeToDoList(&l2, &time);
    displayCurrentTimeAndMoney(time, money);
    updateTimeToDoList(&l2, &time);
    displayCurrentTimeAndMoney(time, money);
    updateTimeToDoList(&l2, &time);
    displayCurrentTimeAndMoney(time, money);
    updateTimeToDoList(&l2, &time);
    displayCurrentTimeAndMoney(time, money);
    updateTimeToDoList(&l2, &time);
    displayCurrentTimeAndMoney(time, money);
    //displayCurrentTimeAndMoney(time, money);

    return 0;
}