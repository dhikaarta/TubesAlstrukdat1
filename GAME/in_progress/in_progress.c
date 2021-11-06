#include <stdio.h>
#include "in_progress.h"
#include "../../ADT Linked List/list_linked.c"
#include "../../ADT Linked List/node.c"
void displayInProgress(List in_progress)
{
    if (isEmptyLINKEDLIST(in_progress))
    {
        printf("Nothing in In Progress List");
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
            printf("(Tujuan: %c)\n", INFO(p).dropOffTASK);
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