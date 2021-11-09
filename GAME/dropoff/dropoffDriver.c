#include <stdio.h>
#include <stdlib.h>
#include "dropoff.h"

int main() {
    Stack bag; 
    LOCATION A, B, C, D, G; 
    List in_progress; 
    List todo; 
    ElTypeTASK task1, task2;
    task1.timeTASK = 1;
    task1.itemTASK = 'N';
    task1.pickUpTASK = 'A';
    task1.dropOffTASK = 'B';
    task2.timeTASK = 2;
    task2.itemTASK = 'H';
    task2.pickUpTASK = 'B';
    task2.dropOffTASK = 'G';
    CreateBAG(&bag);
    long money;
    money = 0;
    A = MakeLOCATION('A', 0, 0);
    B = MakeLOCATION('B', 4, 1);
    C = MakeLOCATION('C', 2, 4);
    D = MakeLOCATION('D', 3, 6);
    G = MakeLOCATION('G', 3, 6);
    CreateLINKEDLIST(&in_progress);
    CreateLINKEDLIST(&todo);
    insertFirstLINKEDLIST(&todo, task1);
    insertFirstLINKEDLIST(&todo, task2);
    displayLINKEDLIST(todo);
    pickUpAtloc(A, &bag, &in_progress, todo);
    pickUpAtloc(B, &bag, &in_progress, todo);
    displayInProgress(in_progress);
    dropOffAtloc(G, &bag, &in_progress, &todo, &money);
    displayInProgress(in_progress);
    printf("\n");
    displayLINKEDLIST(in_progress);
    
    printf("%lu", money);
    
}