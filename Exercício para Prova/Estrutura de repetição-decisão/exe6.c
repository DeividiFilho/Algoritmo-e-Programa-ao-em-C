#include <stdio.h>
#include <locale.h>

main(){
	setlocale(LC_ALL,"Portuguese");
	int num, cont, resul;
	
	printf("Insira um n�mero entra 1 e 10: ");
	scanf("%d", &num);
	
	if(num>=1 && num<=10) {
		for(cont=1; cont<=10; cont++) {
			resul = (num*cont);
	        printf("\t %d * %d = %d\n ",num,cont,resul);

		}
	} else
		printf("\n o n�mero n�o est� entre 1 e 10");
}
