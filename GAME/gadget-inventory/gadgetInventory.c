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
        printf("ENTER COMMAND (BUY): ");
        scanf("%d", &id);

        // Update Inventory
        if (id < 1 || id > 4)
        {
            printf("Input yang dimasukkan salah!!\n\n");
        }
        else if ((*money < listGadgetStore.contents[id - 1].priceGADGET))
        {
            printf("Uang tidak cukup untuk membeli gadget!\n\n");
        }
        else if (id > 0)
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
    printf("\nENTER COMMAND (Inventory): ");
    scanf("%d", &idInventory);
    // Asumsi input pengguna selalu benar
    if (isEmptyLISTGADGET(*listInventory))
    {
        printf("Tidak ada gadget yang dapat digunakan!! Anda tidak memiliki gadget apapun pada Inventory\n\n");
    }

    else if ((*listInventory).contents[idInventory - 1].idGADGET == VAL_UNDEF)
    {
        printf("Tidak ada gadget yang dapat digunakan!!\n");
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