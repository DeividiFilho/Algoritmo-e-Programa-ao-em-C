// Faça um programa que peça ao usuário um número entre 12 e 20. Se a pessoa digitar um número diferente,
// mostrar a mensagem "entrada inválida" e solicitar o número novamente. Se digitar correto mostrar o número digitado.

#include <stdio.h>

main() {
	int num;
	
	printf("Insira um numero entre 12 e 20: ");
	scanf("%d", &num);
	
	if(num >= 12 && num <= 20)
		printf("O numero inserido: %d", num);
	else 
		printf("numero invalido");
}
