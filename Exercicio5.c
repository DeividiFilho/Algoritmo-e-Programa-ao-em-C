#include <stdio.h>

int calcularFatorial(int n) {
    int fatorial = 1, i;
    for ( i = 1; i <= n; i++) {
        fatorial *= i;
    }
    return fatorial;
}

float calcularSerie() {
    float soma = 0;
    int i;
    for ( i = 0; i < 10; i++) {
        float termo = (float)(100 - i) / calcularFatorial(i);
        soma += termo;
        printf("%.2f ", termo);
    }
    printf("\n");
    return soma;
}

int main() {
    float soma = calcularSerie();
    printf("Soma total: %.2f\n", soma);
    return 0;
}

