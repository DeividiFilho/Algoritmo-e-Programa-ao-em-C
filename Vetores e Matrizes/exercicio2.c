//2- Faça um programa que preencha dois vetores A e B 
//com dezelementos numéricos cada um calcule e apresente 
//um vetor C resultante da intercalação deles.

#include <stdio.h>

int main() {
  // Definição do tamanho dos vetores
  int size = 10;

  // Criação dos vetores
  int vetorA[size];
  int vetorB[size];
  int vetorC[size*2]; // Vetor resultante terá o dobro do tamanho dos vetores A e B
  int i;
  
  // Leitura dos valores para o vetor A
  printf("Digite %d valores para o vetor A:\n", size);
  for ( i = 0; i < size; i++) {
    scanf("%d", &vetorA[i]);
  }

  // Leitura dos valores para o vetor B
  printf("Digite %d valores para o vetor B:\n", size);
  for ( i = 0; i < size; i++) {
    scanf("%d", &vetorB[i]);
  }

  // Intercalação dos valores dos vetores A e B para o vetor C
  int j = 0; // Índice para percorrer o vetor A
  int k = 0; // Índice para percorrer o vetor B
  for ( i = 0; i < size*2; i++) { // O vetor C terá o dobro do tamanho dos vetores A e B
    if (i % 2 == 0) { // Se o índice i for par, pegar um valor do vetor A
      vetorC[i] = vetorA[j];
      j++;
    } else { // Se o índice i for ímpar, pegar um valor do vetor B
      vetorC[i] = vetorB[k];
      k++;
    }
  }

  // Impressão do vetor resultante C
  printf("Vetor resultante C:\n");
  for ( i = 0; i < size*2; i++) {
    printf("%d ", vetorC[i]);
  }
  printf("\n");

  return 0;
}

