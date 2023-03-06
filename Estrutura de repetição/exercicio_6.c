//6- Fa�a um programa que receba um numero N
//fornecido pelo usu�rio e mostre os N termos da s�rie a
//seguir:
//S = 1/1 + 2/3 + 3/5 + 4/7 + 5/9 + ... + n/m
//Por fim, imprima a soma total da s�rie

#include <stdio.h>

int main() {
    int n, i;
    float s = 0, m = 1;  // Vari�veis para armazenar a soma e o denominador

    printf("Digite um valor para N: ");
    scanf("%d", &n);

    // Loop para calcular e exibir cada termo da s�rie
    for (i = 1; i <= n; i++) {
        s += i / m;  // Adiciona o termo atual � soma
        printf("\n%d/%.0f ", i, m);  // Exibe o termo atual
        m += 2;  // Incrementa o denominador
    }

    // Exibe a soma total da s�rie
    printf("\nSoma total: %.2f", s);

    return 0;
}


