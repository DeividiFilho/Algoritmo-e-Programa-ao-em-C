//4- Faça um programa que leia um número inteiro ? 0 e
//calcule o seu fatorial.

#include <stdio.h>

int main() {
    int num, i, fat=1;

    printf("Digite um numero inteiro não negativo: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Número inválido! O número deve ser inteiro não negativo.\n");
        return 1; // sai do programa com erro
    }

    for (i = 1; i <= num; i++) {
        fat *= i; // multiplica o fatorial pelo próximo número
    }

    printf("%d! = %d\n", num, fat);

    return 0; // sai do programa com sucesso
}

