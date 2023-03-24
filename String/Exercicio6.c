// 6) Faça um programa que leia o nome e o sobrenomede uma pessoa separadamente. 
// O programa devejuntar as duas strings em uma só e escrever natela:
// a nova string, o seu número de caracteres, asua primeira e a última letra.

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
  printf("Número de caracteres: %d\n", tamanho);
  printf("Primeira letra: %c\n", nome_completo[0]);
  printf("Última letra: %c\n", nome_completo[tamanho-1]);

}

