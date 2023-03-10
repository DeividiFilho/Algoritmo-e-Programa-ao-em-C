#include <stdio.h>

int main() {
  // Declarando uma matriz de inteiros com 3 linhas e 4 colunas
	int matriz[3][4];
	// Inicializando a matriz com valores
	matriz[0][0] = 1;
	matriz[0][1] = 2;
	matriz[0][2] = 3;
	matriz[0][3] = 4;
	matriz[1][0] = 5;
	matriz[1][1] = 6;
	matriz[1][2] = 7;
	matriz[1][3] = 8;
	matriz[2][0] = 9;
	matriz[2][1] = 10;
	matriz[2][2] = 11;
	matriz[2][3] = 12;
	
	// Imprimindo os valores da matriz
	int i;
	int j;
	printf("Os valores da matriz sao:\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
	      printf("%d ", matriz[i][j]);
	    }
	    printf("\n");
 	}	

  return 0;
}

