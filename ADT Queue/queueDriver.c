#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
    Queue q;
    ElType val;
    CreateQUEUE(&q);
    printf("Queue kosong: %d\n", IsEmptyQUEUE(q));
    printf("Queue penuh: %d\n", IsFullQUEUE(q));

    EnqueueQUEUE(&q, 5);
    EnqueueQUEUE(&q, 3);
    EnqueueQUEUE(&q, 4);
    EnqueueQUEUE(&q, 1);
    EnqueueQUEUE(&q, 2);
    printf("Queue sebelum di dequeue (length = %d) ", LengthQUEUE(q));
    displayQUEUE(q);

    DequeueQUEUE(&q, &val);
    DequeueQUEUE(&q, &val);
    printf("\nQueue setelah di dequeue (length = %d) ", LengthQUEUE(q));
    displayQUEUE(q);
    return 0;
}