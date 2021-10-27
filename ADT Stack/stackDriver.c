#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    Stack s;
    ElType val;
    CreateSTACK(&s);
    printf("Stack kosong: %d\n", IsEmptySTACK(s));
    printf("Stack penuh: %d\n", IsFullSTACK(s));

    PushSTACK(&s, 2);
    PushSTACK(&s, 3);
    PushSTACK(&s, 4);
    PushSTACK(&s, 1);
    PushSTACK(&s, 9);

    printf("Isi stack : ");
    while (!IsEmptySTACK(s))
    {
        PopSTACK(&s, &val);
        printf("%d ", val);
    }

    return 0;
}