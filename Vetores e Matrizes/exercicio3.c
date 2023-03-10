//Crie um programa que preencha uma matriz 3x3 
//denúmeros inteiros e verifique se a matriz é simétrica.
//A matriz será simétrica se e somente se todoelemento A[i,j] = A[j,i].

#include <stdio.h>

int main() {
  // Criação da matriz 3x3
  int matriz[3][3];
	int i, j;
  // Leitura dos valores para a matriz
  printf("Digite os valores da matriz 3x3:\n");
  for ( i = 0; i < 3; i++) {
    for ( j = 0; j < 3; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }

  // Verificação da simetria da matriz
  int simetrica = 1; // Assume que a matriz é simétrica até que se prove o contrário
  for ( i = 0; i < 3; i++) {
    for ( j = 0; j < i; j++) { // Já verificou essa posição na iteração anterior
      if (matriz[i][j] != matriz[j][i]) {
        simetrica = 0; // Matriz não é simétrica
        break;
      }
    }
    if (!simetrica) {
      break;
    }
  }

  // Impressão do resultado da verificação
  if (simetrica) {
    printf("A matriz e simétrica.\n");
  } else {
    printf("A matriz N e simétrica.\n");
  }

  return 0;
}

