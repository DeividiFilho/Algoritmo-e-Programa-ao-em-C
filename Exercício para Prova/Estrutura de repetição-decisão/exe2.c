//Faça um programa que leia um número inteiro positivo e exiba na tela todos os números pares de 1 até esse número.

#include <stdio.h>

main()
{
	int num, i;
	printf("Insira um numero: \n");
	scanf("%d", &num);
	
    printf("\nNumeros pares de 1 ate %d:\n", num);
	for(i=1; i <= num; i++){
		if(i % 2 ==0)
			printf("%d\n", i);
	}
	
}
