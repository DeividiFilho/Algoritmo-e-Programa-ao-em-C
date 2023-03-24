// 5) Faça um programa que leia um nome e escreva o numero de letras que ele possui.

#include <stdio.h>
#include <string.h>

int main() {
  char nome[100];
  int tamanho;

  printf("Digite um nome: ");
  scanf("%s", nome);

  tamanho = strlen(nome);

  printf("O nome %s tem %d letras.\n", nome, tamanho);

  return 0;
}

