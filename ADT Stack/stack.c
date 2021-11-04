#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Konstruktor/Kreator *** */
void CreateSTACK(Stack *s)
{
    CURRENT_CAP_STACK(*s) = 3;
    IDX_TOP_STACK(*s) = IDX_UNDEF;
    
}

/* ************ Prototype ************ */
boolean IsEmptySTACK(Stack s)
{
    return IDX_TOP_STACK(s) == IDX_UNDEF;
}

boolean IsFullSTACK(Stack s)
{
    return IDX_TOP_STACK(s) == CURRENT_CAP_STACK(s) - 1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushSTACK(Stack *s, ElTypeTASK task)
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
    TOP_STACK(*s) = task;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopSTACK(Stack *s, ElTypeTASK *task)
{
    *task = TOP_STACK(*s);
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