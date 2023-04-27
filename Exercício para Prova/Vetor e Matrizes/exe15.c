// Leia um vetor de 10 posic¸oes. Contar e escrever quantos valores pares ele possui. ˜

#include <stdio.h>

int main() {
    int vetor[10];
    int i, count = 0;

    for (i = 0; i < 10; i++) {
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < 10; i++) {
        if (vetor[i] % 2 == 0) {
            count++;
        }
    }
    printf("\nO vetor possui %d valores pares.\n", count);
}

