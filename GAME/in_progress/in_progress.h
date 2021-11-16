#ifndef IN_PROGRESS_H
#define IN_PROGRESS_H
#include <stdio.h>
#include "../../ADT Linked List/list_linked.h"
#include "../time-to-do-list/timeToDoList.h"
#include "../../ADT Point/location.h"

void displayInProgress(List in_progress);
/* Display in progress list secara terbalik ()*/

void processItemType(ElTypeTASK task);
/* Prosedur menampilkan jenis item dalam kata */

void updateProgressList(List *in_progress, TIME time);
/* Prosedur untuk mengupdate expired time pada pesanan bertipe perishable di in progress list */

#endif