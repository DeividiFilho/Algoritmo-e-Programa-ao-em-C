#include <stdio.h>

void substituirNegativosPorZero(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] < 0) {
            vetor[i] = 0;
        }
    }
}

int main() {
    int vetor[10] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10};
    int i;
    
    printf("Vetor original: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    
    substituirNegativosPorZero(vetor, 10);
    
    printf("\nVetor modificado: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    
    return 0;
}

//  a função percorre todos os elementos do vetor usando um laço for,
// e se o valor do elemento for negativo, substitui esse valor por zero.
