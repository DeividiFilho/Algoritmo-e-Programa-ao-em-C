// 2. Crie um programa que le 6 valores inteiros e, em seguida, mostre na tela os valores lidos. ˆ

#include <stdio.h>

main() {
	int A[6];
	int i;
	
	
	for(i = 0; i < 6; i++) {
		printf("Insira o valor do indice %d : ", i);
		scanf("%d", &A[i]);	
	}
	
	printf("\nO vetor:\n\n");
	
	for(i = 0; i < 6; i++) {
		printf("%d ", A[i]);
	}	
}
