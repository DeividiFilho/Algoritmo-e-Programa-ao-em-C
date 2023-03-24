#include<stdlib.h>
#include<stdio.h>
int main()
{
	int i;
	char nomes[5][40];
	for (i=0; i<5; i++)
	{
		printf("Entre com o nome da linha %d", i);
		gets(nomes[i]);
	}
	for (i=0; i<5; i++)
	{
	printf("\nO nome %d e\n", i);
	puts(nomes[i]);
	}
	//system(“Pause”);
}
