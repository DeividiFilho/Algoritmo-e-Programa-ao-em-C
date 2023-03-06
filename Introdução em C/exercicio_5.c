//5- Dados tr�s valores X, Y e Z, verifique se eles podem
//ser os comprimentos dos lados de um tri�ngulo. Se
//forem, verifique se � um tri�ngulo equil�tero,
//is�sceles ou escaleno. Se n�o formarem um
//tri�ngulo, escreva uma mensagem informando que
//n�o � tri�ngulo. Considere que:
//� O comprimento de cada lado do tri�ngulo � menor do que
//a soma dos outros dois lados.
//� O tri�ngulo equil�tero tem tr�s lados iguais.
//� O tri�ngulo is�sceles tem o comprimento de dois lados
//iguais.
//� O tri�ngulo escaleno tem os tr�s lados diferentes.

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



