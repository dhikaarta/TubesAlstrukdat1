#include <stdio.h>
#include <stdlib.h>
#include "listtask.h"

int main()
{
    ElTypeTASK val;
    ListTASK l, l2;
    CreateLISTTASK(&l);
    CreateLISTTASK(&l2);
    ReadLISTTASK(&l);
    displayLISTTASK(l);
    l2 = sortLISTTASK(l);
    displayLISTTASK(l2);

    return 0;
}