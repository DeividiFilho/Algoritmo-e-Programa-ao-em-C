// implementação de um programa que faz a busca e
// substituição de uma palavra específica em um texto.

#include <stdio.h>
#include <string.h>

#define MAX_TEXTO 1000
#define MAX_PALAVRA 100

void buscarSubstitui(char texto[], char palavra[], char substituto[]) {
	char novoTexto[MAX_TEXTO];
	int i = 0, j = 0, k = 0;
	int tamTexto = strlen(texto);
	int tamPalavra = strlen(palavra);
	int tamSubstituto = strlen(substituto);
	
	while(i < tamTexto) {
		int palavraEncontrada = 1;
		for(j = 0; j < tamPalavra; j++) {
			if(texto[i + j] != palavra[j]) {
				palavraEncontrada = 0;
				break;
			}
		}
		if(palavraEncontrada) {
			for(j = 0; j < tamSubstituto; j++) {
				novoTexto[k++] = substituto[j];
			}
			i += tamPalavra;
		} else {
			novoTexto[k++] = texto[i++];
		}
	}
	novoTexto[k] = '\0';
	strcpy(texto, novoTexto);
}


int main() {
	char texto[MAX_TEXTO], palavra[MAX_PALAVRA], substituto[MAX_PALAVRA];
	
	printf("Digite o texto: ");
	fgets(texto, MAX_TEXTO, stdin);
	
	printf("\nDigite a palavra a ser substituida: ");
	scanf("%s", palavra);
	
	printf("\nDigite o termo para substituicao: ");
	scanf("%s", substituto);
	
	printf("Texto apos a substituiicao: %s", texto);
	return 0;
}
