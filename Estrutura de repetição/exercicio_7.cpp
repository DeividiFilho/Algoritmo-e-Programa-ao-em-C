//7- Faça um programa que mostre os 8 primeiros termos
//da sequência de Fibonacci.
//Ex: 0, 1, 1, 2, 3, 5, 8,13, 21,34, 55

#include <stdio.h>

int main() {
    int n1 = 0, n2 = 1, n3, i;

    printf("\nSequencia de Fibonacci:\n");

    // Mostra os dois primeiros termos
    printf("%d %d ", n1, n2);

    // Loop para mostrar os próximos 6 termos
    for (i = 0; i < 6; i++) {
        n3 = n1 + n2;
        printf("%d ", n3);
        n1 = n2;
        n2 = n3;
    }

    return 0;
}

