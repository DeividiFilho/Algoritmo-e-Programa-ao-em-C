#include <stdio.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");
	int num = 10;
	int *ponteiro_num;
	ponteiro_num = &num;
	
	printf("Valor de num: %d\n", num);
  	printf("Endereço de num: %p\n", &num);
  	printf("Valor apontado por ponteiro_num: %d\n", *ponteiro_num);
  	printf("Endereço armazenado em ponteiro_num: %p\n", ponteiro_num);
}
