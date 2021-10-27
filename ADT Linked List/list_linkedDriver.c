#include <stdio.h>
#include "list_linked.h"

int main(){
    List l1, l2;  
    int x; 
    CreateLINKEDLIST(&l1);
    CreateLINKEDLIST(&l2);
    insertFirstLINKEDLIST(&l1, 3);
    if (isEmptyLINKEDLIST(l1)){
        printf("Empty\n");
    } else 
        printf("Not Empty\n");
    if (isEmptyLINKEDLIST(l2)){
        printf("Empty\n");
    } else 
        printf("Not Empty\n");
    
    insertLastLINKEDLIST(&l1, 4);
    insertLastLINKEDLIST(&l1, 5);
    insertLastLINKEDLIST(&l1, 6);
    insertFirstLINKEDLIST(&l2, 7);
    insertAtLINKEDLIST(&l2, 8, 1);
    insertAtLINKEDLIST(&l2, 9, 2);
    insertAtLINKEDLIST(&l2, 10, 3);

    displayLINKEDLIST(l1);
    printf("\n");
    displayLINKEDLIST(l2);
    printf("\n");

    setElmtLINKEDLIST(&l1, 1, 15);
    displayLINKEDLIST(l1);
    printf("\n");
    printf("%d\n", getElmtLINKEDLIST(l1,1));

    printf("%d\n", indexOfLINKEDLIST(l1, 15));

    deleteFirstLINKEDLIST(&l2, &x);
    printf("%d\n", x);
    displayLINKEDLIST(l2);
    printf("\n");
    deleteAtLINKEDLIST(&l2, 1, &x);
    printf("%d\n", x);
    displayLINKEDLIST(l2);
    printf("\n");
    deleteLastLINKEDLIST(&l2, &x);
    printf("%d\n", x);
    displayLINKEDLIST(l2);

    printf("\n%d\n", lengthLINKEDLIST(l1));
    displayLINKEDLIST(l1);
    printf("\n");
    displayLINKEDLIST(l2);
    printf("\n");
    displayLINKEDLIST(concatLINKEDLIST(l1,l2));
    printf("\n");
    return 0;
}