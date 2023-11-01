/*
 ESERCIZIO 2
Pensa a un numero.

L’utente pensa ad un numero e il computer lo deve indovinare compiendo le seguenti operazioni.

- L’utente fissa un intervallo entro cui generare il valore da indovinare (min, max). Se i valori inseriti non rispettano il vincolo 0<min≤max, l’operazione di lettura va ripetuta

- L’utente pensa ad un numero compreso tra min e max.

- Il programma cerca di indovinare la scelta dell’utente e propone un numero. A seconda della situazione l’utente deve dire al programma se:

- il numero da indovinare è più piccolo;

- il numero da indovinare è più grande;

- ha indovinato.

Scrivere una versione di programma in cui non c'è limite al numero di tentativi e scriverne un'altra in cui invece viene posto tale limite.

Il programma deve stampare il numero di tentativi.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int min;
    printf("Benvenuto utente, per favore setta il valore minimo di range dell'intervallo: ");
    scanf("%d", &min);
    fflush(stdin);
    int max;
    printf("Utente, per favore setta il valore massimo di range dell'intervallo: ");
    fflush(stdin);
    scanf("%d", &max);
    int numestratto;
    char rispostautente;
    fflush(stdin);
     while (min <= 0 || max <= 0 || min > max)
        {
            printf("Utente, ascoltami attentamente. Il numero minimo del range deve essere obbligatoriamente "
                   "maggiore di zero e minore o uguale al massimo. Il massimo, invece, deve essere"
                   " necessariamente maggiore di zero e maggiore o uguale al minimo.\n");
            printf("utente, per favore setta il valore minimo di range dell'intervallo: ");
            scanf("%d", &min);
            fflush(stdin);
            printf("utente, per favore setta il valore massimo di range dell'intervallo: ");
            scanf("%d", &max);
            fflush(stdin);
        }
     numestratto = rand() % (max - min) + min;
     printf("Molto bene caro utente. Adesso estrarremo un numero casuale all'interno del range."
                   " Il Numero estratto: %d\n", numestratto);
    printf("il numero estratto era il tuo? O uno maggiore ominore di quest'ultimo? (rispondi con >, < o =): ");
    scanf("%c", &rispostautente);
    fflush(stdin);
    int cont = 1;
    while (rispostautente != '=')
    {
        if (rispostautente == '>')
        {
            min = numestratto;
            numestratto = rand() % (max - min) + min;
            printf("Molto bene caro utente. Adesso estrarremo un numero casuale all'interno del range."
                   " Il Numero estratto: %d\n", numestratto);
            printf("il numero estratto era il tuo? O uno maggiore ominore di quest'ultimo? (rispondi con >, < o =): ");
            scanf("%c", &rispostautente);
            fflush(stdin);
            cont = cont + 1;
        }
        else if (rispostautente == '<')
        {
            max = numestratto;
            numestratto = rand() % (max - min) + min;
            printf("Molto bene caro utente. Adesso estrarremo un numero casuale all'interno del range."
                   " Il Numero estratto: %d\n", numestratto);
            printf("il numero estratto era il tuo? O uno maggiore ominore di quest'ultimo? (rispondi con >, < o =): ");
            scanf("%c", &rispostautente);
            fflush(stdin);
            cont = cont + 1;
        }
    }
    printf("Caro utente, alla fine ho indovinato. Nella bellezza di %d tentativi! Alla prossima!", cont);
    return 0;
}

