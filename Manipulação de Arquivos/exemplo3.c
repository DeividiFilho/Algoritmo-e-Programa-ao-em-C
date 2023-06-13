#include <stdio.h>
#include <stdlib.h>
main()
{ FILE *p;
char c;
if((p = fopen("arquivo.txt","r")) == NULL) {
printf( "Erro na abertura do arquivo");
exit(0);
}
while((c = fgetc(p) ) != EOF) /* Enquanto não chegar ao final do arquivo*/
printf("%c", c); /* imprime o caractere lido */
fclose(p);
system("PAUSE");
}
