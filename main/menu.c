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
#include "../ADT Queue/queuetask.h"

Word kataNewGame = {"NEWGAME", 7};
Word kataLoad = {"LOADGAME",8};
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
Word kataSaveGame = {"SAVE_GAME", 9};
Word kataReturn = {"RETURN", 6};

LOCATION nobita;
LOCATION pickUp;
LOCATION dropOff;
long money;
FILE *fptr;

int moveFreq = 0;
int rtsCounter = 0;
boolean senterPengecilAktif = false;

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
    //membaca file dri ascii art
        FILE *fptrascii;

        char c;
        // Open file
        fptrascii = fopen("ascii1.txt", "r");
        if (fptrascii == NULL)
        {
            printf("Cannot open file \n");
            exit(0);
        }

        // Read contents from file
        c = fgetc(fptrascii);
        while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(fptrascii);
        }

        fclose(fptrascii);
    while (flag)
    {
        //printf("this is start\n");
        Word kataInput = getInput();

        if (isKataEqual(kataInput, kataNewGame))
        {
            printf("Silahkan masukkan file konfigurasi : ");
            kataInput = getInput();

            startWORDfile(kataInput.contents);
            //printf("%s\n", currentWordfile.contents);
            N = atoi(currentWordfile.contents);
            advWORDfile();
            //printf("%s\n", currentWordfile.contents);
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
            //displaylistLOCATION(arrayLoc, L);
            // MENGINISIASI MAP BERTIPE MATRIX
            Matrix MAP;
            // MEMBUAT MAP
            CreateMAP(N, M, &MAP);
            // MEMBACA ELEMEN DARI MAP DENGAN MENANDAI TITIK TITIK YANG TELAH DIINPUT
            readMAPConfiguration(&MAP, arrayLoc, L + 1);

            // MEMBUAT MATRIX ADJ
            Matrix Madj = makeMatrixAdj(L);
            // MENAMPILAN MATRIX ADJ
            //displayMATRIX(Madj);

            // NOBITA PERTAMA KALI DI SET DI HEADQUARTERS
            nobita = getLocHQ(arrayLoc);

            // Untuk List Task
            advWORDfile();
            P = atoi(currentWordfile.contents);
            ListTASK lTask;
            ReadLISTTASKfile(&lTask, P);
            lTask = sortLISTTASK(lTask);

            // Memindahkan isi List Task ke Queue Task
            QueueTASK qTask;
            CreateQUEUETASK(&qTask, lTask.Neff);
            qTask = CopyListToQueueTASK(lTask);

            // Untuk inisialisasi GADGET dan INVENTORY
            money = 20000;
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

            while (!IsEmptyQUEUETASK(qTask) || !isEmptyLINKEDLIST(LinkedToDoList) || !isEmptyLINKEDLIST(inProgressList) || LOC_X(nobita) != i_headquarters || LOC_Y(nobita) != j_headquarters)
            {
                printf("\nMobita berada di posisi ");
                TulisLOCATION(nobita);
                printf("\n");
                displayCurrentTimeAndMoney(time, money);
                printf("\nENTER COMMAND : ");
                kataInput = getInput();
                printf("\n");
            
                if (isKataEqual(kataInput, kataMove))
                {
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
                        displayMAPColor(MAP, nobita, arrayPosMove, nPossibleMoves, LinkedToDoList, b);
                        // MENERIMA INPUTAN USER UNTUK LOKASI YANG DIPILIH
                        printf("\nPosisi yang dipilih? (ketik 0 jika ingin kembali)\n");
                        printf("\n");
                        printf("ENTER COMMAND: ");
                        kataInput = getInput();
                        lokasiDipilih = atoi(kataInput.contents);

                        // JIKA TIDAK TERJADI PERPINDAHAN MAKA MENGGUNAKAN LOKASI SEBELUMNYA
                        if(lokasiDipilih > nPossibleMoves)
                        {
                            printf("Tidak ada inputan tersebut ! kembali ke menu utama\n");
                        }
                        else if (lokasiDipilih != 0)
                        {
                            printf("\nMobita sekarang berada di titik ");
                            if (time.incTime == 0.5)
                            {
                                moveFreq++;
                                speedBoost(&time, &moveFreq, b);
                            }
                            updateTimeToDoList(&qTask, &time, &LinkedToDoList);
                            updateProgressList(&inProgressList, time);
                            UpdatePerishableInBag(&b, time);
                            if (time.incTime == 0)
                            {
                                time.incTime = 1;
                                int i;
                                for (i = IDX_TOP_STACK(b); i >= 0; i--) {
                                    if (b.buffer[i].itemTASK == 'H') {
                                    time.incTime += 1;
                                    }
                                }
                            }
                            nobita = arrayPosMove[lokasiDipilih - 1];
                            //updateisi todolist
                            TulisLOCATION(nobita);
                            printf("!");
                            printf("\n");
                            printf("Waktu: %.f\n", floor(time.currentTime));
                        }
                        else
                        {
                            nobita = nobita;
                        }
                    } while (lokasiDipilih != 0);
                    
                }
                else if (isKataEqual(kataInput, kataPickUp))
                {
                    pickUpAtloc(nobita, &b, &inProgressList, &LinkedToDoList, &time);
                }
                else if (isKataEqual(kataInput, kataDropOff))
                {
                    dropOffAtloc(nobita, &b, &inProgressList, &money, &successfulDropOff, &time);
                }
                else if (isKataEqual(kataInput, kataMap))
                {
                    int nPossibleMoves;
                    LOCATION *arrayPosMove;
                    arrayPosMove = makeArrayOfPossibleMoves(Madj, arrayLoc, nobita, L, &nPossibleMoves);
                    displayMAPColor(MAP, nobita, arrayPosMove, nPossibleMoves, LinkedToDoList, b);
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
                else if (isKataEqual(kataInput, kataReturn))
                {
                    returnToSender(&b, &LinkedToDoList,&inProgressList, &rtsCounter, &time, &senterPengecilAktif);
                }
                else if (isKataEqual(kataInput, kataInventory))
                {
                    useInventory(&listInventory, &b, &time);
                }
                else if (isKataEqual(kataInput, kataHelp))
                {
                    printHelp();
                }
                else if(isKataEqual(kataInput, kataSaveGame))
                {
                    int i,j;
                    Address p;
                    char namaFile[32] = "../GAME/SAVE/";
                    printf("Masukkan nama file save : ");
                    kataInput = getInput();printf("\n");
    
                    strcat(namaFile, kataInput.contents);
                    
                    fptr = fopen(namaFile,"w");
                    fprintf(fptr, "%i %i\n", N,M);
                    fprintf(fptr, "%i %i\n%i\n", i_headquarters,j_headquarters,L);
                    for(i = 1; i<=L; i++)
                    {
                        fprintf(fptr, "%c %i %i\n", CHAR(arrayLoc[i]),LOC_X(arrayLoc[i]), LOC_Y(arrayLoc[i]));
                    }
                    for(i= 0; i <ROWSMATRIX(Madj); i++){
                        for (j = 0; j<COLSMATRIX(Madj); j++){
                            if (j == getLastIdxRowMATRIX(Madj)){
                                fprintf(fptr,"%d", ELMTMATRIX(Madj,i,j));
                            }else {
                                fprintf(fptr,"%d ", ELMTMATRIX(Madj,i,j));
                            }
                        }

                        if (i < getLastIdxRowMATRIX(Madj)){
                        fprintf(fptr,"\n");
                        } 

                    }

                    fprintf(fptr,"\n%i\n",LengthQUEUETASK(qTask));
                    for (i = IDX_HEAD_QUEUETASK(qTask); i < IDX_HEAD_QUEUETASK(qTask) + LengthQUEUETASK(qTask); i++)
                    {
                        if(qTask.bufferQUEUETASK[i].itemTASK =='P')
                        {
                             fprintf(fptr,"%d %c %c %c %f\n",  qTask.bufferQUEUETASK[i].timeTASK, qTask.bufferQUEUETASK[i].pickUpTASK, qTask.bufferQUEUETASK[i].dropOffTASK, qTask.bufferQUEUETASK[i].itemTASK, qTask.bufferQUEUETASK[i].timeExpTASK);
                        }
                        else{
                            fprintf(fptr,"%d %c %c %c\n",  qTask.bufferQUEUETASK[i].timeTASK, qTask.bufferQUEUETASK[i].pickUpTASK, qTask.bufferQUEUETASK[i].dropOffTASK, qTask.bufferQUEUETASK[i].itemTASK);
                        }
                        
                    }

                    fprintf(fptr,"%f %f\n", time.currentTime, time.incTime);
                    fprintf(fptr,"%c %d %d\n", CHAR(nobita), LOC_X(nobita), LOC_Y(nobita));
                    fprintf(fptr,"%li\n", money);
                    fprintf(fptr, "%i\n", listInventory.Neff);
                    for(i =0; i < listInventory.Neff;i++)
                    {
                        fprintf(fptr,"%i %li\n", listInventory.contents[i].idGADGET,listInventory.contents[i].priceGADGET);
                    }
                    fprintf(fptr, "%i\n", lengthLINKEDLIST(LinkedToDoList));
                   
                    p = FIRST(LinkedToDoList);
                    while(p!= NULL)
                    {
                        if(ITEMTASK(p) == 'P')
                        {
                            fprintf(fptr,"%d %c %c %c %f %f\n", TIMETASK(p),PICKUPTASK(p),DROPOFFTASK(p), ITEMTASK(p), TIMEEXPTASK(p),INITTIMEEXPTASK(p));
                        }
                        else
                        {
                            fprintf(fptr,"%d %c %c %c\n", TIMETASK(p),PICKUPTASK(p),DROPOFFTASK(p), ITEMTASK(p));
                        }
                        p = NEXT(p);
                    }
                    fprintf(fptr, "%i\n", b.currentCAPACITYSTACK);
                    fprintf(fptr, "%i\n", lengthLINKEDLIST(inProgressList));
                    p = FIRST(inProgressList);
                    while(p!= NULL)
                    {
                        if(ITEMTASK(p) == 'P')
                        {
                            fprintf(fptr,"%d %c %c %c %f %f\n", TIMETASK(p),PICKUPTASK(p),DROPOFFTASK(p), ITEMTASK(p), TIMEEXPTASK(p), INITTIMEEXPTASK(p));
                        }
                        else
                        {
                            fprintf(fptr,"%d %c %c %c\n", TIMETASK(p),PICKUPTASK(p),DROPOFFTASK(p), ITEMTASK(p));
                        }
                        p = NEXT(p);
                    }
                    fprintf(fptr,"%i\n", moveFreq);
                    fprintf(fptr, "%i\n", successfulDropOff);
                    fprintf(fptr,"%i\n",  rtsCounter);
                    fprintf(fptr, "%c\n", senterPengecilAktif);



                    fclose(fptr);     
                }
                else if (isKataEqual(kataInput,kataExit))
                {

                    break;
                }
                else
                {
                    printf("command tidak valid ! kembali ke menu awal\n");
                }
            }
            printf("Game Selesai !\n");
            printf("Waktu yang dilampaui : %f sekon\n", floor(time.currentTime));
            printf("Pesanan yang berhasil diantar : %i", successfulDropOff);
            //membaca file dri ascii art
                FILE *fptrascii2;

                char c;
                // Open file
                fptrascii2 = fopen("ascii2.txt", "r");
                if (fptrascii2 == NULL)
                {
                    printf("Cannot open file \n");
                    exit(0);
                }

                // Read contents from file
                c = fgetc(fptrascii2);
                while (c != EOF)
                {
                    printf ("%c", c);
                    c = fgetc(fptrascii2);
                }

                fclose(fptrascii2);
            flag = false;
        }
        //Kode load game
        else if(isKataEqual(kataInput,kataLoad))
        {
            int i,id;
            Address p;
            long price;
            char saveFile[32] = "../GAME/SAVE/";
            printf("Masukkan nama savefile :");
            kataInput = getInput();
            strcat(saveFile, kataInput.contents);
            startWORDfile(saveFile);
            N = atoi(currentWordfile.contents);
            advWORDfile();
            //printf("%s\n", currentWordfile.contents);
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
            //displaylistLOCATION(arrayLoc, L);
            // MENGINISIASI MAP BERTIPE MATRIX
            Matrix MAP;
            // MEMBUAT MAP
            CreateMAP(N, M, &MAP);
            // MEMBACA ELEMEN DARI MAP DENGAN MENANDAI TITIK TITIK YANG TELAH DIINPUT
            readMAPConfiguration(&MAP, arrayLoc, L + 1);

            // MEMBUAT MATRIX ADJ
            Matrix Madj = makeMatrixAdj(L);
            // MENAMPILAN MATRIX ADJ
            //displayMATRIX(Madj);
            advWORDfile();
            P = atoi(currentWordfile.contents);
            ListTASK lTask;
            ReadLISTTASKfile(&lTask, P);
            lTask = sortLISTTASK(lTask);

            // Memindahkan isi List Task ke Queue Task
            QueueTASK qTask;
            CreateQUEUETASK(&qTask, lTask.Neff);
            qTask = CopyListToQueueTASK(lTask);
            advWORDfile();
            TIME time;
            time.currentTime = atof(currentWordfile.contents);
            advWORDfile();
            time.incTime = atof(currentWordfile.contents);
            advWORDfile();
            CHAR(nobita) = currentWordfile.contents[0];
            advWORDfile();
            LOC_X(nobita) = atoi(currentWordfile.contents);
            advWORDfile();
            LOC_Y(nobita) = atoi(currentWordfile.contents);
            advWORDfile();
            money = atoll(currentWordfile.contents);
            int invLength;
            advWORDfile();
            invLength = atoi(currentWordfile.contents);
            ListGADGET listInventory;
            CreateLISTGADGET(&listInventory);
            for(i = 0; i < invLength; i++)
            {
                advWORDfile();
                id = atoi(currentWordfile.contents);
                advWORDfile();
                price = atoi(currentWordfile.contents);
                insertLastLISTGADGET(&listInventory, id,price);

            }
            advWORDfile();
            int toDoLength;
            toDoLength = atoi(currentWordfile.contents);
            List LinkedToDoList;
            CreateLINKEDLIST(&LinkedToDoList);
            for(i = 0; i < toDoLength; i++)
            {
                ReadLINKEDLISTTASKfile(&LinkedToDoList);
            }
            advWORDfile();
            Stack b; CreateBAG(&b);
            int bagSize;
            bagSize = atoi(currentWordfile.contents);
            UpdateBAGsize(&b, bagSize-3);
            List inProgressList;
            int inProgressLength;
            CreateLINKEDLIST(&inProgressList);
            advWORDfile();
            inProgressLength = atoi(currentWordfile.contents);
            for(i=0;i<inProgressLength;i++)
            {
                ReadLINKEDLISTTASKfile(&inProgressList);
            }
            p = FIRST(inProgressList);
            while(p!=NULL)
            {
                ElTypeTASK task;
                task.timeTASK = TIMETASK(p);
                task.pickUpTASK= PICKUPTASK(p);
                task.dropOffTASK= DROPOFFTASK(p);
                task.itemTASK = ITEMTASK(p);
                if (task.itemTASK == 'P')
                {
                    
                    task.timeExpTASK = TIMEEXPTASK(p);
                    task.initTimeExpTASK = INITTIMEEXPTASK(p);
                }
                PushBAG(&b, task);
                p = NEXT(p);
            }
            advWORDfile();
            moveFreq = atoi(currentWordfile.contents);
            advWORDfile();
            int successfulDropOff;
            successfulDropOff = atoi(currentWordfile.contents);
            ListGADGET listGadgetStore = initialGadgetStore();
            advWORDfile();
            rtsCounter = atoi(currentWordfile.contents);
            advWORDfile();
            
           while (!IsEmptyQUEUETASK(qTask) || !isEmptyLINKEDLIST(LinkedToDoList) || !isEmptyLINKEDLIST(inProgressList) || LOC_X(nobita) != i_headquarters || LOC_Y(nobita) != j_headquarters)
            {
                printf("\nMobita berada di posisi ");
                TulisLOCATION(nobita);
                printf("\n");
                displayCurrentTimeAndMoney(time, money);
                printf("\nENTER COMMAND : ");
                kataInput = getInput();
                printf("\n");
            
                if (isKataEqual(kataInput, kataMove))
                {
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
                        displayMAPColor(MAP, nobita, arrayPosMove, nPossibleMoves, LinkedToDoList, b);
                        // MENERIMA INPUTAN USER UNTUK LOKASI YANG DIPILIH
                        printf("\nPosisi yang dipilih? (ketik 0 jika ingin kembali)\n");
                        printf("\n");
                        printf("ENTER COMMAND: ");
                        kataInput = getInput();
                        lokasiDipilih = atoi(kataInput.contents);

                        // JIKA TIDAK TERJADI PERPINDAHAN MAKA MENGGUNAKAN LOKASI SEBELUMNYA
                        if(lokasiDipilih > nPossibleMoves)
                        {
                            printf("Tidak ada inputan tersebut ! kembali ke menu utama\n");
                        }
                        if (lokasiDipilih != 0)
                        {
                            printf("\nNobita sekarang berada di titik ");
                            if (time.incTime == 0.5)
                            {
                                moveFreq++;
                                speedBoost(&time, &moveFreq, b);
                            }
                            updateTimeToDoList(&qTask, &time, &LinkedToDoList);
                            updateProgressList(&inProgressList, time);
                            UpdatePerishableInBag(&b, time);
                            if (time.incTime == 0)
                            {
                                time.incTime = 1;
                            }
                            nobita = arrayPosMove[lokasiDipilih - 1];
                            //updateisi todolist
                            TulisLOCATION(nobita);
                            printf("!");
                            printf("\n");
                            printf("Waktu: %.f\n", floor(time.currentTime));
                        }
                        else
                        {
                            nobita = nobita;
                        }
                    } while (lokasiDipilih != 0);
                    
                }
                else if (isKataEqual(kataInput, kataPickUp))
                {
                    pickUpAtloc(nobita, &b, &inProgressList, &LinkedToDoList, &time);
                }
                else if (isKataEqual(kataInput, kataDropOff))
                {
                    dropOffAtloc(nobita, &b, &inProgressList, &money, &successfulDropOff, &time);
                }
                else if (isKataEqual(kataInput, kataMap))
                {
                    int nPossibleMoves;
                    LOCATION *arrayPosMove;
                    arrayPosMove = makeArrayOfPossibleMoves(Madj, arrayLoc, nobita, L, &nPossibleMoves);
                    displayMAPColor(MAP, nobita, arrayPosMove, nPossibleMoves, LinkedToDoList, b);
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
                else if (isKataEqual(kataInput, kataReturn))
                {
                    returnToSender(&b, &LinkedToDoList, &inProgressList,&rtsCounter, &time, &senterPengecilAktif);
                }
                else if (isKataEqual(kataInput, kataInventory))
                {
                    useInventory(&listInventory, &b, &time);
                }
                else if (isKataEqual(kataInput, kataHelp))
                {
                    printHelp();
                }
                else if(isKataEqual(kataInput, kataSaveGame))
                {
                    int i,j;
                    Address p;
                    char namaFile[32] = "../GAME/SAVE/";
                    printf("Masukkan nama file save : ");
                    kataInput = getInput();printf("\n");
    
                    strcat(namaFile, kataInput.contents);
                    
                    fptr = fopen(namaFile,"w");
                    fprintf(fptr, "%i %i\n", N,M);
                    fprintf(fptr, "%i %i\n%i\n", i_headquarters,j_headquarters,L);
                    for(i = 1; i<=L; i++)
                    {
                        fprintf(fptr, "%c %i %i\n", CHAR(arrayLoc[i]),LOC_X(arrayLoc[i]), LOC_Y(arrayLoc[i]));
                    }
                    for(i= 0; i <ROWSMATRIX(Madj); i++){
                        for (j = 0; j<COLSMATRIX(Madj); j++){
                            if (j == getLastIdxRowMATRIX(Madj)){
                                fprintf(fptr,"%d", ELMTMATRIX(Madj,i,j));
                            }else {
                                fprintf(fptr,"%d ", ELMTMATRIX(Madj,i,j));
                            }
                        }

                        if (i < getLastIdxRowMATRIX(Madj)){
                        fprintf(fptr,"\n");
                        } 

                    }

                    fprintf(fptr,"\n%i\n",LengthQUEUETASK(qTask));
                    for (i = IDX_HEAD_QUEUETASK(qTask); i < IDX_HEAD_QUEUETASK(qTask) + LengthQUEUETASK(qTask); i++)
                    {
                        if(qTask.bufferQUEUETASK[i].itemTASK =='P')
                        {
                             fprintf(fptr,"%d %c %c %c %f\n",  qTask.bufferQUEUETASK[i].timeTASK, qTask.bufferQUEUETASK[i].pickUpTASK, qTask.bufferQUEUETASK[i].dropOffTASK, qTask.bufferQUEUETASK[i].itemTASK, qTask.bufferQUEUETASK[i].timeExpTASK);
                        }
                        else{
                            fprintf(fptr,"%d %c %c %c\n",  qTask.bufferQUEUETASK[i].timeTASK, qTask.bufferQUEUETASK[i].pickUpTASK, qTask.bufferQUEUETASK[i].dropOffTASK, qTask.bufferQUEUETASK[i].itemTASK);
                        }
                        
                    }

                    fprintf(fptr,"%f %f\n", time.currentTime, time.incTime);
                    fprintf(fptr,"%c %d %d\n", CHAR(nobita), LOC_X(nobita), LOC_Y(nobita));
                    fprintf(fptr,"%li\n", money);
                    fprintf(fptr, "%i\n", listInventory.Neff);
                    for(i =0; i < listInventory.Neff;i++)
                    {
                        fprintf(fptr,"%i %li\n", listInventory.contents[i].idGADGET,listInventory.contents[i].priceGADGET);
                    }
                    fprintf(fptr, "%i\n", lengthLINKEDLIST(LinkedToDoList));
                   
                    p = FIRST(LinkedToDoList);
                    while(p!= NULL)
                    {
                        if(ITEMTASK(p) == 'P')
                        {
                            fprintf(fptr,"%d %c %c %c %f %f\n", TIMETASK(p),PICKUPTASK(p),DROPOFFTASK(p), ITEMTASK(p), TIMEEXPTASK(p),INITTIMEEXPTASK(p));
                        }
                        else
                        {
                            fprintf(fptr,"%d %c %c %c\n", TIMETASK(p),PICKUPTASK(p),DROPOFFTASK(p), ITEMTASK(p));
                        }
                        p = NEXT(p);
                    }
                    fprintf(fptr, "%i\n", b.currentCAPACITYSTACK);
                    fprintf(fptr, "%i\n", lengthLINKEDLIST(inProgressList));
                    p = FIRST(inProgressList);
                    while(p!= NULL)
                    {
                        if(ITEMTASK(p) == 'P')
                        {
                            fprintf(fptr,"%d %c %c %c %f %f\n", TIMETASK(p),PICKUPTASK(p),DROPOFFTASK(p), ITEMTASK(p), TIMEEXPTASK(p),INITTIMEEXPTASK(p));
                        }
                        else
                        {
                            fprintf(fptr,"%d %c %c %c\n", TIMETASK(p),PICKUPTASK(p),DROPOFFTASK(p), ITEMTASK(p));
                        }
                        p = NEXT(p);
                    }
                    fprintf(fptr,"%i\n", moveFreq);
                    fprintf(fptr, "%i\n", successfulDropOff);
                    fprintf(fptr,"%i\n",  rtsCounter );
                    fprintf(fptr, "%c\n", senterPengecilAktif);



                    fclose(fptr);     
                }
                else if (isKataEqual(kataInput,kataExit))
                {

                    break;
                }
                else
                {
                    printf("command tidak valid ! kembali ke menu awal\n");
                }
            }
            printf("Game Selesai !\n");
            printf("Waktu yang dilampaui : %f sekon\n", floor(time.currentTime));
            printf("Pesanan yang berhasil diantar : %i", successfulDropOff);
            //membaca file dri ascii art
                FILE *fptrascii2;

                char c;
                // Open file
                fptrascii2 = fopen("ascii2.txt", "r");
                if (fptrascii2 == NULL)
                {
                    printf("Cannot open file \n");
                    exit(0);
                }

                // Read contents from file
                c = fgetc(fptrascii2);
                while (c != EOF)
                {
                    printf ("%c", c);
                    c = fgetc(fptrascii2);
                }

                fclose(fptrascii2);
            flag = false;
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