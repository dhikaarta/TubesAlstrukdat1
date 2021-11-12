#include <stdio.h>
#include <stdlib.h>
#include "../GAME/map/map.c"
#include "../ADT list statis/listtask.h"
#include "../GAME/pcolor/pcolor.c"
#include "../GAME/help/help.c"
#include "../GAME/gadget-inventory/gadgetInventory.h"
#include "../GAME/time-to-do-list/timeToDoList.h"
#include "../GAME/in_progress/in_progress.h"
#include "../GAME/pickup/pickup.h"
#include "../GAME/dropoff/dropoff.h"

Word kataNewGame = {"NEWGAME", 7};
Word kataExit = {"EXIT", 4};
Word kataMove = {"MOVE", 4};
Word kataPickUp = {"PICK_UP", 7};
Word kataDropOff = {"DROP_OFF", 8};
Word kataMap = {"MAP", 3};
Word kataToDo = {"TO_DO", 5};
Word kataInProgress = {"IN_PROGRESS", 11};
Word kataBuy = {"BUY", 3};
Word kataInventory = {"INVENTORY", 9};
Word kataHelp = {"HELP", 4};

LOCATION nobita;
LOCATION pickUp;
LOCATION dropOff;

int moveFreq = 0;

Word getInput()
{
    startWORD();
    Word kataInput = currentWord;
    advWORD();
    while (!endWord)
    {

        int j;
        for (j = 0; j < currentWord.length; j++)
        {
            kataInput.contents[j + kataInput.length] = currentWord.contents[j];
        }
        kataInput.length += currentWord.length;
        advWORD();
    }
    return kataInput;
}
/* fungsi buat dapetin input dari user pake mesin kata*/

