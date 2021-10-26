#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    Queue q;
    ElType val;
    CreateQueue(&q);
    printf("Queue kosong: %d\n", QueueIsEmpty(q));
    printf("Queue penuh: %d\n", QueueIsFull(q));

    QueueEnqueue(&q, 5);
    QueueEnqueue(&q, 3);
    QueueEnqueue(&q, 4);
    QueueEnqueue(&q, 1);
    QueueEnqueue(&q, 2);
    printf("Queue sebelum di dequeue (length = %d) ", QueueLength(q));
    displayQueue(q);

    QueueDequeue(&q, &val);
    QueueDequeue(&q, &val);
    printf("\nQueue setelah di dequeue (length = %d) ", QueueLength(q));
    displayQueue(q);
    return 0;
}