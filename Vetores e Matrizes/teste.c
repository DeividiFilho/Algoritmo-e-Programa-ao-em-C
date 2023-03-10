#include <stdio.h>

int main() {
    int matrizA[3][3];
    int matrizB[3][3];
    int matrizSoma[3][3];
    int i, j;

    // preenchendo a matriz A
    printf("Preencha a matriz A:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &matrizA[i][j]);
        }
    }

    // preenchendo a matriz B
    printf("\nPreencha a matriz B:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Digite o elemento [%d][%d]: ", i, j);
            scanf("%d", &matrizB[i][j]);
        }
    }

    // somando as matrizes
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matrizSoma[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    // imprimindo a matriz resultado
    printf("A soma das matrizes A e B eh:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", matrizSoma[i][j]);
        }
        printf("\n");
    }

    return 0;
}

