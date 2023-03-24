// 1) Fa�a um programa que receba uma palavra everifique se ela � um pal�ndromo, ou seja,
// se escritado fim para o come�o � igual � palavra escrita docome�o para o fim. Exemplo: 
// RENNER, ANA, MIRIM, OVO, etc

#include <stdio.h>
#include <string.h>

int main(){
	char palavra[100];
	int i, j, tamanho;
	int palindromo = 1; // assume q � pal�ndromo
	

	printf("Digite uma palavra: ");
	scanf("%s", palavra);
	
	tamanho = strlen(palavra);
	
	for( i=0, j = tamanho - 1; i < tamanho / 2, i++;) { // compara metade da palavra inicial com metade da final
		if (palavra[i] != palavra[j]) { // por isso � importante saber o tamnho
			palindromo = 0; // N�o � pal�ndromo 
			break;
		}
	}
	
	if(palindromo) {
		printf("%s � um pal�ndromo\n", palavra);
	} else {
    	printf("%s n�o � um pal�ndromo\n", palavra);
    }
	
}
