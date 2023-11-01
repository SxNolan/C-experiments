#include <stdio.h>

int main() {
    int primonumero;
    int secondonumero;
    int terzonumero;
    int rismedia;
    puts("Utente, mi comunichi pure il tuo primo numero:");
    scanf("%d", &primonumero);
    puts("Utente, mi comunichi pure il tuo secondo numero:");
    scanf("%d", &secondonumero);
    puts("Utente, mi comunichi pure il tuo terzo numero:");
    scanf("%d", &terzonumero);
    rismedia = ( primonumero + secondonumero + terzonumero ) / 3;
    printf("La media tra %d, %d e %d risulta uguale a %d \n", primonumero, secondonumero, terzonumero, rismedia);
    printf("Utente, per calcolare una nuova media, la prego di restartarmi di conseguenza. Altrimenti, se ha finito di utilizzarmi, mi chiuda senza alcun problema. Alla prossima! :D");
    return 0;
}
