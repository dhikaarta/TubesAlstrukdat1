#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    Stack s;
    ElTypeTASK val;
    CreateSTACK(&s);
    printf("Stack kosong: %d\n", IsEmptySTACK(s));
    printf("Stack penuh: %d\n", IsFullSTACK(s));
    val.timeTASK = 1;
    val.itemTASK = 'N'; 
    val.pickUpTASK = 'A';
    val.dropOffTASK = 'B';
    PushSTACK(&s, val);

    printf("Isi stack : ");
    while (!IsEmptySTACK(s))
    {
        PopSTACK(&s, &val);
        printf("%d ", val);
    }

    return 0;
}