#include <stdio.h>
#include <stdlib.h>
#include "listtask.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateLISTTASK(ListTASK *l)
{
    (*l).Neff = 0;
    (*l).idxHead = IDX_UNDEF;
}

void ReadLISTTASK(ListTASK *l)
{
    int nTask;
    scanf("%d", &nTask);
    for (int i = 0; i < nTask; i++)
    {
        scanf("%d %c %c %c", &((*l).contents[i].timeTASK), &((*l).contents[i].pickUpTASK), &((*l).contents[i].dropOffTASK), &((*l).contents[i].itemTASK));
        if ((*l).contents[i].itemTASK == 'P')
        {
            scanf(" %d", &(*l).contents[i].timeExpTASK);
        }
    }
    (*l).Neff = nTask;
    (*l).idxHead = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthLISTTASK(ListTASK l)
{
    return l.Neff;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyLISTTASK(ListTASK l)
{
    return lengthLISTTASK(l) == 0;
}

void displayLISTTASK(ListTASK l)
{
    if (isEmptyLISTTASK(l))
    {
        printf("KOSOONGGG");
    }
    else
    {
        for (int i = l.idxHead; i < l.Neff + l.idxHead; i++)
        {
            printf("%d. Time Task = %d\n", i + 1 - l.idxHead, l.contents[i].timeTASK);
            printf("   Pick Up Point = %c\n", l.contents[i].pickUpTASK);
            printf("   Drop Off Point = %c\n", l.contents[i].dropOffTASK);
            printf("   Item Task = %c\n", l.contents[i].itemTASK);
            if (l.contents[i].itemTASK == 'P')
            {
                printf("   Expired Time = %d\n", l.contents[i].timeExpTASK);
            }
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void deleteFirstLISTTASK(ListTASK *l)
{
    (*l).idxHead++;
    (*l).Neff--;
}

void sortLISTTASK(ListTASK *l)
{
}