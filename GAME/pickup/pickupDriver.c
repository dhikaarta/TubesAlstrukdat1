#include <stdio.h>
#include <stdlib.h>
#include "pickup.h"
#include "pickup.c"
/* Compile: gcc pickupDriver.c "../../ADT Stack/stack.c" "../../ADT Stack/bag.c" "../in_progress/in_progress.c" "../../ADT Point/location.c" */
int main() {
    Stack bag; 
    LOCATION A, B, C, D; 
    List in_progress; 
    List todo; 
    CreateBAG(&bag);
    TIME time;
    A = MakeLOCATION('A', 0, 0);
    B = MakeLOCATION('B', 4, 1);
    C = MakeLOCATION('C', 2, 4);
    D = MakeLOCATION('D', 3, 6);
    CreateLINKEDLIST(&in_progress);
    CreateLINKEDLIST(&todo);
    ElTypeTASK t1, t2, t3, t4, test;
    t1.timeTASK = 1;
    t1.itemTASK = 'N'; 
    t1.pickUpTASK = 'A';
    t1.dropOffTASK = 'B';

    t2.timeTASK = 2;
    t2.itemTASK = 'H';
    t2.pickUpTASK = 'C';
    t2.dropOffTASK = 'D';

    t3.timeTASK = 3;
    t3.itemTASK = 'N';
    t3.pickUpTASK = 'E';
    t3.dropOffTASK = 'F';

    t4.timeTASK = 4;
    t4.itemTASK = 'N';
    t4.pickUpTASK = 'D';
    t4.dropOffTASK = 'E';
    insertFirstLINKEDLIST(&todo, t1);
    insertFirstLINKEDLIST(&todo, t2);
    insertFirstLINKEDLIST(&todo, t3);
    insertFirstLINKEDLIST(&todo, t4);
    displayLINKEDLIST(in_progress);
    displayLINKEDLIST(todo);
    pickUpAtloc(B, &bag, &in_progress, &todo, &time);
    pickUpAtloc(C, &bag, &in_progress, &todo, &time);
    PopBAG(&bag, &test);
    displayLINKEDLIST(in_progress);
    displayLINKEDLIST(todo);
    printf("\n%c", test.dropOffTASK);
}