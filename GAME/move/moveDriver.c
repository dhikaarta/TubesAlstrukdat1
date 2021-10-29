#include <stdio.h>
#include <stdlib.h>
#include "move.c"
#include "../../ADT matriks/matrix.c"

int main(){
    // MASIH SALAH
    Matrix adjacency;
    readMATRIX(&adjacency, 17,17);
    printf("\n");
    displayMATRIX(adjacency);
    return 0;
}