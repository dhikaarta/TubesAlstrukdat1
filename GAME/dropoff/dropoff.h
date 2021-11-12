#ifndef DROPOFF_H
#define DROPOFF_H
#include <stdio.h>
#include <stdlib.h>
#include "../../ADT Point/location.h"
#include "../../ADT Stack/bag.h"
#include "../../ADT Linked List/list_linked.h"
#include "../in_progress/in_progress.h"
#include "../pickup/pickup.h"
void processMoneyDropOff(ElTypeTASK task, long *money);
/* Update money tergantung pada pesanan yang di drop off */

void dropOffAtloc(LOCATION currentloc, Stack *bag, List *in_progress, long *money, int *successfulDroppedOff);
/* Prosedur dropoff pesanan pada currentloc, update in_progress list, update bag, dan update jumlah pesanan yang berhasil di drop off*/
/* I.S. currentloc, bag, in_progress, money, dan successfuldropped off terdefinisi */
/* F.S. Jika pesanan pada top of bag sesuai, maka item akan di drop, bag akan di pop, in_progress akan terupdate, jumlah pesanan berhasil diantar bertambah satu, Nobita dapet duit */


#endif