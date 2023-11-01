#include <stdio.h>

int main() {
    int number1;
    int number2;
    printf("bro, please insert the first number: ");
    scanf("%d", &number1);
    printf("bro, please insert the second number: ");
    scanf("%d", &number2);

    if (number1 >= number2)
    {
        printf("Il primo numero da te scelto (%d), risulta essere il numero maggiore. NB: Potrebbe essere anche uguale all'altro numero, occhio ;)\n", number1 );
    }

    if (number1 < number2)
    {
        printf("Il secondo numero da te scelto (%d), risulta essere il numero maggiore.\n", number2 );
    }

    return 0;
}
