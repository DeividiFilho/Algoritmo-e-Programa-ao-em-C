// Faça um programa que leia um número inteiro positivo e exiba na tela todos os números primos de 1 até esse número. 
// Um número primo é aquele que é divisível apenas por 1 e por ele mesmo.

#include <stdio.h>

int main() {
    int numero, i, j, primo;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);

    printf("Numeros primos de 1 a %d: ", numero);
    for (i = 1; i <= numero; i++) {
        primo = 1;
        for (j = 2; j <= i/2; j++) {
            if (i % j == 0) {
                primo = 0;
                break;
            }
        }
        if (primo) {
            printf("%d ", i);
        }
    }

}

