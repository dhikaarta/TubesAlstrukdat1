#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include "../ADT List Statis/listtask.h"
typedef struct node* Address;
typedef struct node {
    ElTypeTASK info;
    Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

Address newNode(ElTypeTASK val);


#endif