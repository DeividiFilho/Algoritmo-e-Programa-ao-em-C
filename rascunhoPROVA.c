/* PROVA PR�TICA DE AP2S2 - II SEM DE 2022 - 17/10/2022
	Deividi Douglas de Carlo Filho -- SC3029948
	
	ATEN��O: VOC� N�O DEVE MODIFICAR OS PROT�TIPOS DAS FUN��ES. 
	N�o ser� permitido o uso de vari�veis globais dentro das fun��es. 
*/
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char nome[40];
	char tel_fixo[15], cel[15], cidade [40]; 	
} Pessoa;
/*struct Pessoa {
	char nome[40];
	char tel_fixo[15], cel[15], cidade [40]; 
} ; /*

/*QUEST�O 1 (2.0): Implemente a fun��o inserir_contato() que recebe por par�metro um ponteiro para um vetor
com capacidade para at� 200 registros de pessoas e um ponteiro para a posi��o do vetor na qual o registro 
ser� inserido pela fun��o. A fun��o dever� retornar 1, caso o contato tenha sido inclu�do com sucesso e -1, 
caso contr�rio. A mensagem informando se o contato foi inclu�do com sucesso
ou n�o ser� impressa na fun��o submenu_agenda_contatos().*/

int inserir_contato(Pessoa* vetor_contatos, int* posicao_atual) {
    if (*posicao_atual >= 200) {
        printf("Erro: a capacidade m�xima de registros j� foi atingida.\n");
        return -1;
    }
    
    Pessoa novo_contato;
    printf("Digite o nome do contato: ");
    scanf("%s", novo_contato.nome);
    printf("Digite o telefone do contato: ");
    scanf("%s", novo_contato.tel_fixo);
    
    vetor_contatos[*posicao_atual] = novo_contato;
    (*posicao_atual)++;
    
    printf("Contato inserido com sucesso.\n");
    return 1;
}


/*QUEST�O 2 (1.0): Implemente a fun��o buscar_contato() que receba por par�metro um ponteiro para um vetor
com registros de pessoas, o nome do contato e o contador indicando a quantidade de contatos armazenados
no vetor. A fun��o dever� retornar a posi��o (�ndice) do primeiro registro encontrado com aquele nome, 
caso ele exista e -1, caso ele n�o seja encontrado. A mensagem informando que o nome n�o foi encontrado 
(quando acontecer) deve ser impressa imprimir_contatos().*/

int buscar_contato(Pessoa* vetor_contatos, char* nome_contato, int num_contatos) {
	int i;
    for (i = 0; i < num_contatos; i++) {
        if (strcmp(vetor_contatos[i].nome, nome_contato) == 0) {
            return i;
        }
    }
    printf("O contato \"%s\" n�o foi encontrado.\n", nome_contato);
    return -1;
}


/*QUEST�O 3 (1.0): Implemente a fun��o imprimir_contato() que receba por par�metro um ponteiro para um vetor
com registros de pessoas e o contador de contatos cadastrados. A fun��o dever� solicitar o nome do contato
como entrada e dever� transferir esse nome, juntamente com o vetor de contatos, por par�metros para a fun��o 
buscar_contato(), que verificar� se esse nome est� cadastrado. Se o retorno da fun��o buscar_contato() 
for maior ou igual a zero (ou seja, um �ndice v�lido), a fun��o imprimir_contato() dever� imprimir o telefone fixo,
o celular e a cidade daquele contato. Caso o retorno seja -1, deve apresentar uma mensagem 
informando que o nome n�o foi localizado na agenda de contatos.*/

void imprimir_contato(Pessoa* vetor_contatos, int num_contatos) {
    char nome_contato[100];
    printf("Digite o nome do contato que deseja visualizar: ");
    scanf("%s", nome_contato);
    
    int indice_contato = buscar_contato(vetor_contatos, nome_contato, num_contatos);
    if (indice_contato >= 0) {
        printf("Telefone fixo: %s\n", vetor_contatos[indice_contato].tel_fixo);
        printf("Telefone celular: %s\n", vetor_contatos[indice_contato].cel);
        printf("Cidade: %s\n", vetor_contatos[indice_contato].cidade);
    }
}
	    		

/*QUEST�O 4 (2.0): Implemente a fun��o excluir_contato() que recebe por par�metro um ponteiro para um vetor
de pessoas e um ponteiro para o contador de contatos cadastrados. A fun��o dever� retornar 1, caso o contato 
tenha sido exclu�do com sucesso e -1, caso o contato n�o tenha sido encontrado. A mensagem informando se o 
contato foi exclu�do ou n�o deve ser impressa pela fun��o submenu_agenda_contatos().
OBS: utilize a fun��o buscar_contato() para verificar se o contato existe na agenda. */

