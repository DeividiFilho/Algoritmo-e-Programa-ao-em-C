//4- Fa�a um programa que leia um n�mero inteiro ? 0 e
//calcule o seu fatorial.

#include <stdio.h>

int main() {
    int num, i, fat=1;

    printf("Digite um numero inteiro n�o negativo: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("N�mero inv�lido! O n�mero deve ser inteiro n�o negativo.\n");
        return 1; // sai do programa com erro
    }

    for (i = 1; i <= num; i++) {
        fat *= i; // multiplica o fatorial pelo pr�ximo n�mero
    }

    printf("%d! = %d\n", num, fat);

    return 0; // sai do programa com sucesso
}

