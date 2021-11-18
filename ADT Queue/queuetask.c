#include <stdio.h>
#include <stdlib.h>
#include "queuetask.h"
#include "../ADT mesin karakter & kata/wordmachine.h"
#include "../ADT mesin karakter & kata/charmachine.h"

void CreateQUEUETASK(QueueTASK *qt, int CAPACITY_QUEUETASK)
{
    BUFFER_QUEUETASK(*qt) = (ElTypeTASK *)malloc(CAPACITY_QUEUETASK * sizeof(ElTypeTASK));
    IDX_HEAD_QUEUETASK(*qt) = IDX_UNDEF;
    IDX_TAIL_QUEUETASK(*qt) = IDX_UNDEF;
    CAP_QUEUETASK(*qt) = CAPACITY_QUEUETASK;
}

void dealocateQUEUETASK(QueueTASK *qt)
{
    free(BUFFER_QUEUETASK(*qt));
    IDX_HEAD_QUEUETASK(*qt) = IDX_UNDEF;
    IDX_TAIL_QUEUETASK(*qt) = IDX_UNDEF;
}

boolean IsEmptyQUEUETASK(QueueTASK qt)
{
    return ((IDX_HEAD_QUEUETASK(qt) == IDX_UNDEF) && (IDX_TAIL_QUEUETASK(qt) == IDX_UNDEF));
}

boolean IsFullQUEUETASK(QueueTASK qt)
{
    return (LengthQUEUETASK(qt) == CAP_QUEUETASK(qt));
}

int LengthQUEUETASK(QueueTASK qt)
{
    int length;
    if (IsEmptyQUEUETASK(qt))
    {
        length = 0;
    }
    else
    {
        length = (IDX_TAIL_QUEUETASK(qt) - IDX_HEAD_QUEUETASK(qt) + 1);
    }
    return length;
}

void ReadQUEUETASK(QueueTASK *qt, int nTask)
{
    int i;
    for (i = 0; i < nTask; i++)
    {
        ElTypeTASK task;
        scanf("%d %c %c %c", &(task.timeTASK), &(task.pickUpTASK), &(task.dropOffTASK), &(task.itemTASK));
        if (task.itemTASK == 'P')
        {
            scanf(" %f", &(task.timeExpTASK));
        }
        EnqueueQUEUETASK(qt, task);
    }
}

void ReadQUEUETASKfile(QueueTASK *qt)
{
    /* BACA 1 ELEMEN TYPE DARI FILE */
    ElTypeTASK task;
    advWORDfile();
    task.timeTASK = atoi(currentWordfile.contents);
    advWORDfile();
    task.pickUpTASK = currentWordfile.contents[0];
    advWORDfile();
    task.dropOffTASK = currentWordfile.contents[0];
    advWORDfile();
    task.itemTASK = currentWordfile.contents[0];
    if (task.itemTASK == 'P')
    {
        advWORDfile();
        task.timeExpTASK = atoi(currentWordfile.contents);
    }
    EnqueueQUEUETASK(qt, task);
}

QueueTASK CopyListToQueueTASK(ListTASK l)
{
    int i;
    QueueTASK q;
    CreateQUEUETASK(&q, l.Neff);
    for (i = 0; i < l.Neff; i++)
    {
        EnqueueQUEUETASK(&q, l.contents[i]);
    }
    return q;
}

void EnqueueQUEUETASK(QueueTASK *qt, ElTypeTASK task)
{

    if (IsEmptyQUEUETASK(*qt))
    {
        IDX_HEAD_QUEUETASK(*qt) = 0;
        IDX_TAIL_QUEUETASK(*qt) = 0;
    }
    else
    {
        if (IDX_TAIL_QUEUETASK(*qt) == CAP_QUEUETASK(*qt) - 1)
        {
            int i;
            for (i = IDX_HEAD_QUEUETASK(*qt); i <= IDX_TAIL_QUEUETASK(*qt); i++)
            {
                qt->bufferQUEUETASK[i - IDX_HEAD_QUEUETASK(*qt)] = qt->bufferQUEUETASK[i];
            }
            IDX_TAIL_QUEUETASK(*qt) -= IDX_HEAD_QUEUETASK(*qt);
            IDX_HEAD_QUEUETASK(*qt) = 0;
        }
        IDX_TAIL_QUEUETASK(*qt)
        ++;
    }

    TAIL_QUEUETASK(*qt) = task;
}
void DequeueQUEUETASK(QueueTASK *qt, ElTypeTASK *task)
{
    *task = HEAD_QUEUETASK(*qt);
    if (IDX_HEAD_QUEUETASK(*qt) == IDX_TAIL_QUEUETASK(*qt))
    {
        IDX_HEAD_QUEUETASK(*qt) = IDX_UNDEF;
        IDX_TAIL_QUEUETASK(*qt) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD_QUEUETASK(*qt)
        ++;
    }
}

void displayQUEUETASK(QueueTASK qt)
{
    if (IsEmptyQUEUETASK(qt))
    {
        printf("Tidak ada pesanan");
    }
    else
    {
        int i;
        for (i = IDX_HEAD_QUEUETASK(qt); i <= IDX_TAIL_QUEUETASK(qt); i++)
        {
            ElTypeTASK task;
            DequeueQUEUETASK(&qt, &task);
            printf("%d. Time Task = %d\n", i + 1, task.timeTASK);
            printf("   Pick Up Point = %c\n", task.pickUpTASK);
            printf("   Drop Off Point = %c\n", task.dropOffTASK);
            printf("   Item Task = %c\n", task.itemTASK);
            if (task.itemTASK == 'P')
            {
                printf("   Expired Time = %f\n", task.timeExpTASK);
            }
        }
    }
}