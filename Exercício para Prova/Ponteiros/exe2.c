#include <stdio.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");
	char str[10] = "Hello";
	char *ponteiro_str;
	ponteiro_str = str;
	
	printf("Conte�do de str: %s\n", str);
	printf("Endere�o de str: %p\n", &str[0]);
	printf("\n");
	printf("Conte�do apontado por ponteiro_str: %s\n", ponteiro_str);
	printf("Endere�o armazenado em ponteiro_str: %p\n", ponteiro_str);
}
