#include "bag.c"
#include "bag.h"
#include <stdio.h>


int main(){
    Stack b; 
    CreateBAG(&b);
    TIME time;
    time.incTime = 1.5;
    ElTypeTASK task1, task2, task3;
    task1.itemTASK = 'P';
    task2.itemTASK = 'P';
    task3.itemTASK = 'P';
    task1.timeExpTASK = 3;
    task2.timeExpTASK = 2; 
    task3.timeExpTASK = 1;
    PushBAG(&b, task1);
    PushBAG(&b, task2);
    PushBAG(&b, task3);
    UpdatePerishableInBag(&b, time);
    UpdatePerishableInBag(&b, time);
    UpdatePerishableInBag(&b, time);
    
    printf("%.1f\n", TOP_STACK(b).timeExpTASK);
}

/* gcc bagDriver.c stack.c */