#include <stdio.h>
#include <math.h>

float calculaDelta(float a, float b, float c) {
    float delta = b * b - 4 * a * c;
    return delta;
}

void calculaRaizes(float a, float b, float c) {
    float delta = calculaDelta(a, b, c);
    
    if (delta < 0) {
        printf("Nao existem raizes reais.\n");
    } else if (delta == 0) {
        float x = -b / (2 * a);
        printf("Existe uma raiz real: %.2f\n", x);
    } else {
        float x1 = (-b + sqrt(delta)) / (2 * a);
        float x2 = (-b - sqrt(delta)) / (2 * a);
        printf("Existem duas raizes reais:\n x1 = %.2f\n x2 = %.2f\n", x1, x2);
    }
}

int main() {
    float a, b, c;
    
    printf("Digite os valores de a, b e c:\n");
    scanf("%f %f %f", &a, &b, &c);
    
    printf("Equacao: %.2fx^2 + %.2fx + %.2f = 0\n", a, b, c);
    
    calculaRaizes(a, b, c);
    
    return 0;
}

