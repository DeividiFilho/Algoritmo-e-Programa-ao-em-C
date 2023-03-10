#include <stdio.h>

int main() {
  int m, n, p;
  int i, j, k;
  // Leitura das dimensões da matriz A
  printf("Digite as dimensões da matriz A (m x n): ");
  scanf("%d %d", &m, &n);

  // Criação da matriz A
  int A[m][n];

  // Leitura dos valores para a matriz A
  printf("Digite os valores da matriz A %d x %d:\n", m, n);
  for ( i = 0; i < m; i++) {
    for ( j = 0; j < n; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  // Leitura das dimensões da matriz B
  printf("Digite as dimensões da matriz B (n x p): ");
  scanf("%d %d", &n, &p);

  // Criação da matriz B
  int B[n][p];

  // Leitura dos valores para a matriz B
  printf("Digite os valores da matriz B %d x %d:\n", n, p);
  for ( i = 0; i < n; i++) {
    for ( j = 0; j < p; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  // Criação da matriz C, resultante da multiplicação de A por B
  int C[m][p];

  // Multiplicação de A por B
  for ( i = 0; i < m; i++) {
    for ( j = 0; j < p; j++) {
      int soma = 0;
      for ( k = 0; k < n; k++) {
        soma += A[i][k] * B[k][j];
      }
      C[i][j] = soma;
    }
  }

  // Impressão da matriz C resultante
  printf("Matriz resultante C %d x %d:\n", m, p);
  for ( i = 0; i < m; i++) {
    for ( j = 0; j < p; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }

  return 0;
}

