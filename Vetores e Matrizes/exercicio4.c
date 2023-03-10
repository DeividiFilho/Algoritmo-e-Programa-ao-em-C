#include <stdio.h>

int main() {
  int n;
  int i, j;
  // Leitura do tamanho da matriz
  printf("Digite o tamanho da matriz n x n: ");
  scanf("%d", &n);

  // Criação da matriz n x n
  int matriz[n][n];

  // Leitura dos valores para a matriz
  printf("Digite os valores da matriz %d x %d:\n", n, n);
  for ( i = 0; i < n; i++) {
    for ( j = 0; j < n; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }

  // Verificação da matriz identidade
  int identidade = 1; // Assume que a matriz é identidade até que se prove o contrário
  for ( i = 0; i < n; i++) {
    for ( j = 0; j < n; j++) {
      if (i == j && matriz[i][j] != 1) {
        identidade = 0; // Elemento da diagonal principal diferente de 1
        break;
      } else if (i != j && matriz[i][j] != 0) {
        identidade = 0; // Elemento fora da diagonal principal diferente de 0
        break;
      }
    }
    if (!identidade) {
      break;
    }
  }

  // Impressão do resultado da verificação
  if (identidade) {
    printf("A matriz e identidade.\n");
  } else {
    printf("A matriz N e identidade.\n");
  }

  return 0;
}

