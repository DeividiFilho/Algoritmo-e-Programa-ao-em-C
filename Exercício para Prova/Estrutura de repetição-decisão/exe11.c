// Fa�a um programa que pe�a ao usu�rio um n�mero entre 12 e 20. Se a pessoa digitar um n�mero diferente,
// mostrar a mensagem "entrada inv�lida" e solicitar o n�mero novamente. Se digitar correto mostrar o n�mero digitado.

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
