/* HEADER BAG MEMANFAATKAN ADT STACK */

#ifndef BAG_H
#define BAG_H
#include "../boolean.h"
#include "stack.h"
#include "../ADT List Statis/listtask.h"
#include "../GAME/time-to-do-list/timeToDoList.h"
void CreateBAG(Stack*b);
/* Prosedur membuat bag dengan initial size 3 */ 
/* TopBag = IDX_UNDEF */

void PushBAG(Stack *b, ElTypeTASK task);
/* Menambahkan pesanan ke dalam bag */
/* Jika bag sudah penuh maka pesanan tidak akan ditambahkan */

void PopBAG(Stack *b, ElTypeTASK *task);
/* Spesifikasi sama dengan PopSTACK */


void UpdateBAGsize(Stack *b, int val);
/* Menambahkan kapasitas bag sebesar val  */

void UpdatePerishableInBag(Stack *b, TIME time);
/* Fungsi untuk mengurangi waktu sisa pada item bertipe perishable di bag */
/* Menghilangkan perishable item jika waktu sisa sama dengan nol */

#endif 