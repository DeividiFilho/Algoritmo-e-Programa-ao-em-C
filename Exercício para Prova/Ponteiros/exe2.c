#include <stdio.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");
	char str[10] = "Hello";
	char *ponteiro_str;
	ponteiro_str = str;
	
	printf("Conteúdo de str: %s\n", str);
	printf("Endereço de str: %p\n", &str[0]);
	printf("\n");
	printf("Conteúdo apontado por ponteiro_str: %s\n", ponteiro_str);
	printf("Endereço armazenado em ponteiro_str: %p\n", ponteiro_str);
}
