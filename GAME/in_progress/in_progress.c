#include <stdio.h>
#include "in_progress.h"
#include "../../ADT Linked List/list_linked.c"
#include "../../ADT Linked List/node.c"
void displayInProgress(List in_progress)
{
    if (isEmptyLINKEDLIST(in_progress))
    {
        printf("Nothing in In Progress List\n");
    } 
    else 
    {
        int i;
        Address p;
        printf("Pesanan yang sedang diantarkan:\n");
        i = 0;
        p = FIRST(in_progress);
        while (p != NULL)
        {
            printf("%d.", i+1);
            processItemType(INFO(p));
            printf("(Tujuan: %c", INFO(p).dropOffTASK);
            if (INFO(p).itemTASK == 'P')
            {
                printf(", sisa waktu: %.1f", INFO(p).timeExpTASK);
            }
            printf(")\n");
            i++;
            p = NEXT(p);
        }
    }
}

void processItemType(ElTypeTASK task){
    if (task.itemTASK == 'N')
    {
        printf(" Normal Item ");
    } 
    else if (task.itemTASK == 'H')
    {
        printf(" Heavy Item ");
    } 
    else 
    { /* Perishable */
        printf(" Perishable Item ");
    }
}

void updateProgressList(List *in_progress, TIME time){
    /* KAMUS LOKAL */
    Address p;
    int i;
    ElTypeTASK deltask;
    /* ALGORITMA */
    p = FIRST(*in_progress);
    i = 0;
    while (p != NULL){
        if (ITEMTASK(p) == 'P'){
            TIMEEXPTASK(p) -= time.incTime;
            if (TIMEEXPTASK(p) <= 0) {
                deleteAtLINKEDLIST(in_progress, i, &deltask);
            }
        }
        i++;
        p = NEXT(p);
    }
}