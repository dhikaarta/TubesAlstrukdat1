#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Konstruktor/Kreator *** */
void CreateSTACK(Stack *s)
{
    IDX_TOP_STACK(*s) = IDX_UNDEF;
}

/* ************ Prototype ************ */
boolean IsEmptySTACK(Stack s)
{
    return IDX_TOP_STACK(s) == IDX_UNDEF;
}

boolean IsFullSTACK(Stack s)
{
    return IDX_TOP_STACK(s) == CAPACITY_STACK - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushSTACK(Stack *s, ElType val)
{
    if (IsEmptySTACK(*s))
    {
        IDX_TOP_STACK(*s) = 0;
    }
    else
    {
        IDX_TOP_STACK(*s)
        ++;
    }
    TOP_STACK(*s) = val;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopSTACK(Stack *s, ElType *val)
{
    *val = TOP_STACK(*s);
    if (IDX_TOP_STACK(*s) == 0)
    {
        IDX_TOP_STACK(*s) = IDX_UNDEF;
    }
    else
    {
        IDX_TOP_STACK(*s)
        --;
    }
}