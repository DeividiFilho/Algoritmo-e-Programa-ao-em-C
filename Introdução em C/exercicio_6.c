//6- Faça um programa para resolver equações
//do 2o grau. Considere:
//ax2 + bx + c = 0 Obs: a deve ser diferente de 0
//delta = b2 - 4 * a * c
//Se delta < 0, não existe raiz real
//Se delta = 0, existe uma raiz real
//x = (-b) / (2 * a)
//Se delta > 0, existem duas raízes reais
//x1 = (- b + raiz quadrada de delta) / (2 * a)
//x2 = (- b - raiz quadrada de delta) / (2 * a)
//
//Testes
//1: <1, 1, 1; não tem raízes>
//2: <1, 2, 1; -1>
//3: <1, 0, -4; 2, -2>

#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, delta, x1, x2;

    // Entrada dos valores de a, b e c
    printf("Digite os valores de a, b e c: ");
    scanf("%f%f%f", &a, &b, &c);

    // Cálculo do delta
    delta = b * b - 4 * a * c;

    // Verifica se existe raiz real
    if (delta < 0) {
        printf("Nao existe raiz real.\n");
    } else if (delta == 0) {
        // Existe uma raiz real
        x1 = -b / (2 * a);
        printf("Existe uma raiz real: x = %.2f\n", x1);
    } else {
        // Existem duas raízes reais
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("Existem duas raizes reais: x1 = %.2f, x2 = %.2f\n", x1, x2);
    }

    return 0;
}

