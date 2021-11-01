#include "queuetask.h"
#include "queuetask.c"

int main(){
    QueueTASK qt; 
    int nTask; 
    scanf("%d\n", &nTask);
    CreateQUEUETASK(&qt, nTask);
    ReadQUEUETASK(&qt, nTask);
    displayQUEUETASK(qt);
}