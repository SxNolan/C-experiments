
/*
 ESERCIZIO 1
Indovina il continente

        In questo gioco, il computer visualizza una coppia di coordinate generata in maniera random sullo schermo per un breve periodo di tempo. Il giocatore deve indovinare a quale continente appartiene la coppia di coordinate generate; fino a quando l'utente indovina il gioco prosegue con la generazione di una nuova coppia di coordinate. L'obiettivo è quello di continuare il processo il più a lungo possibile.

Al termine del gioco il programma calcolerà un punteggio ottenuto quantomeno sulla base del numero di iterazioni eseguite e inviterà il giocatore a giocare di nuovo.

N.B.: i margini che definiscono i confini dei vari continenti sono decisi da voi
 */

#include <stdio.h> // For input and output
#include <stdlib.h> // For rand() and srand()
#include <time.h> // For time() function


int main(void) {
    char onemoregame;
    char risposta[7];
    const unsigned int ritardo = 2;
    time_t now = 0;
    int coord1, coord2;
    srand(time(NULL));

        coord1 = rand() % (1000 - 100) + 100;
        if (coord1 <= 250){
            coord2 = rand() % (900 - 600) + 600;
        }
        if (coord1 >= 251 && coord1 <= 400){
            coord2 = rand() % (1200 - 901) + 901;
        }
        if (coord1 >= 401 && coord1 <= 550){
            coord2 = rand() % (1500 - 1201) + 1201;
        }
        if (coord1 >= 551 && coord1 <= 700){
            coord2 = rand() % (1800 - 1501) + 1501;
        }
        if (coord1 >= 701 && coord1 <= 850){
            coord2 = rand() % (2100 - 1801) + 1801;
        }
        if (coord1 >= 851 && coord1 <= 1000){
            coord2 = rand() % (2400 - 2101) + 2101;
        }

        printf("%d %d", coord1, coord2);
        for (; clock() - now < ritardo * CLOCKS_PER_SEC;);
        printf("\r                  ");
        printf("ora rispondi qual'e\' il continente giusto: ");
        scanf("%s", &risposta);
        fflush(stdin);
        if (risposta[0] == 'a')
            {
                if (risposta[1] == 'm')
                {
                    if (coord1 >= 100 && coord1 <= 250 && coord2 >= 600 && coord2 <= 900)
                    {
                        printf("la risposta America e\' corretta.\n");
                    }
                    else {
                        printf("sbagliato.\n");
                    }
                }
                else if (risposta[1] == 'f')
                {
                    if (coord1 >= 251 && coord1 <= 400 && coord2 >= 901 && coord2 <= 1200)
                    {
                        printf("la risposta Africa e\' corretta.\n");
                    }
                    else {
                        printf("sbagliato.\n");
                    }
                }
                else if (risposta[1] == 's') {
                    if (coord1 >= 401 && coord1 <= 550 && coord2 >= 1201 && coord2 <= 1500)
                    {
                    printf("la risposta Asia e\' corretta.\n");
                    }
                    else {
                        printf("sbagliato.\n");
                    }
                }
                else if (risposta[1] == 'n')
                {
                    if (coord1 >= 551 && coord1 <= 700 && coord2 >= 1501 && coord2 <= 1800)
                    {
                        printf("la risposta Antartide e\' corretta.\n");
                    }
                    else {
                        printf("sbagliato.\n");
                    }
                }
            }
        if (risposta[0] == 'e')
        {
            if (coord1 >= 701 && coord1 <= 850 && coord2 >= 1801 && coord2 <= 2100)
            {
                printf("la risposta Europa e\' corretta.\n");
            }
            else {
                printf("sbagliato.\n");
            }
        }
        if (risposta[0] == 'o')
        {
            if (coord1 >= 851 && coord1 <= 1000 && coord2 >= 2101 && coord2 <= 2400)
            {
                printf("la risposta Oceania e\' corretta.\n");
            }
            else {
                printf("sbagliato.\n");
            }
        }

    printf("see you soon user :).");
    return 0;
}