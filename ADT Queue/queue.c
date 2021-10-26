#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q)
{
    QUEUE_IDX_HEAD(*q) = IDX_UNDEF;
    QUEUE_IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean QueueIsEmpty(Queue q)
{
    return ((QUEUE_IDX_HEAD(q) == IDX_UNDEF) && (QUEUE_IDX_TAIL(q) == IDX_UNDEF));
}
boolean QueueIsFull(Queue q)
{
    return ((QUEUE_IDX_HEAD(q) == 0) && (QUEUE_IDX_TAIL(q) == QUEUE_CAPACITY - 1));
}
int QueueLength(Queue q)
{
    if (QueueIsEmpty(q))
    {
        return 0;
    }
    else
    {
        return (QUEUE_IDX_TAIL(q) - QUEUE_IDX_HEAD(q) + 1);
    }
}

/* *** Primitif Add/Delete *** */
void QueueEnqueue(Queue *q, ElType val)
{
    if (QueueIsEmpty(*q))
    {
        QUEUE_IDX_HEAD(*q) = 0;
        QUEUE_IDX_TAIL(*q) = 0;
    }
    else
    {
        if (QUEUE_IDX_TAIL(*q) == QUEUE_CAPACITY - 1)
        {
            for (int i = QUEUE_IDX_HEAD(*q); i <= QUEUE_IDX_TAIL(*q); i++)
            {
                (*q).buffer[i - QUEUE_IDX_HEAD(*q)] = (*q).buffer[i];
            }
            QUEUE_IDX_TAIL(*q) -= QUEUE_IDX_HEAD(*q);
            QUEUE_IDX_HEAD(*q) = 0;
        }
        QUEUE_IDX_TAIL(*q) += 1;
    }
    QUEUE_TAIL(*q) = val;
}

void QueueDequeue(Queue *q, ElType *val)
{
    *val = QUEUE_HEAD(*q);
    if (QueueLength(*q) == 1)
    {
        QUEUE_IDX_HEAD(*q) = IDX_UNDEF;
        QUEUE_IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        QUEUE_IDX_HEAD(*q)
        ++;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q)
{
    printf("[");
    if (!QueueIsEmpty(q))
    {
        for (int i = QUEUE_IDX_HEAD(q); i < QUEUE_IDX_TAIL(q); i++)
        {
            printf("%d,", q.buffer[i]);
        }
        printf("%d]", q.buffer[QUEUE_IDX_TAIL(q)]);
    }
    else
    {
        printf("]");
    }
}