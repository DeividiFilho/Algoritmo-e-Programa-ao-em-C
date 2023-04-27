// Faça um programa que leia um número inteiro positivo e calcule o fatorial desse número. 
// O fatorial é o resultado da multiplicação de todos os números inteiros positivos de 1 até o número informado.

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
