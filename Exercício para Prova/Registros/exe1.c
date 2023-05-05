// Funcioanrio de uma empresa

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Funcionario {
	char nome[50];
	int idade;
	float salario;
};


int main() {
	struct Funcionario f;
	strcpy(f.nome, "Deividi Filho");
	f.idade = 20;
	f.salario = 25000.0;
	
	printf("Nome: %s\n", f.nome);
	printf("Idade: %d\n", f.idade);
	printf("Salario: %.2f\n", f.salario);
	
	return 0;
}
