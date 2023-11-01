#include <stdio.h>
#include <stdbool.h>
#define MAXELEM 10

//pila : Last In First Out
typedef struct {         //dichiaro la mia strutturra e le do un nome attraverso typedef
    int dimensione;
    int vettore[MAXELEM]; //array statico: prima versione programma
} TStack;

TStack CreaStack();                 //dichiarazione delle varie funzioni necessarie al programma
void Destroypila(TStack *pila);
void push(TStack *pila, int num);
int pop(TStack *pila);
bool IsEmpty(TStack *pila);
bool IsFull(TStack *pila);
void inseriscieleminappoggio(TStack *appoggio, int x);

int main() {                //apertura del main
    int numerodamostrare;   //dichiarazione variabili necessarie al programma
    int numdagg;
    char risposta;
    bool ritornodafunction;
    int booleaninintero;
    bool finito = false;
    TStack stack;
    TStack appoggio;
    printf("buongiorno utente, oggi proveremo ad implementare una ADT di tipo lista.\n\n");
    while (finito == false) { //condizione di uscita dal ciclo per via dell'utilizzo di un menù
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
        switch(risposta) {  //creazione switch per filtrare scelta utente
            case '0' :      //chiamata alla funzione per creare un nuovo stack
            stack = CreaStack();
            appoggio = CreaStack();
                break;
            case '1' :      //chiamata alla funzione per inserire elementi dentro la pila
                printf("\n\nutente, scegli che elemento andare ad inserire all'interno dello stack: ");
                scanf("%d", &numdagg);  //richiesta in input dell'elemento da inserire
                fflush(stdin);
                push(&stack, numdagg);
                break;
            case '2' :      //chiamata alla funzione per estrarre e mostrare in input l'elemento in testa alla pila
                numerodamostrare = pop(&stack);
                printf("\n\nIl numero estratto dal tuo stack e\': %d\n\n", numerodamostrare);
                inseriscieleminappoggio(&appoggio, numerodamostrare);
                break;
            case '3' :      //chiamata alla funzione isempty per verificare se la nostra pila risulta vuota o meno
                ritornodafunction = IsEmpty(&stack);
                if (ritornodafunction == true) {
                    booleaninintero = 1;
                } else {
                    booleaninintero = 0;
                }
                printf("\n\nreturn value da questa funzione e\' (1 = true, 0 = false): %d\n\n", booleaninintero);
                break; //nota bene: avendo a che fare con un valore booleano, e non esistendo (almeno in base alle
                // mie ricerche) un segnaposto utile a 'printare' un valore booleano in output, ho preferito mostrarli
                //come 0 ed 1 (l'output del printf aiuta lo user alla comprensione).

            case '4' :      //chiamata alla funzione isfull per verificare se la nostra pila risulta piena o meno
                ritornodafunction = IsFull(&stack);
                if (ritornodafunction == true) {
                    booleaninintero = 1;
                } else {
                    booleaninintero = 0;
                }
                printf("\n\nreturn value da questa funzione e\'(1 = true, 0 = false): %d\n\n", booleaninintero);
                break; //nota bene: avendo a che fare con un valore booleano, e non esistendo (almeno in base alle
                // mie ricerche) un segnaposto utile a 'printare' un valore booleano in output, ho preferito mostrarli
                //come 0 ed 1 (l'output del printf aiuta lo user alla comprensione).
            case '5' :      //chiamata alla funzione utile a terminare la nostra pila
                Destroypila(&stack);
                break;
            case '6' :      //modifica la variabile booleana utile ad uscire dal menù e dunque a terminare l'esecuzione.
                finito = true;
        }
    }
    return 0;
}

TStack CreaStack() {
    TStack pila;
    pila.dimensione = 0;        //imposto la dimensione della pila uguale a zero (utile per andare a lavorare con deter
    //minati elementi ad esempio in pop e push
    return pila;
}

void inseriscieleminappoggio(TStack *appoggio, int x) {
    appoggio->vettore[appoggio->dimensione] = x;
    appoggio->dimensione++;
}


void Destroypila (TStack *pila) {
    pila->dimensione = 0;       //per 'distruggere la pila, non faccio altro che settare la dimensione a zero
}

void push(TStack *pila, int num) {
    pila->vettore[pila->dimensione] = num;    //assegno il valore preso in input al mio stack
    pila->dimensione++;                       //aumento il count per lavorare in un secondo momento sull'elemento succesivo
}

int pop(TStack *pila) {
    int numero;
    numero = pila->vettore[pila->dimensione-1];
    pila->dimensione--; //diminuisco il mio counter di uno
    return numero; //ritorno al chaimante il valore estratto
}

bool IsEmpty(TStack *pila) {
    return pila->dimensione == 0; //return al chiamante del valore booleano
}

bool IsFull(TStack *pila) {
    return pila->dimensione == MAXELEM; //return al chiamante del valore booleano
}