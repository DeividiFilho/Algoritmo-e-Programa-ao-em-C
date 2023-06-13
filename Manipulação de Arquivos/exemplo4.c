#include <stdio.h>
#include <stdlib.h>
main()
{ FILE *p;
char c;
if((p = fopen("arquivo1.txt","r")) == NULL) {
printf( "Erro na abertura do arquivo");
exit(0);
}
while(!feof(p)) /* Enquanto não chegar ao final do arquivo*/
{ c = fgetc(p);
printf("%c", c); /* imprime o caractere lido */ }
fclose(p);
system("PAUSE");
}