int main()
{
    boolean flag = true;
    int N, M, i_headquarters, j_headquarters, L, P;

    while (flag)
    {

        printf("this is start\n");
        Word kataInput = getInput();

        if (isKataEqual(kataInput, kataNewGame))
        {
            printf("Silahkan masukkan file konfigurasi : ");
            kataInput = getInput();

            startWORDfile(kataInput.contents);
            printf("%s\n", currentWordfile.contents);
            N = atoi(currentWordfile.contents);
            advWORDfile();
            printf("%s\n", currentWordfile.contents);
            M = atoi(currentWordfile.contents);
            advWORDfile();
            i_headquarters = atoi(currentWordfile.contents);
            advWORDfile();
            j_headquarters = atoi(currentWordfile.contents);
            advWORDfile();
            L = atoi(currentWordfile.contents);

            // MEMBUAT ARRAY OF LOC UNTUK HEADQUARTERS DAN TITIK
            LOCATION *arrayLoc = makeArrayOfLOCATION(L, i_headquarters, j_headquarters);
            // MENGETES ARRAY OF LOC
            displaylistLOCATION(arrayLoc, L);
            // MENGINISIASI MAP BERTIPE MATRIX
            Matrix MAP;
            // MEMBUAT MAP
            CreateMAP(N, M, &MAP);
            // MEMBACA ELEMEN DARI MAP DENGAN MENANDAI TITIK TITIK YANG TELAH DIINPUT
            readMAPConfiguration(&MAP, arrayLoc, L);

            // MEMBUAT MATRIX ADJ
            Matrix Madj = makeMatrixAdj(L);
            // MENAMPILAN MATRIX ADJ
            displayMATRIX(Madj);
            printf("\n");

            // NOBITA PERTAMA KALI DI SET DI HEADQUARTERS
            nobita = getLocHQ(arrayLoc);

            // Untuk List Task
            advWORDfile();
            P = atoi(currentWordfile.contents);
            ListTASK lTask;
            ReadLISTTASKfile(&lTask, P);
            lTask = sortLISTTASK(lTask);
            displayLISTTASK(lTask);
            printf("\n");

            // Untuk inisialisasi GADGET dan INVENTORY
            long money = 20000;
            ListGADGET listGadgetStore = initialGadgetStore();
            ListGADGET listInventory;
            CreateLISTGADGET(&listInventory);

            //Inisialisasi ToDoList
            List LinkedToDoList;
            CreateLINKEDLIST(&LinkedToDoList);
            List inProgressList;
            CreateLINKEDLIST(&inProgressList);

            // Inisialisasi waktu
            TIME time;
            timeInitial(&time);

            // Inisialisasi Tas
            Stack b;
            CreateBAG(&b);

            int successfulDropOff = 0;


            printf("ENTER COMMAND : ");
            while (true)
            {
                kataInput = getInput();
                printf("Mobita berada di posisi ");
                TulisLOCATION(nobita);
                printf("\n");
                displayCurrentTimeAndMoney(time, money);

                if (isKataEqual(kataInput, kataMove))
                {
                    printf("itu masuk sini \n");
                    int i;
                    // INISIASI LOKASI YANG AKAN DIPILIH
                    int lokasiDipilih;
                    do
                    {
                        // INISIASI JUMLAH LOKASI YANG DAPAT DICAPAI
                        int nPossibleMoves;
                        // MENGINISIASI ARRAY OF LOCATION DARI JUMLAH LOKASI YANG DAPAT DICAPAI
                        LOCATION *arrayPosMove;
                        // MEMBUAT ARRAY OF LOCATION MANA SAJA YANG DAPAT DICAPAI
                        arrayPosMove = makeArrayOfPossibleMoves(Madj, arrayLoc, nobita, L, &nPossibleMoves);
                        printf("\nPosisi yang dapat dicapai:\n");
                        // MENAMPILKAN KE USER AGAR DAPAT DIPILIH
                        for (i = 0; i < nPossibleMoves; i++)
                        {
                            printf("%d. %c (%d,%d)\n", i + 1, CHAR(arrayPosMove[i]), LOC_X(arrayPosMove[i]), LOC_Y(arrayPosMove[i]));
                        }
                        // MENAMPILKAN PETA DENGAN WARNA
                        displayMAPColor(MAP, nobita, arrayPosMove, nPossibleMoves, LinkedToDoList, inProgressList);
                        // MENERIMA INPUTAN USER UNTUK LOKASI YANG DIPILIH
                        printf("\nPosisi yang dipilih? (ketik 0 jika ingin kembali)\n");
                        printf("\n");
                        printf("ENTER COMMAND: ");
                        kataInput = getInput();
                        lokasiDipilih = atoi(kataInput.contents);
                        
                        printf("\nNobita sekarang berada di titik ");
                        // JIKA TIDAK TERJADI PERPINDAHAN MAKA MENGGUNAKAN LOKASI SEBELUMNYA
                        if (lokasiDipilih != 0)
                        {
                            // time.incTime = 1;
                            if (time.incTime == 0.5) {
                                moveFreq++;
                                speedBoost(&time, &moveFreq);
                            }
                            nobita = arrayPosMove[lokasiDipilih - 1];
                            //updateisi todolist
                            updateTimeToDoList(&lTask, &time, &LinkedToDoList);
                        }
                        else
                        {
                            nobita = nobita;
                        }
                        TulisLOCATION(nobita);
                        printf("!");
                        printf("\n");
                        printf("%i\n", lokasiDipilih);

                    } while (lokasiDipilih != 0);
                    printf("tes\n");
                }
                else if (isKataEqual(kataInput, kataPickUp))
                {
                    pickUpAtloc(nobita, &b, &inProgressList, LinkedToDoList, &time);
                }
                else if (isKataEqual(kataInput, kataDropOff))
                {
                    dropOffAtloc(nobita, &b, &inProgressList, &LinkedToDoList, &money, &time);
                }
                else if (isKataEqual(kataInput, kataMap))
                {
                    int nPossibleMoves;
                    LOCATION *arrayPosMove;
                    arrayPosMove = makeArrayOfPossibleMoves(Madj, arrayLoc, nobita, L, &nPossibleMoves);
                    displayMAPColor(MAP, nobita, arrayPosMove, nPossibleMoves, LinkedToDoList, inProgressList);
                    printf("\n");
                }
                else if (isKataEqual(kataInput, kataToDo))
                {
                    displayToDoList(LinkedToDoList);
                }
                else if (isKataEqual(kataInput, kataInProgress))
                {
                    displayInProgress(inProgressList);
                }
                else if (isKataEqual(kataInput, kataBuy))
                {
                    if (LOC_X(nobita) == i_headquarters && LOC_Y(nobita) == j_headquarters)
                    {
                        gadgetStore(listGadgetStore, &listInventory, &money);
                    }
                    else
                    {
                        printf("Anda hanya bisa membeli gadget di Headquarters!!\n");
                    }
                }
                else if (isKataEqual(kataInput, kataInventory))
                {
                    useInventory(&listInventory, &b, &time);
                }
                else if (isKataEqual(kataInput, kataHelp))
                {
                    printHelp();
                }
                else if (isEmptyLISTTASK(lTask) && isEmptyLINKEDLIST(LinkedToDoList) && LOC_X(nobita) == i_headquarters && LOC_Y(nobita) == j_headquarters)
                {
                    printf("Game Selesai !\n");
                    printf("Waktu yang dilampaui : %i\n", time);

                    break;
                }
                else
                {
                    printf("command tidak valid ! kembali ke menu awal\n");
                }
                printf("ENTER COMMAND : ");
            }
        }
        else if (isKataEqual(kataInput, kataExit))
        {
            printf("EXIT GAME");
            flag = false;
        }
        else
        {
            printf("INPUT TIDAK VALID, TERMINASI PROGRAM");
            flag = false;
        }
    }
}