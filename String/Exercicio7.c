// 7) Fa�a um programa que leia um nome completo e imprima de duas formas:
// com todas as letras emmin�sculas e com todas as letras em mai�sculas

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
	char nome[100];
	int i;
	
	printf("Digite um nome completo: ");
    fgets(nome, 100, stdin); // lendo o nome completo

    printf("\nNome em letras min�sculas: "); // Printando em letras min�sculas
    for ( i = 0; i < strlen(nome); i++) {
      printf("%c", tolower(nome[i])); // lower = low case
    }
    printf("\n");

    printf("Nome em letras mai�sculas: "); // Printando o nome em letras mai�sculas

    for ( i = 0; i < strlen(nome); i++) {
      printf("%c", toupper(nome[i])); // upper = uper case
    }
	printf("\n");
}

