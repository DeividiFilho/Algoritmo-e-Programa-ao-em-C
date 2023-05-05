// Escreva um programa em C que leia um vetor de inteiros com 10 elementos, e em seguida 
// encontre o maior valor e a posi��o desse valor no vetor. Utilize ponteiros para 
// percorrer o vetor e encontrar o maior valor e sua posi��o. Em seguida, imprima o 
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
	
	/* define um vetor de inteiros vetor com 10 elementos. Em seguida, � criado 
	um ponteiro ptr que aponta para o primeiro elemento do vetor. 
	A vari�vel maior � inicializada com o valor apontado por ptr, ou seja, o primeiro 
	elemento do vetor. Isso porque, inicialmente, 
	n�o sabemos qual � o maior valor e precisamos come�ar com um valor de refer�ncia.
	A vari�vel posicao � inicializada com zero, indicando que o maior valor est� na primeira 
	posi��o do vetor, a menos que encontremos um valor maior em outra posi��o posterior.*/
	
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
	printf("O maior valor encontrado foi %d na posi��o %d.\n", maior, posicao);
}



