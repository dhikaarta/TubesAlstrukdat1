#include <stdio.h>
#include <stdlib.h>
#include "dropoff.h"
#include "../pickup/pickup.h"
#include "../ability/ability.h"
#include "../in_progress/in_progress.h"

void processMoneyDropOff(ElTypeTASK task, long *money){
    if (task.itemTASK == 'N'){
        *money += 200;
    } else if (task.itemTASK == 'H' || task.itemTASK == 'P'){
        *money += 400;
    } else if (task.itemTASK == 'V'){
        *money += 600;
    }
}


void dropOffAtloc(LOCATION currentloc, Stack *bag, List *in_progress, long *money, int *successfulDroppedOff, TIME *t){
    if (TOP_STACK(*bag).dropOffTASK != currentloc.A){
        printf("Tidak ada pesanan untuk di drop off!");
    } else {
        ElTypeTASK taskdone; 
        PopBAG(bag, &taskdone);
        *successfulDroppedOff += 1;

        // INCTIME - 1 JIKA BERHASIL DROP OFF HEAVY ITEM
        if (taskdone.itemTASK == 'H') {
            (*t).incTime -= 1;
        }

        // MENGAKTIFKAN SPEED BOOST JIKA BERHASIL MENGANTARKAN HEAVY ITEM
        extern int moveFreq;
        if (taskdone.itemTASK == 'H') {
            printf("Ability Speed Boost telah aktif\n");
            (*t).incTime = 0.5;
        }

        // MENDAPATKAN ABILITY INCREASE CAPACITY
        if (taskdone.itemTASK == 'P') {
            increaseCapacity(bag);
        }

        // MENDAPATKAN ABILITY RETURN TO SENDER
        extern int rtsCounter;
        if (taskdone.itemTASK == 'V') {
            rtsCounter += 1;
        }
        
        int i; 
        i = indexOfLINKEDLIST(*in_progress, taskdone);
        deleteAtLINKEDLIST(in_progress, i, &taskdone);
        long oldmoney = *money;
        processMoneyDropOff(taskdone, money);
        printf("Pesanan");
        processItemType(taskdone);
        printf("berhasil diantarkan\n");
        printf("Uang yang didapatkan: %lu Yen\n", *money - oldmoney);
    }
}