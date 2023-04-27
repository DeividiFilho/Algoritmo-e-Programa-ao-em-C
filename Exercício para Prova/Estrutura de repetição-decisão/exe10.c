// Faça um programa em C para ler um número real e exibir uma tabela em que o número
// apareça multiplicado até 200, sendo 10 em cada linha. Esta tabela é útil para deixar
// afixada em lojas de Xerox

#include <stdio.h>
#include <locale.h>

main() {
	setlocale(LC_ALL,"portuguese");

	int i;
	float valor = 0.06;
	float valorTot;
	
	for(i=1; i<=200; i=i+10) {
		valorTot = valor * i;
		printf("\n%d = %d", i, valorTot);
	}
}
