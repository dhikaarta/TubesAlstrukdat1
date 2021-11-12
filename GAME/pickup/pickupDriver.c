#include <stdio.h>
#include <stdlib.h>
#include "pickup.h"
#include "pickup.c"
int main() {
    Stack bag; 
    LOCATION A, B, C, D; 
    List in_progress; 
    List todo; 
    CreateBAG(&bag);
    A = MakeLOCATION('A', 0, 0);
    B = MakeLOCATION('B', 4, 1);
    C = MakeLOCATION('C', 2, 4);
    D = MakeLOCATION('D', 3, 6);
    CreateLINKEDLIST(&in_progress);
    CreateLINKEDLIST(&todo);
    ElTypeTASK t1, t2; 
    t1.pickUpTASK = 'A';
    t1.dropOffTASK = 'B';
    t2.pickUpTASK = 'C';
    t2.dropOffTASK = 'D';
    insertFirstLINKEDLIST(&todo, t1);
    insertFirstLINKEDLIST(&todo, t2);
    pickUpAtloc(A, &bag, &in_progress, todo);
    pickUpAtloc(B, &bag, &in_progress, todo);
    pickUpAtloc(C, &bag, &in_progress, todo);
    displayLINKEDLIST(in_progress);
}