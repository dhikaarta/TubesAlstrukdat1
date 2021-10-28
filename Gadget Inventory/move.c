#include "../ADT List Statis/listgadget.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long money = 2000;
    printf("Uang Anda Sekarang: %ld Yen\n", money);
    printf("Gadget yang tersedia:\n");

    ListGADGET listGadgetStore;
    CreateLISTGADGET(&listGadgetStore);
    insertLastLISTGADGET(&listGadgetStore, 1, 800);
    insertLastLISTGADGET(&listGadgetStore, 2, 1200);
    insertLastLISTGADGET(&listGadgetStore, 3, 1500);
    insertLastLISTGADGET(&listGadgetStore, 4, 3000);
    displayLISTGADGETSTORE(listGadgetStore);
    printf("Gadget mana yang ingin dibeli? (ketik 0 jika ingin kembali)\n");

    int id;
    printf("ENTER COMMAND: ");
    scanf("%d", &id);
    while (id < 0 || id > 4 || money < listGadgetStore.contents[id - 1].priceGADGET)
    {
        if (id < 0 || id > 4)
        {
            printf("Input yang dimasukkan masih salah, coba lagi !!\n");
        }
        else if (money < listGadgetStore.contents[id - 1].priceGADGET)
        {
            printf("Uang tidak cukup untuk membeli gadget!\n");
        }
        printf("ENTER COMMAND: ");
        scanf("%d", &id);
    }
    money -= money < listGadgetStore.contents[id - 1].priceGADGET;
    ListGADGET listInventory;
    CreateLISTGADGET(&listInventory);
    insertLastLISTGADGET(&listInventory, id, listGadgetStore.contents[id - 1].priceGADGET);
    displayLISTINVENTORY(listInventory);
}