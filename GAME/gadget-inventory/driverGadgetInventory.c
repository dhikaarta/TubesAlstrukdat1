#include "gadgetInventory.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // DI MAIN
    long money = 0;
    ListGADGET listGadgetStore = initialGadgetStore();
    ListGADGET listInventory;
    CreateLISTGADGET(&listInventory);

    // IF command gadget
    gadgetStore(listGadgetStore, &listInventory, &money);

    // IF command Inventory
    useInventory(&listInventory);
}