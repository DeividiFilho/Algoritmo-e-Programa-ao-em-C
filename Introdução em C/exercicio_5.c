//5- Dados três valores X, Y e Z, verifique se eles podem
//ser os comprimentos dos lados de um triângulo. Se
//forem, verifique se é um triângulo equilátero,
//isósceles ou escaleno. Se não formarem um
//triângulo, escreva uma mensagem informando que
//não é triângulo. Considere que:
//– O comprimento de cada lado do triângulo é menor do que
//a soma dos outros dois lados.
//– O triângulo equilátero tem três lados iguais.
//– O triângulo isósceles tem o comprimento de dois lados
//iguais.
//– O triângulo escaleno tem os três lados diferentes.

#include <stdio.h>

int main() {
    int x, y, z;

    printf("Digite o valor de X: ");
    scanf("%d", &x);

    printf("Digite o valor de Y: ");
    scanf("%d", &y);

    printf("Digite o valor de Z: ");
    scanf("%d", &z);

    if (x < y + z && y < x + z && z < x + y) {
        if (x == y && y == z) {
            printf("\nTriangulo equilatero.\n");
        } else if (x == y || x == z || y == z) {
            printf("\nTriangulo isosceles.\n");
        } else {
            printf("\nTriangulo escaleno.\n");
        }
    } else {
        printf("\nNao e triangulo.\n");
    }

    return 0;
}



