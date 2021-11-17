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

        // MENGAKTIFKAN SPEED BOOST JIKA BERHASIL MENGANTARKAN HEAVY ITEM
        extern int moveFreq;
        if (taskdone.itemTASK == 'H') {
            printf("Ability Speed Boost telah aktif\n");
            (*t).incTime = 0.5;
            printf("testing purposes 1\n");
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
        printf("testing purposes 2\n");
        i = indexOfLINKEDLIST(*in_progress, taskdone);
        printf("%i\n", i);
        printf("testing purposes 3\n");
        deleteAtLINKEDLIST(in_progress, i, &taskdone);
        printf("testing purposes 4\n");
        long oldmoney = *money;
        printf("testing purposes 5\n");
        processMoneyDropOff(taskdone, money);
        printf("testing purposes 6\n");
        printf("Pesanan");
        printf("testing purposes 7\n");
        processItemType(taskdone);
        printf("testing purposes 8\n");
        printf("berhasil diantarkan\n");
        printf("testing purposes 9\n");
        printf("Uang yang didapatkan: %lu Yen\n", *money - oldmoney);
        printf("testing purposes 10\n");
    }
}