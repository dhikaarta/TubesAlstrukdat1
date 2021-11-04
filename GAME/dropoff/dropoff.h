#ifndef PICKUP_H
#define PICKUP_H
#include <stdio.h>
#include <stdlib.h>
#include "../../ADT Point/location.h"
#include "../../ADT Stack/bag.h"
#include "../../ADT Linked List/list_linked.h"
#include "dropoff.h"


void processMoneyDropOff(ElTypeTASK task, long *money);
/* Update money tergantung pada pesanan yang di drop off */

void dropOffAtloc(LOCATION currentloc, Stack *bag, List *in_progress, ListTASK *todo, long *money);
/* Prosedur dropoff pesanan pada currentloc, update in_progress list, update bag, dan update todo list */
/* I.S. bebas */
/* F.S. Jika pesanan pada top of bag sesuai, maka item akan di drop, bag akan di pop, in_progress akan terupdate, todo list terupdate, Nobita dapet duit */


#endif