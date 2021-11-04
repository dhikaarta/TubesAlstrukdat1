#include <stdio.h>
#include <stdlib.h>
#include "timeToDoList.h"

int main()
{
    // Di Mainn (ini udah sama dhika)
    ListTASK l, l2;
    CreateLISTTASK(&l);
    CreateLISTTASK(&l2);
    ReadLISTTASK(&l);
    l2 = sortLISTTASK(l);

    // Inisialisasi di MAIN
    List LinkedToDoList;
    CreateLINKEDLIST(&LinkedToDoList);

    // TIME
    TIME time;
    timeInitial(&time);
    long money = 20;

    // Setiap melakukan MOVE:
    updateTimeToDoList(&l2, &time, &LinkedToDoList);
    updateTimeToDoList(&l2, &time, &LinkedToDoList);
    updateTimeToDoList(&l2, &time, &LinkedToDoList);
    displayCurrentTimeAndMoney(time, money);
    displayLINKEDLIST(LinkedToDoList);

    //displayCurrentTimeAndMoney(time, money);

    return 0;
}