#include <stdio.h>
#include "in_progress.h"
#include "in_progress.c"
#include "../../ADT Point/location.c"

int main(){
    List in_progress; 
    ElTypeTASK task1, task2;
    CreateLINKEDLIST(&in_progress);
    task1.timeTASK = 1;
    task1.itemTASK = 'N';
    task1.pickUpTASK = 'A';
    task1.dropOffTASK = 'H';

    task2.timeTASK = 2;
    task2.itemTASK = 'H';
    task2.pickUpTASK = 'B';
    task2.dropOffTASK = 'G';
    insertFirstLINKEDLIST(&in_progress, task1);
    insertFirstLINKEDLIST(&in_progress, task2);
    displayInProgress(in_progress);
}   