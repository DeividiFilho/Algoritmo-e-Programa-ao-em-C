#include <stdio.h>
#include <stdlib.h>
main()
{ FILE *fp;
char string[100]; int i;
if((fp = fopen("arquivo.txt","w")) == NULL) {
printf( "Erro na abertura do arquivo");
exit(0); // aborta a execução do programa
}
printf("Entre com a string a ser gravada no arquivo:");
gets(string);
for(i=0; string[i]; i++)
fputc(string[i], fp); /* Grava a string, caractere a caractere */
fclose(fp);
}
