// Faca um programa que leia um vetor de 8 posic¸oes e, em seguida, leia tamb ˜ em dois va- ´
// lores X e Y quaisquer correspondentes a duas posic¸oes no vetor. Ao final seu programa ˜
// devera escrever a soma dos valores encontrados nas respectivas posic¸ ´ oes ˜ X e Y .

#include <stdio.h>

main() {
	int A[8], B[8], x, y, i, soma;
	
	for(i=0; i<8; i++) {
		printf("Insira o elemento do indice %d para o vetor A: \n", i);
		scanf("%d", &A[i]);
	}
	for(i=0; i<8; i++) {
		printf("Insira o elemento do indice %d para o vetor B: \n", i);
		scanf("%d", &B[i]);
	}
	
	printf("Insira o valor de X: \n");
	scanf("%d", &x);
	printf("Insira o valor de y: \n");
	scanf("%d", &y);
	
	
	
}
