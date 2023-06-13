#include <stdio.h>
#include <stdlib.h>
main()
{ FILE *p;
char string[100];
if((p = fopen("arquivo1.txt","r")) == NULL){
printf( "Erro na abertura do arquivo");
exit(0);
}
while(!feof(p)) /* Enquanto não chegar ao final do arquivo*/
{ fgets(string,99,p);
printf("%s", string); /* imprime a string lida */
}
fclose(p);
}
