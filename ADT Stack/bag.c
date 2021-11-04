#include "bag.h"
#include "stack.c"
#include "../ADT List Statis/listtask.c"

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
