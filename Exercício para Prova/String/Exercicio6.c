// 6) Fa�a um programa que leia o nome e o sobrenomede uma pessoa separadamente. 
// O programa devejuntar as duas strings em uma s� e escrever natela:
// a nova string, o seu n�mero de caracteres, asua primeira e a �ltima letra.

#include <stdio.h>
#include <string.h>

int main() {
  char nome[100], sobrenome[100], nome_completo[200];
  int tamanho;

  printf("Digite seu nome: ");
  scanf("%s", nome);

  printf("Digite seu sobrenome: ");
  scanf("%s", sobrenome);

  
  strcpy(nome_completo, nome); // concatena as strings
  strcat(nome_completo, " ");
  strcat(nome_completo, sobrenome);

  tamanho = strlen(nome_completo); // o tamanho da nova string


  printf("\nNome completo: %s\n", nome_completo);
  printf("N�mero de caracteres: %d\n", tamanho);
  printf("Primeira letra: %c\n", nome_completo[0]);
  printf("�ltima letra: %c\n", nome_completo[tamanho-1]);

}

