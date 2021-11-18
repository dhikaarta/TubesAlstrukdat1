#ifndef PICKUP_H
#define PICKUP_H
#include <stdio.h>
#include <stdlib.h>
#include "../../ADT Point/location.h"
#include "../../ADT Stack/bag.h"
#include "../../ADT Linked List/list_linked.h"
#include "../ability/ability.h"
#include "../in_progress/in_progress.h"
#include "../ability/ability.h"
void pickUpAtloc(LOCATION currentloc, Stack *bag, List *in_progress, List *todo, TIME *t);
/* Prosedur mengambil pesanan pada currentloc, update in_progress list dan update bag*/
/* I.S. bebas */
/* F.S. Jika tas penuh atau tidak ada pesanan maka akan menampilkan pesan
        Jika tidak keduanya maka bag dan in progress list akan terupdate  */
#endif