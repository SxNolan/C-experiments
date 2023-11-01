#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct elemento {
    int numero;
    struct elemento *next;
};

void cancellaelem(struct elemento **testa, int data) {
    struct elemento *tmp = *testa;
    while (tmp != NULL) {
        if (tmp->numero == data) {
            *testa = tmp->next;
            free(tmp);
        }
        tmp = tmp->next;
    }
}

bool ricercanum(struct elemento *testa, int numerino) {
    while (testa != NULL) {
        if (testa->numero == numerino) {
            return true;
        }
        testa = testa->next;
    }
    return false;
}

void insertlist(struct elemento **testa) {
    int numdains;
    struct elemento *nuovo;
    nuovo = malloc(sizeof(struct elemento));
    if (nuovo == NULL) {
        exit(1);
    }
    printf("utente, digita il numero da inserire all'interno del nuovo nodo: ");
    scanf("%d", &numdains);
    fflush(stdin);
    nuovo->numero = numdains;
    nuovo->next = *testa;
    *testa = nuovo;
}

void printlist(struct elemento *testa) {
    while (testa != NULL) {
        printf(" numero: [%d] -->", testa->numero);
        testa = testa->next;
    }
    printf(" NULL");
}
int main() {
    int rispostina;
    int number;
    int numdacancellare;
    char risposta;
    bool rispostadafunction;
    bool cond = true;
    struct elemento *testa;
    testa = NULL;
    while (cond == true) {
        insertlist(&testa);
        printf("\n\nutente, sei soddisfatto o vuoi aggiungere altri elementi?");
        risposta = getchar();
        if (risposta == 'y') {
            printlist(testa);
            printf("\nutente, che numero vuoi cercare all'interno della tua lista? ");
            scanf("%d", &number);
            rispostadafunction = ricercanum(testa, number);
            if (rispostadafunction == true) {
                printf("il numero da te cercato e\' presente all'interno della lista!\n");
            } else {
                printf("il numero da te cercato non e\' presente all'interno della lista!\n");
            }
            printf("vuoi cancellare un elemento? ");
            scanf("%d", &rispostina);
            fflush(stdin);
            if (rispostina == 1) {
                printf("\ndimmi pure il numero da cancellare all'interno della lista: ");
                scanf("%d", &numdacancellare);
                fflush(stdin);
                cancellaelem(&testa, numdacancellare);
            } else {

            }
            cond = false;
        }
        else if (risposta == 'n') {
            cond = true;
        }
    }
    return 0;
}