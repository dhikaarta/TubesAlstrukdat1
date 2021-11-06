#include <stdio.h>
#include <stdlib.h>
#include "listtask.h"
#include "../ADT matriks/matrix.h"
#include "../ADT mesin karakter & kata/wordmachine.h"
//#include "../ADT matriks/matrix.c"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateLISTTASK(ListTASK *l)
{
    (*l).Neff = 0;
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
            (*l).contents[i].initTimeExpTASK = (*l).contents[i].timeExpTASK;
        }
    }
    (*l).Neff = nTask;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */

void ReadLISTTASKfile(ListTASK *l, int nTask)
{
    for (int i = 0; i < nTask; i++)
    {
        advWORDfile();
        (*l).contents[i].timeTASK = atoi(currentWordfile.contents);
        advWORDfile();
        (*l).contents[i].pickUpTASK = currentWordfile.contents[0];
        advWORDfile();
        (*l).contents[i].dropOffTASK = currentWordfile.contents[0];
        advWORDfile();
        (*l).contents[i].itemTASK = currentWordfile.contents[0];
        if ((*l).contents[i].itemTASK == 'P')
        {
            advWORDfile();
            (*l).contents[i].timeExpTASK = atoi(currentWordfile.contents);
            (*l).contents[i].initTimeExpTASK = (*l).contents[i].timeExpTASK;
        }
        (*l).Neff = nTask;
    }
}

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
        for (int i = 0; i < l.Neff; i++)
        {
            printf("%d. Time Task = %d\n", i + 1, l.contents[i].timeTASK);
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
void deleteAtLISTTASK(ListTASK *l, ElTypeTASK *val, int idx)
{
    *val = (*l).contents[idx];
    if (lengthLISTTASK(*l) > 1)
    {
        for (int i = idx; i < (*l).Neff - 1; i++)
        {
            (*l).contents[i] = (*l).contents[i + 1];
        }
    }
    (*l).Neff--;
}

ListTASK sortLISTTASK(ListTASK l)
{
    ListTASK l2;
    CreateLISTTASK(&l2);
    int idx2 = 0;
    int idxMin = 0;
    int n = l.Neff;
    ElTypeTASK val;
    for (int i = 0; i < n; i++)
    {
        int minVal = l.contents[0].timeTASK;
        int idxMin = 0;
        for (int j = 0; j < l.Neff; j++)
        {
            if (l.contents[j].timeTASK < minVal)
            {
                minVal = l.contents[j].timeTASK;
                idxMin = j;
            }
        }
        deleteAtLISTTASK(&l, &val, idxMin);
        l2.contents[idx2] = val;
        l2.Neff++;
        idx2++;
    }
    return l2;
}