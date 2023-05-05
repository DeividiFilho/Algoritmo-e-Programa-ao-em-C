// Escreva um programa em C que leia um vetor de inteiros com 10 elementos, e em seguida 
// encontre o maior valor e a posição desse valor no vetor. Utilize ponteiros para 
// percorrer o vetor e encontrar o maior valor e sua posição. Em seguida, imprima o 
// resultado na tela.

#include <stdio.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");
	int vetor[10];      
	int *ptr = vetor;
	int maior = *ptr;
	int posicao = 0;
	int i;
	
	/* define um vetor de inteiros vetor com 10 elementos. Em seguida, é criado 
	um ponteiro ptr que aponta para o primeiro elemento do vetor. 
	A variável maior é inicializada com o valor apontado por ptr, ou seja, o primeiro 
	elemento do vetor. Isso porque, inicialmente, 
	não sabemos qual é o maior valor e precisamos começar com um valor de referência.
	A variável posicao é inicializada com zero, indicando que o maior valor está na primeira 
	posição do vetor, a menos que encontremos um valor maior em outra posição posterior.*/
	
	// Ler vetores
	printf("Entre com 10 valores inteiros:\n\n");
	for (i = 0; i < 10; i++) {
		printf("Entre com o %d valor: ", i+1);
		scanf("%d", &vetor[i]);
	}
	
	// Percorrendo o vetor
	for (i = 0; i < 10; i++) {
		if(*(ptr + i) > maior) {
			maior = *(ptr + i);
			posicao = i;
		}
	}
	
	// Imprimir
	printf("O maior valor encontrado foi %d na posição %d.\n", maior, posicao);
}



