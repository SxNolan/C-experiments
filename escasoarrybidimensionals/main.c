#include <stdio.h>
#define MAXI 5
#define MAXJ 5
int main() {
    int numero;
    int i;
    int j;
    int somma = 0;
    int matrice[MAXI][MAXJ];
    for (i = 0; i < MAXI; i++) {
        for (j = 0; j < MAXJ; j++) {
            fflush(stdin);
            printf("\ninserisci numero dentro matrice: ");
            scanf("%d", &numero);
            matrice[i][j] = numero;
            somma = somma + numero;
        }
    }
    printf("\ncaro, eccoti il tuo array bidimensionale: \n");
    for (i = 0; i < MAXI; i++) {
        for (j = 0; j < MAXJ; j++) {
            printf("%d ", matrice[i][j]);
            if (j == MAXJ - 1) {
                printf("\n");
            }
        }
    }
    printf("valore somma dell'array: %d", somma);
    return 0;
}
