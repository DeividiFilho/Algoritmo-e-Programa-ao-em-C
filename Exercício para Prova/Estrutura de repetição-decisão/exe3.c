// Fa�a um programa que leia v�rios n�meros inteiros informados pelo usu�rio e calcule a m�dia dos n�meros informados. 
// O programa deve parar de ler n�meros quando o usu�rio informar o valor 0.

#include <stdio.h>

main(){
	int num, soma, qntdd;
	float media;
	
	printf("Insira uma numero: ");
	scanf("%d", &num);
	
	while (num != 0) {
		soma += num;
		qntdd++;
		
		printf("Insira uma numero (ou insira 0 para sair) : ");
		scanf("%d", &num);
	}

	if (qntdd == 0) {
        printf("Nenhum numero foi informado.\n");
    } else {
        media = (float) soma / qntdd;
        printf("A media dos numeros informados e: %.2f \n", media);
    }

}
