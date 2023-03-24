// 1) Faça um programa que receba uma palavra everifique se ela é um palíndromo, ou seja,
// se escritado fim para o começo é igual à palavra escrita docomeço para o fim. Exemplo: 
// RENNER, ANA, MIRIM, OVO, etc

#include <stdio.h>
#include <string.h>

int main(){
	char palavra[100];
	int i, j, tamanho;
	int palindromo = 1; // assume q é palíndromo
	

	printf("Digite uma palavra: ");
	scanf("%s", palavra);
	
	tamanho = strlen(palavra);
	
	for( i=0, j = tamanho - 1; i < tamanho / 2, i++;) { // compara metade da palavra inicial com metade da final
		if (palavra[i] != palavra[j]) { // por isso é importante saber o tamnho
			palindromo = 0; // Não é palíndromo 
			break;
		}
	}
	
	if(palindromo) {
		printf("%s é um palíndromo\n", palavra);
	} else {
    	printf("%s não é um palíndromo\n", palavra);
    }
	
}
