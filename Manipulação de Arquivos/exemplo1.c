#include <stdio.h>
#include <stdlib.h>
main(){ 
	FILE *fp;
	char string[100]; int i;
	if((fp = fopen("arquivo1.txt","w")) == NULL) {
		printf( "Erro na abertura do arquivo");
		exit(0); // aborta a execução do programa
}

	printf("Entre com a string a ser gravada no arquivo:");
	gets(string);
	fputs(string, fp); /* Grava a string toda de uma só vez*/
	fclose(fp);
}
