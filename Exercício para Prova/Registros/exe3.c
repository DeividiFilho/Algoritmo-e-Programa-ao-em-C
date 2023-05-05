// Implemente um programa que leia o nome, a idade e o enderec¸o de uma pessoa e
// armazene os dados em uma estrutura.

#include <stdio.h>

typedef struct {
	char nome[100];
	int idade;
	char endereco[100];
} Pessoa;

main() {
	Pessoa pessoa;
	
	printf("Digite o nome: ");
	scanf("%s", &pessoa.nome );
	
	printf("Digite a idade: ");
	scanf("%d", &pessoa.idade);
	
	printf("Digite o endereco: ");
	scanf("%s", &pessoa.endereco);
	
	printf("\nNome: %s\nIdade: %d\nEndereo: %s", pessoa.nome, pessoa.idade, pessoa.endereco);
}
