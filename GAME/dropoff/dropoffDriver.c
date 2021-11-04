#include <stdio.h>
#include <stdlib.h>
#include "dropoff.h"
#include "dropoff.c"
int main() {
    Stack bag; 
    LOCATION A, B, C, D; 
    List in_progress; 
    ListTASK todo; 
    CreateBAG(&bag);
    long money;
    money = 0;
    A = MakeLOCATION('A', 0, 0);
    B = MakeLOCATION('B', 4, 1);
    C = MakeLOCATION('C', 2, 4);
    D = MakeLOCATION('D', 3, 6);
    CreateLINKEDLIST(&in_progress);
    CreateLISTTASK(&todo);
    ReadLISTTASK(&todo);
    pickUpAtloc(A, &bag, &in_progress, todo);
    pickUpAtloc(B, &bag, &in_progress, todo);
    dropOffAtloc(A, &bag, &in_progress, &todo, &money);
    printf("\n");
    displayLINKEDLIST(in_progress);
    displayLISTTASK(todo);
    printf("\n%lu", money);
    
}