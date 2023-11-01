#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct elemento {
    int valore;
    struct elemento *next;
};

void push(struct elemento **testa, int x);
int pop(struct elemento **testa);
bool IsEmpty(struct elemento *testa);
bool IsNotTrue(struct elemento *testa);
void destroypila(struct elemento **testa);

    int main() {
        bool ritornodafunction;
        bool finito = false;
        char risposta;
        int numdagg, numerodamostrare;
        struct elemento *testa;
        testa = NULL; //inizializzo la mia testa a NULL
        printf("buongiorno utente, oggi proveremo ad implementare una ADT di tipo lista.\n\n");
        while (finito == false) {
            printf("Menu\' a scelta multipla comprendente: \n0 - creazione di una nuova pila.\n");
            printf("1 - push di un nuovo elemento ( sottinteso inserimento per via della ADT utilizzata).\n");
            printf("2 - pop dell'elemento (sottinteso in testa per via della ADT utilizzata).\n");
            printf("3 - verifica della 'vuotezza' della pila creata precedentemente.\n");
            printf("4- verifica della 'saturazione' della pila creata precedentemente.\n");
            printf("5 - distruzione della pila creata precdentemente.\n");
            printf("6 - terminazione dell'eseguibile.\n");
            printf("\nper favore utente, inserisca la sottofunzione che le interessa utilizzare (se non lo si"
                   " e\' ancora fatto, si provveda ad inizializzare la propria pila [digitando 0 ed inviando]:");
            risposta = getchar();
            switch (risposta) {      //creazione switch per filtrare scelta utente
                case '1' :          //chiamata alla funzione per inserire elementi dentro la pila
                    printf("\n\nutente, scegli che elemento andare ad inserire all'interno dello stack: ");
                    scanf("%d", &numdagg);   //richiesta in input dell'elemento da inserire
                    fflush(stdin);
                    push(&testa, numdagg);
                    break;
                case '2' :
                    numerodamostrare = pop(&testa);
                    printf("il numero estratto e\': %d", numerodamostrare);
                    break;
                case '3' :
                    ritornodafunction = IsEmpty(testa);
                    if (ritornodafunction == true) {
                        printf("utente, la tua lista e\' vuota.");
                    } else {
                        printf("utente, la tua lista non e\' vuota.");
                    }
                    break;
                case '4':
                    ritornodafunction = IsNotTrue(testa);
                    if (ritornodafunction == true) {
                        printf("utente, la tua lista non e\' vuota.");
                    } else {
                        printf("utente, la tua lista e\' vuota.");
                    }
                    break;
                case '5':
                    destroypila(&testa);
                    break;
                case '6' :
                    finito = true;
                break;
            }
        }
    return 0;
    }


void push(struct elemento **testa, int x) {
    struct elemento *nuovo;
    nuovo = NULL;
    if (nuovo == NULL) {
        nuovo = malloc(sizeof(struct elemento));
    }
    if (nuovo == NULL) {
        exit(1);
    }
    nuovo->valore = x;
    nuovo->next = *testa;
    *testa = nuovo;
}

int pop(struct elemento **testa) {
    int numerino;
    if (*testa == NULL) {
        exit(1);
    }
    struct elemento *temp;
    temp = *testa;
    *testa = temp->next;
    numerino = temp->valore;
    free(temp);
    return numerino;
}

bool IsEmpty(struct elemento *testa) {
    if (testa == NULL) {
      return true;
    } else {
        return false;
    } //return al chiamante del valore booleano
}

bool IsNotTrue(struct elemento *testa) {
    if (testa == NULL) {
        return false;
    } else {
        return true;
    } //return al chiamante del valore booleano
}

void destroypila(struct elemento **testa) {
    *testa = NULL;
}