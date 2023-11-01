#include <stdio.h>

int main(void)
    {
        int numero1;
		int numero2;
		int numero3;
		printf("User, please insert the first number: ");
		scanf("%d", &numero1);
		printf("User, please insert the second number: ");
		scanf("%d", &numero2);
		printf("User, please insert the third number: ");
		scanf("%d", &numero3);
		if (numero1 > numero2 && numero1 > numero3)
        {
            printf("User, your first number (%d) id the biggest number.\n\n", numero1);
        }
        if (numero2 > numero1 && numero2 > numero3)
        {
            printf("User, your second number (%d) id the biggest number.\n\n", numero2);
        }
        if (numero3 > numero1 && numero3 > numero2)
        {
            printf("User, your third number (%d) id the biggest number.\n\n", numero3);
        }
        int contatore;
        contatore = printf("User, do not hesitate to use me if you need help. See you soon.\n\n");
        printf("Character printed by the last function printf() are: %d\n\n", contatore);
        return 0;
    }
