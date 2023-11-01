/*
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define MAXLENGHT 300

int main(void) {
    time_t now;
    const double DELAY = 0.2;
    bool flag = true;
    int max = 255;
    int min= 1;
    int numero_generato;
    time_t seed = 0;
    int i;
    char stringa[MAXLENGHT + 1];
    char appoggio[MAXLENGHT + 1];
    printf("caro utente, inserisci una stringa a piacimento: ");
    gets(stringa);
    srand(seed);
    for (; flag == true;) {
        now = clock();
        system("cls");
        for( ; clock() - now < DELAY*CLOCKS_PER_SEC; ); // Wait DELAY seconds
        for (i = 0; i < strlen(stringa); i++) {
            for (int j = 0; stringa[i] == appoggio[i]; j++) {
                numero_generato = rand() % (max - min) + min;
                appoggio[j] = (char)numero_generato;
                if (j == 3) {
                    appoggio[j] = stringa[j];
                }
            }
                printf("%c", appoggio[i]);

        }

        if (strcmp(stringa, appoggio) == 0) {
            flag = false;
        }
    }
    return(0);
    } */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//uso il materiale che ha condiviso il prof. Ravaioli, cosi possiamo avere delle funzioni per la console che
// valgono sia su mac sia su windows
#ifdef _WIN32 // valido sia per 32 che 64 bit
#include <conio.h>
#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING  0x0004
#endif

static HANDLE stdoutHandle;
static DWORD outModeInit;

void setupConsole(void) {
    DWORD outMode = 0;
    stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if(stdoutHandle == INVALID_HANDLE_VALUE) {
        exit(GetLastError());
    }
    if(!GetConsoleMode(stdoutHandle, &outMode)) {
        exit(GetLastError());
    }
    outModeInit = outMode;
    outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if(!SetConsoleMode(stdoutHandle, outMode)) {
        exit(GetLastError());
    }
}
#else
#include <termios.h>
    #include <unistd.h>

    int getch(void) {
        struct termios oldattr, newattr;
        int ch;
        tcgetattr( STDIN_FILENO, &oldattr );
        newattr = oldattr;
        newattr.c_lflag &= ~( ICANON | ECHO );
        tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
        ch = getchar();
        tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
        return ch;
    }

    int getche(void) {
        struct termios oldattr, newattr;
        int ch;
        tcgetattr( STDIN_FILENO, &oldattr );
        newattr = oldattr;
        newattr.c_lflag &= ~( ICANON );
        tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
        ch = getchar();
        tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
        return ch;
    }
#endif

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
//how to use color:
//printf("This is " RED "red" RESET " and this is " BLU "blue" RESET "\n");

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

#define MAX_ASCII 254
#define MIN_ASCII 1

int generaCarattereASCII(int delta, char lettera) {
    int min = (int) lettera - delta;
    int max = (int) lettera + delta;
    if(min<MIN_ASCII || max>MAX_ASCII)
    {min=MIN_ASCII;max=MAX_ASCII;}

    int ASCII_generato = rand() % (max - min) + min;
    if(ASCII_generato < 7 || ASCII_generato > 15)
        return ASCII_generato;
    else
        return 49;
}

#define CARATTERE_DI_FINE_INSERIMENTO '#'
#define LUNGHEZZA_STRINGA 200
#define GIRA 20

int main() {
    /*Gruppo:
    Matricola:  Alex Mazzoni       E-mail: alex.mazzoni3@studio.unibo.it
    Matricola:  Giovanni Luca      E-mail: giovanni.luca@studio.unibo.it
    Matricola:  Michele Farneti    E-mail: michele.farneti@studio.unibo.it
    */
    printf("\nSettimana 5 - Esercizio 2\t E-mail di riferimento: alex.mazzoni3@studio.unibo.it\n");

    srand(time(NULL));

    int i = 0;
    char testo[LUNGHEZZA_STRINGA];

    int parallelo[LUNGHEZZA_STRINGA];
    int max_parallelo = 0;

    char *colori[] = {RED, BLU, YEL, MAG, CYN, GRN};

    printf("\ninserisci il testo (inserire il carattere '%c'):\n", CARATTERE_DI_FINE_INSERIMENTO);
    for (i = 0; i < sizeof(testo) - 1 && (testo[i] = getch()) !=
                                         CARATTERE_DI_FINE_INSERIMENTO; i++) //inserire il termine definito nella define per terminare la testo oppure finire la lunghezza della stringa
    {
        if (testo[i] == '\r') testo[i] = '\n';
        printf("%c", testo[i]); //stampa il carattere inserito.
        if (testo[i] != '\b') {
            parallelo[i] = rand() % (GIRA - 2) + 2;
            if (parallelo[i] > max_parallelo)max_parallelo = parallelo[i];
        } else i = i - 2;
    }
    int lunghezza_effettiva = i;
    float velocita_testo = 0.05f;     //in secondi
    float velocita_carattere = 0.02f; //in secondi
    testo[i + 1] = '\0';

    clock_t now;
    for (i = 0; i <= max_parallelo; i++) {
        int indice_colori = rand() % (5 - 0) + 0;
        now = clock();
        for (; clock() - now < velocita_testo * CLOCKS_PER_SEC;); // Wait DELAY seconds

        clear();
        printf("\n\n");
        for (int j = 0; j < lunghezza_effettiva; j++) {
            now = clock();
            for (; clock() - now < velocita_carattere * CLOCKS_PER_SEC;); // Wait DELAY seconds

            if (i < parallelo[j])
                printf("%s" "%c" RESET, colori[indice_colori], generaCarattereASCII((((i + 1) * 100) / 20), testo[j]));
            else
                printf(WHT "%c" RESET, testo[j]);
        }
    }
    printf("\n\n");

    return 0;
}