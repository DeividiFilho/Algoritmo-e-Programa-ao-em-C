//Crie um programa que preencha uma matriz 3x3 
//den�meros inteiros e verifique se a matriz � sim�trica.
//A matriz ser� sim�trica se e somente se todoelemento A[i,j] = A[j,i].

#include <stdio.h>

int main() {
  // Cria��o da matriz 3x3
  int matriz[3][3];
	int i, j;
  // Leitura dos valores para a matriz
  printf("Digite os valores da matriz 3x3:\n");
  for ( i = 0; i < 3; i++) {
    for ( j = 0; j < 3; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }

  // Verifica��o da simetria da matriz
  int simetrica = 1; // Assume que a matriz � sim�trica at� que se prove o contr�rio
  for ( i = 0; i < 3; i++) {
    for ( j = 0; j < i; j++) { // J� verificou essa posi��o na itera��o anterior
      if (matriz[i][j] != matriz[j][i]) {
        simetrica = 0; // Matriz n�o � sim�trica
        break;
      }
    }
    if (!simetrica) {
      break;
    }
  }

  // Impress�o do resultado da verifica��o
  if (simetrica) {
    printf("A matriz e sim�trica.\n");
  } else {
    printf("A matriz N e sim�trica.\n");
  }

  return 0;
}

