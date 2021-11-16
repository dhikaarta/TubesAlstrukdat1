#include <stdio.h>
#include "in_progress.h"

/* gcc in_progressDriver.c in_progress.c "../time-to-do-list/timeToDoList.c" "../../ADT Linked List/list_linked.c" "../../ADT Point/location.c" "../../ADT Linked List/node.c" "../../ADT Queue/queuetask.c"*/

int main(){
    List in_progress; 
    TIME time; 
    time.incTime = 1;
    ElTypeTASK task1, task2, task3;
    CreateLINKEDLIST(&in_progress);
    task1.timeTASK = 1;
    task1.itemTASK = 'P';
    task1.pickUpTASK = 'A';
    task1.dropOffTASK = 'H';
    task1.timeExpTASK = 3;
    task2.timeTASK = 2;
    task2.itemTASK = 'P';
    task2.pickUpTASK = 'B';
    task2.dropOffTASK = 'G';
    task2.timeExpTASK = 4;

    task3.timeTASK = 2;
    task3.itemTASK = 'N';
    task3.pickUpTASK = 'C';
    task3.dropOffTASK = 'D';
    insertFirstLINKEDLIST(&in_progress, task1);
    insertFirstLINKEDLIST(&in_progress, task2);
    insertFirstLINKEDLIST(&in_progress, task3);
    updateProgressList(&in_progress, time);
    updateProgressList(&in_progress, time);
    updateProgressList(&in_progress, time);
    updateProgressList(&in_progress, time);
    updateProgressList(&in_progress, time);
    displayInProgress(in_progress);

} 