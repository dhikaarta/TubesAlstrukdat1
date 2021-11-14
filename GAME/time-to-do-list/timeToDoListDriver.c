#include <stdio.h>
#include <stdlib.h>
#include "timeToDoList.h"

int main()
{
    // Di Mainn (ini udah sama dhika)
    ListTASK l;
    CreateLISTTASK(&l);
    ReadLISTTASK(&l);
    l = sortLISTTASK(l);

    QueueTASK(qTask);
    CreateQUEUETASK(&qTask, l.Neff);
    qTask = CopyListToQueueTASK(l);

    // Inisialisasi di MAIN
    List LinkedToDoList;
    CreateLINKEDLIST(&LinkedToDoList);

    // TIME
    TIME time;
    timeInitial(&time);
    long money = 20;

    // Setiap melakukan MOVE:
    updateTimeToDoList(&qTask, &time, &LinkedToDoList);
    updateTimeToDoList(&qTask, &time, &LinkedToDoList);
    updateTimeToDoList(&qTask, &time, &LinkedToDoList);
    updateTimeToDoList(&qTask, &time, &LinkedToDoList);
    displayCurrentTimeAndMoney(time, money);
    displayLINKEDLIST(LinkedToDoList);

    //displayCurrentTimeAndMoney(time, money);

    return 0;
}