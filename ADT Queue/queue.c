#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQUEUE(Queue *q)
{
    IDX_HEAD_QUEUE(*q) = IDX_UNDEF;
    IDX_TAIL_QUEUE(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean IsEmptyQUEUE(Queue q)
{
    return ((IDX_HEAD_QUEUE(q) == IDX_UNDEF) && (IDX_TAIL_QUEUE(q) == IDX_UNDEF));
}
boolean IsFullQUEUE(Queue q)
{
    return ((IDX_HEAD_QUEUE(q) == 0) && (IDX_TAIL_QUEUE(q) == CAPACITY_QUEUE - 1));
}
int LengthQUEUE(Queue q)
{
    if (IsEmptyQUEUE(q))
    {
        return 0;
    }
    else
    {
        return (IDX_TAIL_QUEUE(q) - IDX_HEAD_QUEUE(q) + 1);
    }
}

/* *** Primitif Add/Delete *** */
void EnqueueQUEUE(Queue *q, ElType val)
{
    if (IsEmptyQUEUE(*q))
    {
        IDX_HEAD_QUEUE(*q) = 0;
        IDX_TAIL_QUEUE(*q) = 0;
    }
    else
    {
        if (IDX_TAIL_QUEUE(*q) == CAPACITY_QUEUE - 1)
        {
            for (int i = IDX_HEAD_QUEUE(*q); i <= IDX_TAIL_QUEUE(*q); i++)
            {
                (*q).buffer[i - IDX_HEAD_QUEUE(*q)] = (*q).buffer[i];
            }
            IDX_TAIL_QUEUE(*q) -= IDX_HEAD_QUEUE(*q);
            IDX_HEAD_QUEUE(*q) = 0;
        }
        IDX_TAIL_QUEUE(*q) += 1;
    }
    TAIL_QUEUE(*q) = val;
}

void DequeueQUEUE(Queue *q, ElType *val)
{
    *val = HEAD_QUEUE(*q);
    if (LengthQUEUE(*q) == 1)
    {
        IDX_HEAD_QUEUE(*q) = IDX_UNDEF;
        IDX_TAIL_QUEUE(*q) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD_QUEUE(*q)
        ++;
    }
}

/* *** Display Queue *** */
void displayQUEUE(Queue q)
{
    printf("[");
    if (!IsEmptyQUEUE(q))
    {
        for (int i = IDX_HEAD_QUEUE(q); i < IDX_TAIL_QUEUE(q); i++)
        {
            printf("%d,", q.buffer[i]);
        }
        printf("%d]", q.buffer[IDX_TAIL_QUEUE(q)]);
    }
    else
    {
        printf("]");
    }
}