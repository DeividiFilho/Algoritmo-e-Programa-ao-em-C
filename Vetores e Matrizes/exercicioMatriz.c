//Escreva um programa que leia duas matrizes 3x3 
//e realize a soma dessas matrizes. Em seguida,
//o programa deve imprimir a matriz resultante.

#include <stdio.h>

int main(){
	int a[3][3];
	int b[3][3];
	int c[3][3];
	int i, j;
	
	
	printf("Preencha a matriz A:\n");
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
            printf("Digite o elemento [%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	
	printf("\nPreencha a matriz B:\n");
	for (i=0; i<3; i++){
		for(j=0; j<3; j++){
            printf("Digite o elemento [%d][%d]: ", i, j);
			scanf("%d", &b[i][j]);
		}
	}
	
	for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[i][j] = a[i][j] + b[i][j];
    	}
	}
				
	printf("A soma das matrizes A e B :\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
		}
		printf("\n");

	}
}

