#include <stdio.h>
#include <stdlib.h>
main()
{ FILE *fp;
int v[10], i, n;
if((fp = fopen(�dados.dat",�rb")) == NULL)
{ printf( "Erro na abertura do arquivo");
exit(0); }
n = fread(v,sizeof(int),10,fp); //l� 10 elementos do arq. e armazena em v
if (n != 10 ) //testa se o n�mero de elementos lidos � diferente de 10
fprintf(stderr, �N�o foi poss�vel ler todos elementos do arquivo");
fclose(fp);
for(i=0; i<n; i++)
printf(�%d\n�, v[i]); // apresentando os dados lidos na tela
}
