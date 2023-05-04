//  um programa que leia uma string e substitua todas as ocorrências de um caractere por outro especificado pelo usuário

#include <stdio.h>
#include <string.h>

main() {
	char str[100], c1, c2;
	int i;
	
	printf("\nDigite uma string: ");
	scanf("%s", str);
	
	printf("\nDigite o caracter a ser substituido: "); //é usado um espaço antes do %c para consumir a quebra de linha deixada pelo scanf anterior
	scanf(" %c", &c1);
	
	printf("\nDigite o caractere para substituir: ");
	scanf(" %c", &c2);
	
	for(i=0; i<strlen(str); i++) {
		if(str[i] == c1) {
			str[i] = c2;
		}
	}
	printf("\n\nA String depois de ser substituida: %s", str);
	return 0;
}

