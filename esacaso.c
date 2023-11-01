#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct nodo {
    int valore;
    struct nodo* next;
};

bool isEmpty(struct nodo* testa);
struct nodo* creaLista(struct nodo** testa); 
bool ricercainlista(int n, struct nodo* testa);
void insertelemincoda(struct nodo** testa);

int main(void) {
    int i;
    bool evuota;
    struct nodo* testa = NULL;
    evuota = isEmpty(testa);
    if (evuota == true) {
        printf("\nLa tua lista e\' vuota!");
    } else {
        printf("\nLa tua lista non e\' vuota!");
    }
    printf("\ncreazione lista in corso...");
    creaLista(&testa);
    printf("per favore utente, dimmi che elemento devo cercar dentro la lista: ");
    scanf("%d", &i);
    fflush(stdin);
    evuota = ricercainlista(i, testa);
    return 0;
}

bool isEmpty(struct nodo* testa) {
    if (testa == NULL) {
        return true;
    } else {
        return false;
    }
}

struct nodo* creaLista(struct nodo** testa) {
    if (isEmpty) {
        struct nodo* newelem = malloc(sizeof(struct nodo));
        if (newelem == NULL) {
            exit(1);
        }
        newelem->next = *testa;
        *testa = newelem;
        printf("che valore vuoi assegnare al value del nuovo nodo? (deve essere un integer) ");
        scanf("%d", &newelem->valore);
        fflush(stdin);
        return *testa;
    } else {
        exit(1);
    }
}

bool ricercainlista(int n, struct nodo* testa) {
    while (testa != NULL) {
        if (testa->valore == n) {
            return true;
        }
        testa = testa->next;
    }
    return false;
}

void insertelemincoda(struct nodo** testa) {
    struct nodo* tmp = *testa;
    struct nodo* newelem = malloc(sizeof(struct nodo));
    if (newelem == NULL) {
        exit(1);
    }
    if (isEmpty(tmp)) {
        newelem->next = tmp;
        tmp = newelem;
        printf("che valore vuoi assegnare al value del nuovo nodo? (deve essere un integer) ");
        scanf("%d", &newelem->valore);
        fflush(stdin);
    } else {
        while (tmp != NULL) {
            if (tmp->next == NULL) {
                newelem->next = tmp->next;
                tmp->next = newelem;
                printf("che valore vuoi assegnare al value del nuovo nodo? (deve essere un integer) ");
                scanf("%d", &newelem->valore);
                fflush(stdin);
                break;
            }
            tmp = tmp->next;
        }
}


