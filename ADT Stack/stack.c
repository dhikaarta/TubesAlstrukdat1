#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s)
{
    STACK_IDX_TOP(*s) = IDX_UNDEF;
}

/* ************ Prototype ************ */
boolean StackIsEmpty(Stack s)
{
    return STACK_IDX_TOP(s) == IDX_UNDEF;
}

boolean StackIsFull(Stack s)
{
    return STACK_IDX_TOP(s) == STACK_CAPACITY - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void StackPush(Stack *s, ElType val)
{
    if (StackIsEmpty(*s))
    {
        STACK_IDX_TOP(*s) = 0;
    }
    else
    {
        STACK_IDX_TOP(*s)
        ++;
    }
    STACK_TOP(*s) = val;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void StackPop(Stack *s, ElType *val)
{
    *val = STACK_TOP(*s);
    if (STACK_IDX_TOP(*s) == 0)
    {
        STACK_IDX_TOP(*s) = IDX_UNDEF;
    }
    else
    {
        STACK_IDX_TOP(*s)
        --;
    }
}