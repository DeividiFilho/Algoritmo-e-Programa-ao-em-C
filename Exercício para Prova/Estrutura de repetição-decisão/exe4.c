// Fa�a um programa que leia um n�mero inteiro positivo e calcule o fatorial desse n�mero. 
// O fatorial � o resultado da multiplica��o de todos os n�meros inteiros positivos de 1 at� o n�mero informado.

#include <stdio.h>

main(){
	int num, i, fat;
	
	printf("Insira um numero (acima de 0) para calcular seu FATORIAL: ");
	scanf("%d", &num);
	
	for(i = 1; i<num; i++){
		fat *= i;
	}
	printf("\n %d! = %d", num, fat);
}
