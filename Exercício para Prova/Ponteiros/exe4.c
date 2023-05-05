/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de ´
cada variavel usando os ponteiros. Imprima os valores das vari ´ aveis antes e ap ´ os a ´
modificação */

#include <stdio.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");
	int i = 5;
	float f = 3.14;
	char c = 'a';
	
	int *ptr_i = &i;
	float *ptr_f = &f;
	char *ptr_c = &c;
	
	printf("Valor inicial de i: %d\n", i);
	printf("Valor inicial de f: %f\n", f);
	printf("Valor inicial de c: %c\n", c);
	
	*ptr_i = 10;
	*ptr_f = 2.71;
	*ptr_c = 'd';
	
	printf("\nNovo valor de i: %d\n",i);
	printf("Novo valor de f: %d\n",f);
	printf("Novo valor de c: %d\n",c);
	
}
