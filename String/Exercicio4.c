// 4) Altere o programa 1) para imprimir todos os nomesque contenham uma letra qualquer fornecida pelousu�rio

#include <stdio.h>
#include <string.h>

int main() {
  char nomes[10][100];
  char letra;
  int i, j, tamanho;
  int palindromo = 1; // assume q � pal�ndromo

  for (i = 0; i < 10; i++) {
    printf("Digite um nome: ");
    scanf("%s", nomes[i]);
  }

  printf("Digite uma letra: ");
  scanf(" %c", &letra);

  for (i = 0; i < 10; i++) { // printa os nomes que tem a letra inserida pelo usu�rio
    tamanho = strlen(nomes[i]);

    for (j = 0; j < tamanho; j++) {
      if (nomes[i][j] == letra) {
        printf("%s\n", nomes[i]);
        break;
      }
    }
  }
}

