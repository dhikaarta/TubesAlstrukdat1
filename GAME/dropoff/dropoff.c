#include <stdio.h>
#include <stdlib.h>
#include "dropoff.h"
#include "../pickup/pickup.c"

void processMoneyDropOff(ElTypeTASK task, long *money){
    if (task.itemTASK == 'N'){
        *money += 200;
    } else if (task.itemTASK == 'H' || task.itemTASK == 'P'){
        *money += 400;
    } 
}


void dropOffAtloc(LOCATION currentloc, Stack *bag, List *in_progress, ListTASK *todo, long *money){
    if (TOP_STACK(*bag).dropOffTASK != currentloc.A){
        printf("Tidak ada pesanan untuk di drop off!");
    } else {
        ElTypeTASK taskdone; 
        PopBAG(bag, &taskdone);
        int i; 
        i = indexOfLINKEDLIST(*in_progress, taskdone);
        deleteAtLINKEDLIST(in_progress, i, &taskdone);
        int j;
        j = 0; 
        boolean found;
        found = false; 
        while (j < lengthLISTTASK(*todo) && !found){
            if (todo->contents[j].dropOffTASK == currentloc.A) {
                found = true;
            } else {
                j++;
            }
        }
        deleteAtLISTTASK(todo, &taskdone, j);
        printf("%d", taskdone.timeTASK);
        processMoneyDropOff(taskdone, money);
    }
}