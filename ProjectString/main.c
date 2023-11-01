/*
  ESERCIZIO 2
Scrivere un programma che legga da tastiera un testo terminato dal carattere # e poi stampi le statistiche relative
 al numero di spazi, al numero di caratteri di nuova linea, al numero di caratteri letti, al numero di quelli maiuscoli,
 etc. utilizzando almeno una volta tutte le funzioni dell’header ctype.h
*/


#include <stdio.h>
#include <ctype.h>
int main()
{
    int i;
    char Vettore[i];
    int contaspazi = 0;
    int contanumeri = 0;
    int contaminuscole = 0;
    int contamaiuscole = 0;
    printf("please user, inserisci una frase a tuo piacimento con alla fine un #: \n");
    fgets(Vettore,100 ,stdin);
    /*
    scanf("%s", &Vettore[i]);
     */
    fflush(stdin);
    i = 0;
    while (Vettore[i] !='#')
    {
        fflush(stdin);
        if (Vettore[i] ==' ')
        {
            contaspazi++;
        }
        if (isdigit(Vettore[i])) {
            contanumeri++;
        }
        if (islower(Vettore[i])) {
            contaminuscole++;
        }
        if (isupper(Vettore[i])) {
            contamaiuscole++;
        }
        i = i + 1;
    }

    printf("\nrisultato:\nnumero di spazi: %d\nnumero di numeri: %d\nnumero di minuscole: "
           "%d\nnumero di maiuscole: %d\nnumero di caratteri: %d\n\n"
           , contaspazi, contanumeri, contaminuscole, contamaiuscole, i);
    printf("nota bene: all'interno della somma del numero di caratteri non ho inserito il conteggio del"
           " cancelletto. (#)\n\n\n");

    char letter = 'a';
    if (isalpha(letter))
    {
        printf("Risultato funzione isalpha(): %c\n\n", letter);
    }
    char number = '9';
    if (isalnum(number))
    {
        printf("Risultato funzione isalnum(): %c\n\n", number);
    }
    char maiusc = 'B';
    printf("valore iniziale variabile maiusc: %c\n\n", maiusc);
    if (isupper(maiusc))
    {
        printf("Risultato funzione tolower(): %c\n\n", tolower(maiusc));
    }
    char minusc = 'a';
    printf("valore iniziale variabile minusc: %c\n\n", minusc);
    if (tolower(minusc))
    {
        printf("Risultato funzione toupper(): %c\n\n", toupper(minusc));
    }
    printf("grazie utente, e arrivederci! :)\n\n");
    return 0;
}
