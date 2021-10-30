#include "gadgetInventory.h"
#include <stdio.h>
#include <stdlib.h>

ListGADGET initialGadgetStore()
{
    ListGADGET listGadgetStore;
    CreateLISTGADGET(&listGadgetStore);
    insertLastLISTGADGET(&listGadgetStore, 1, 800);
    insertLastLISTGADGET(&listGadgetStore, 2, 1200);
    insertLastLISTGADGET(&listGadgetStore, 3, 1500);
    insertLastLISTGADGET(&listGadgetStore, 4, 3000);
    return listGadgetStore;
}

void gadgetStore(ListGADGET listGadgetStore, ListGADGET *listInventory, long *money)
{
    if (isFullLISTGADGET(*listInventory))
    {
        printf("Inventory sudah penuh, tidak bisa membeli gadget lagi\n");
    }
    else
    {
        printf("Uang Anda Sekarang: %ld Yen\n", *money);
        printf("Gadget yang tersedia:\n");
        displayLISTGADGETSTORE(listGadgetStore);
        printf("Gadget mana yang ingin dibeli? (ketik 0 jika ingin kembali)\n");
        int id;
        printf("ENTER COMMAND: ");
        scanf("%d", &id);
        while ((id < 0 || id > 4 || *money < listGadgetStore.contents[id - 1].priceGADGET) && id != 0)
        {
            if (id < 0 || id > 4)
            {
                printf("Input yang dimasukkan masih salah, coba lagi !!\n\n");
            }
            else if ((*money < listGadgetStore.contents[id - 1].priceGADGET))
            {
                printf("Uang tidak cukup untuk membeli gadget!\n\n");
            }
            printf("ENTER COMMAND: ");
            scanf("%d", &id);
        }

        // Update Inventory
        if (id > 0)
        {
            *money -= listGadgetStore.contents[id - 1].priceGADGET;
            insertLastLISTGADGET(listInventory, id, listGadgetStore.contents[id - 1].priceGADGET);
            if (id == 1)
            {
                printf("Kain Pembungkus Waktu berhasil dibeli\n");
            }
            else if (id == 2)
            {
                printf("Senter Pembesar Waktu berhasil dibeli\n");
            }
            else if (id == 3)
            {
                printf("Pintu Kemana Saja berhasil dibeli\n");
            }
            else if (id == 4)
            {
                printf("Mesin Waktu berhasil dibeli\n");
            }
            printf("Uang anda sekarang: %ld Yen\n\n", *money);
        }
    }
}

void useInventory(ListGADGET *listInventory)
{
    printf("\nGadget mana yang ingin digunakan? (Ketik 0 jika ingin kembali)\n");
    int idInventory, idGadget;
    displayLISTINVENTORY(*listInventory);
    printf("\nENTER COMMAND: ");
    scanf("%d", &idInventory);
    // Asumsi input pengguna selalu benar
    while (((*listInventory).contents[idInventory - 1].idGADGET == VAL_UNDEF || idInventory > 5) && idInventory != 0)
    {
        printf("Tidak ada gadget yang dapat digunakan!!");
        if (isEmptyLISTGADGET(*listInventory))
        {
            printf(" Anda tidak memiliki gadget apapun pada Inventory\n\n");
            idInventory = 0;
        }
        else
        {
            printf(" Coba lagi..\n");
            printf("\nENTER COMMAND: ");
            scanf("%d", &idInventory);
        }
    }
    if (idInventory > 0)
    {
        idGadget = (*listInventory).contents[idInventory - 1].idGADGET;
        deleteLISTGADGET(listInventory, idInventory);
        if (idGadget == 1)
        {
            printf("Kain Pembungkus Waktu berhasil digunakan!!\n\n");
            /* Fungsi aktivasi Kain Pembungkus Waktu */
        }
        else if (idGadget == 2)
        {
            printf("Senter Pembesar berhasil digunakan!!\n\n");
            /* Fungsi aktivasi Senter Pembesar */
        }
        else if (idGadget == 3)
        {
            printf("Pintu Kemana Saja berhasil digunakan!!\n\n");
            /* Fungsi aktivasi Pintu Kemana Saja */
        }
        else if (idGadget == 4)
        {
            printf("Mesin Waktu berhasil digunakan!!\n\n");
            /* Fungsi aktivasi Mesin Waktu */
        }
    }
}