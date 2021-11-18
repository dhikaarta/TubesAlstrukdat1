#include "gadgetInventory.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    TIME t;
    Stack b;
    List inprogress;
    CreateBAG(&b);
    CreateLINKEDLIST(inprogress);
    // DI MAIN
    long money = 0;
    ListGADGET listGadgetStore = initialGadgetStore();
    ListGADGET listInventory;
    CreateLISTGADGET(&listInventory);

    // IF command gadget
    gadgetStore(listGadgetStore, &listInventory, &money);

    // IF command Inventory
    useInventory(&listInventory, &b, &t, &inprogress);
}