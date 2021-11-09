#include <stdio.h>
#include <stdlib.h>
#include "dropoff.h"
#include "../pickup/pickup.h"
#include "../in_progress/in_progress.h"
void processMoneyDropOff(ElTypeTASK task, long *money){
    if (task.itemTASK == 'N'){
        *money += 200;
    } else if (task.itemTASK == 'H' || task.itemTASK == 'P'){
        *money += 400;
    } 
}


void dropOffAtloc(LOCATION currentloc, Stack *bag, List *in_progress, List *todo, long *money){
    if (TOP_STACK(*bag).dropOffTASK != currentloc.A){
        printf("Tidak ada pesanan untuk di drop off!");
    } else {
        ElTypeTASK taskdone; 
        PopBAG(bag, &taskdone);
        
        int i; 
        i = indexOfLINKEDLIST(*in_progress, taskdone);
        deleteAtLINKEDLIST(in_progress, i, &taskdone);

        Address p;
        int j;
        p = FIRST(*todo); 
        j = 0;
        boolean found;
        found = false; 
        while (p != NULL && !found){
            if (INFO(p).dropOffTASK == currentloc.A) {
                found = true;
            } else {
                p = NEXT(p);
                j++;
            }
        }
        long oldmoney = *money;
        deleteAtLINKEDLIST(todo, j, &taskdone);
        processMoneyDropOff(taskdone, money);
        printf("Pesanan");
        processItemType(taskdone);
        printf("berhasil diantarkan\n");
        printf("Uang yang didapatkan: %lu Yen\n", *money - oldmoney);
    }
}