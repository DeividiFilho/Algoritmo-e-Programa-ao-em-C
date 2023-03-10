// Escreva um programa que declare um vetor com n=10
// números reais e coloque na i-ésima posição 
// o resultado de i*(n-1)

#include <stdio.h>

const int n=10;

main()
{
	float vetor[n];
	int i;
	
	for(i=0; i<n; i++)
		vetor[i] = i*(n-1);
		
	for(i=0; i<n; i++)
		printf("%f\n", vetor[i]);	
}
