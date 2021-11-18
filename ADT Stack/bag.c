#include "bag.h"


void CreateBAG(Stack *bag){
    CreateSTACK(bag);
}

void PushBAG(Stack *b, ElTypeTASK task){
    if (!IsFullSTACK(*b)){
        PushSTACK(b, task);
    }
}
void PopBAG(Stack *b, ElTypeTASK *task){
    PopSTACK(b, task);
}

void UpdateBAGsize(Stack *b, int val){
    if ((CURRENT_CAP_STACK(*b) + val) > MAX_CAPACITY_STACK){
        CURRENT_CAP_STACK(*b) = MAX_CAPACITY_STACK;
    } else {
        CURRENT_CAP_STACK(*b) += val;
    }
}

void UpdatePerishableInBag(Stack *b, TIME time){
    Stack btemp; 
    ElTypeTASK task;
    CreateBAG(&btemp);
    while (!IsEmptySTACK(*b)){
        PopBAG(b, &task);
        if (task.itemTASK == 'P'){
            task.timeExpTASK -= time.incTime;
            if (task.timeExpTASK <= 0 && !IsEmptySTACK(*b)) {
                PopBAG(b, &task);
            }
        }
        PushBAG(&btemp, task);
    }
    while (!IsEmptySTACK(btemp)){
        PopBAG(&btemp, &task);
        PushBAG(b, task);
    }
}