int excluir_contato(Pessoa* vetor_contatos, int* num_contatos) {
	int i;
    char nome_contato[100];
    printf("Digite o nome do contato que deseja excluir: ");
    scanf("%s", nome_contato);

    int indice_contato = buscar_contato(vetor_contatos, nome_contato, *num_contatos);
    if (indice_contato >= 0) {
        for (i = indice_contato; i < *num_contatos - 1; i++) {
            vetor_contatos[i] = vetor_contatos[i+1];
        }
        (*num_contatos)--;
        printf("O contato \"%s\" foi exclu�do com sucesso.\n", nome_contato);
        return 1;
    } else {
        printf("O contato \"%s\" n�o foi encontrado na agenda de contatos.\n", nome_contato);
        return -1;
    }
}


/*QUEST�O 5 (2.0): Desenvolva o c�digo da fun��o imprimir_vetor() que receber� por par�metro um 
ponteiro para um vetor com 100 elementos inteiros e percorrer� esse vetor imprimindo os seus 
elementos. Para percorrer o vetor, a fun��o dever� usar 4 ponteiros (p,q,r,s) de forma SIMULT�NEA 
posicionados conforme seguem:
p: deve iniciar na posi��o 0
q: deve iniciar na posi��o 25
r: deve iniciar na posi��o 50
s: deve iniciar na posi��o 75
*/

void imprimir_vetor(int* vetor) {
    int *p = vetor, *q = vetor + 25, *r = vetor + 50, *s = vetor + 75;
	int i;
    for ( i = 0; i < 25; i++) {
        printf("%d ", *p++);
        printf("%d ", *q++);
        printf("%d ", *r++);
        printf("%d ", *s++);
        printf("\n");
    }
}


/*QUEST�O 6 (0.75): Desenvolva o c�digo da fun��o preencher_vetor() que receber� um ponteiro para 
um vetor vazio por par�metro e o preencher� automaticamente com 100 valores inteiros.*/
void preencher_vetor(int* vetor) {
	int i;
    for (i = 0; i < 100; i++) {
        vetor[i] = i + 1;
    }
}


//Fun��o menu(): fun��o que apresenta o menu de op��es para o usu�rio
void menu(){
	printf("**************Menu de Op��es:****************\n\n");
	printf("\t1. Acessar submenu Agenda de Contatos\n");
	printf("\t2. Imprimir vetor usando 4 ponteiros\n ");
	printf("\t3. Sair\n");
	printf("\nEscolha uma op��o entre 1 e 2 ou digite 3 para encerrar o programa\n");
}
//Chamada das fun��es: (0.75)
void submenu_agenda_contatos(Pessoa contatos[], int *cont){
	int op, flag;
	
	do
	{		
		printf("**************Submenu Agenda:****************\n\n");
		printf("\t1. Inserir contato na agenda\n ");
		printf("\t2. Imprimir dados de um contato\n");
		printf("\t3. Excluir um contato\n");
		printf("\t4. Voltar ao menu principal\n");
		printf("\nEscolha uma op��o entre 1 e 3 ou digite 4 para voltar ao menu principal\n");
		scanf("%d",&op);
	
		switch (op){
		case 1:
		/*INSIRA AQUI A CHAMADA DA FUN��O inserir_contato_agenda(), RESPEITANDO OS 
		PAR�METROS CONFORME O PROT�TIPO DA FUN��O*/		
			inserir_contato_agenda(contatos, cont);	
			break;					
		case 2:
		/*INSIRA AQUI A CHAMADA DA FUN��O imprimir_contato(), RESPEITANDO OS 
		PAR�METROS CONFORME O PROT�TIPO DA FUN��O*/
			imprimir_contato(contatos, *cont);
			break;
		case 3:
		/*INSIRA AQUI A CHAMADA DA FUN��O excluir_contato(), RESPEITANDO OS 
		PAR�METROS CONFORME O PROT�TIPO DA FUN��O*/
			excluir_contato(contatos, cont);
			break;
		case 4:
			printf("Voltando para o menu principal\n");
			break;
		default: printf("Op��o incorreta!\n");		
	}	
	} while(op >= 1 && op <4);
}

//Chamada das fun��es: (0.5)
main()
{	int op, cont = 0;
	Pessoa Agenda[200];  
	setlocale(LC_ALL, "Portuguese");
		
	do
	{	
		menu();
		scanf("%d",&op);
		fflush(stdin);
		switch (op){
			case 1: 
			system("cls");
			//CHAMANDO O SUBMENU AGENDA
			submenu_agenda_contatos(Agenda, &cont);
			break;
		case 2: 
			system("cls");
			int vetor[100];
		    /*INSIRA AQUI AS CHAMADAS DAS FUN��ES preencher_vetor() e imprimir_vetor(), RESPEITANDO OS 
		    PAR�METROS E O VALOR DE RETORNO (QUANDO HOUVER), CONFORME O PROT�TIPO DE CADA FUN��O*/
		    preencher_vetor(vetor);
		    imprimir_vetor(vetor);
		    break;
		case 3: 
			system("cls");
			printf("\nEncerrando o programa...\n"); 
			break;
		default: 
			printf("Op��o incorreta!\n");
	}	
	
	} while (op >= 1 && op <3);	
}

