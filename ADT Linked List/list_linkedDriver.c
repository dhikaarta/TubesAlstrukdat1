#include <stdio.h>
#include "list_linked.h"
#include "list_linked.c"
#include "node.c"

int main(){
    ElTypeTASK nTask;
    nTask.timeTASK = 5;
    nTask.pickUpTASK = 'B';
    nTask.dropOffTASK = 'A';
    nTask.itemTASK = 'N';

    List l1, l2;   
    CreateLINKEDLIST(&l1);
    CreateLINKEDLIST(&l2);
    insertLastLINKEDLIST(&l1, nTask);
    displayLINKEDLIST(l1);
    displayLINKEDLIST(l2);
    return 0;
}