// Escreva um programa que contenha duas variaveis inteiras. Compare seus enderec¸os e ´
// exiba o maior endereço

#include <stdio.h>
#include <locale.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	int a = 5;
	int b = 10;
	int *pont_a;
	int *pont_b;
	pont_a = &a;
	pont_b = &b;
	int maior;
	
	if(pont_a > pont_b) 
		maior = pont_a;
	else 
		maior = pont_b;
	printf("\nConteúdo da variável A: %d\nE seu endereço: %p", a, pont_a);
	printf("\nConteúdo da variável B: %d\nE seu endereço: %p", b, *pont_b);
	printf("\n\nO maior endereço é: %p", maior);
}
