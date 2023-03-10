//2- Fa�a um programa que preencha dois vetores A e B 
//com dezelementos num�ricos cada um calcule e apresente 
//um vetor C resultante da intercala��o deles.

#include <stdio.h>

int main() {
  // Defini��o do tamanho dos vetores
  int size = 10;

  // Cria��o dos vetores
  int vetorA[size];
  int vetorB[size];
  int vetorC[size*2]; // Vetor resultante ter� o dobro do tamanho dos vetores A e B
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

  // Intercala��o dos valores dos vetores A e B para o vetor C
  int j = 0; // �ndice para percorrer o vetor A
  int k = 0; // �ndice para percorrer o vetor B
  for ( i = 0; i < size*2; i++) { // O vetor C ter� o dobro do tamanho dos vetores A e B
    if (i % 2 == 0) { // Se o �ndice i for par, pegar um valor do vetor A
      vetorC[i] = vetorA[j];
      j++;
    } else { // Se o �ndice i for �mpar, pegar um valor do vetor B
      vetorC[i] = vetorB[k];
      k++;
    }
  }

  // Impress�o do vetor resultante C
  printf("Vetor resultante C:\n");
  for ( i = 0; i < size*2; i++) {
    printf("%d ", vetorC[i]);
  }
  printf("\n");

  return 0;
}

