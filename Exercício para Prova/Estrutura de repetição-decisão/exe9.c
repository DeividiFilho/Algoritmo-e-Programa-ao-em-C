// Faça um programa em C para exibir a tabuada de 0 a 9.

#include <stdio.h>

main() {
	int i, j, mult;
	
	for(i=0; i<10; i++) {
		printf("\n\nTabuada do %d", i);
		for(j=0; j<10; j++) {
			mult = i*j;
			printf("\n%d x %d = %d", i, j, mult); 
		}
	}
}
