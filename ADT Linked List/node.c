/* Modul Node */
/* Implementasi Node */

#include "node.h"
#include <stdlib.h>

Address newNode(ElTypeTASK task) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = task;
        NEXT(p) = NULL;
    }
    return p;
}