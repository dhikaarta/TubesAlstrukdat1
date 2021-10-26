#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    Stack s;
    ElType val;
    CreateStack(&s);
    printf("Stack kosong: %d\n", StackIsEmpty(s));
    printf("Stack penuh: %d\n", StackIsFull(s));

    StackPush(&s, 2);
    StackPush(&s, 3);
    StackPush(&s, 4);
    StackPush(&s, 1);
    StackPush(&s, 9);

    printf("Isi stack : ");
    while (!StackIsEmpty(s))
    {
        StackPop(&s, &val);
        printf("%d ", val);
    }

    return 0;
}