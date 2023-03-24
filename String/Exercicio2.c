// 2) Faça um programa que leia um nome e imprima as4 primeiras letras.

#include <stdio.h>
#include <string.h>

int main() {
  char nome[100];

  printf("Digite um nome: ");
  scanf("%s", nome);

  
  if (strlen(nome) >= 4) { // Verifica se o nome tem menos 4 letras (não pode ter menos pq aí teria letra insuficiente
    printf("As 4 primeiras letras do nome sao: %.4s\n", nome);
  } else {
    printf("O nome tem MENOS de 4 letras!\n");
  }
}

