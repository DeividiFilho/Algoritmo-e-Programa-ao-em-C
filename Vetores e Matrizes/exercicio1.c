#include <stdio.h>
#include <locale.h>

int main() {
  // Defini��o do tamanho m�ximo dos vetores
  int max_size = 8;
  setlocale(LC_ALL,"Portuguese");

  // Cria��o dos vetores
  int vetor[max_size];
  int vetor_pos[max_size];
  int vetor_neg[max_size];
	int i;
  // Leitura dos valores para o vetor principal
  printf("Digite %d valores para o vetor:\n", max_size);
  for (i = 0; i < max_size; i++) {
    scanf("%d", &vetor[i]);
  }

  printf("O vetor inicial �:\n");
  for(i=0; i<max_size; i++){
  	printf(" %d", vetor[i]);

  }
  // Preenchimento dos vetores de n�meros positivos e negativos
  int pos_count = 0;
  int neg_count = 0;
  for (i = 0; i < max_size; i++) {
    if (vetor[i] >= 0) {
      vetor_pos[pos_count] = vetor[i];
      pos_count++;
    } else {
      vetor_neg[neg_count] = vetor[i];
      neg_count++;
    }
  }

  // Impress�o dos vetores de n�meros positivos e negativos
  printf("\nVetor de n�meros positivos:\n");
  for ( i = 0; i < pos_count; i++) {
    printf("%d ", vetor_pos[i]);
  }
  printf("\n");

  printf("Vetor de n�meros negativos:\n");
  for ( i = 0; i < neg_count; i++) {
    printf("%d ", vetor_neg[i]);
  }
  printf("\n");

  return 0;
}

