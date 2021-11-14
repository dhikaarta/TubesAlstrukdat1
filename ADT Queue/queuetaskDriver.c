#include "queuetask.h"

int main()
{
    QueueTASK qt;
    ListTASK lt;
    CreateLISTTASK(&lt);
    ReadLISTTASK(&lt);
    lt = sortLISTTASK(lt);
    qt = CopyListToQueueTASK(lt);
    displayQUEUETASK(qt);
}