/* PROVA PR�TICA DE AP2S2 - I SEM DE 2023 - 05/05/2023

	Deividi Douglas de Carlo Filho - SC3029948 
	Iniciando: 19h30
	Terminando:
	
	ATEN��O: VOC� N�O DEVE MODIFICAR OS PROT�TIPOS DAS FUN��ES. 
	N�o ser� permitido o uso de vari�veis globais dentro das fun��es. 
*/
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char nome[40], cpf[15], cel[15], cidade[40]; 	
} Cliente;
/*QUEST�O 1 (1.5): Implemente a fun��o inserir_contato_cliente que recebe por par�metro um ponteiro para um vetor
com capacidade para at� 200 registros de cliente e um ponteiro para a posi��o do vetor na qual o registro 
ser� inserido pela fun��o. A fun��o dever� retornar 1, caso o contato tenha sido inclu�do com sucesso e -1, 
caso contr�rio. A mensagem informando se o contato foi inclu�do com sucesso
ou n�o ser� impressa na fun��o submenu_agenda_clientes().*/
int inserir_contato_cliente(Cliente agenda_cli[], int *i) 
{   
	printf("\nInserindo um novo contato na agenda:\n");
	
	// Para limitar o n�mero m�ximo de clientes
	if (*i >= 200) { 
    	printf("Erro: a capacidade m�xima de registros j� foi atingida.\n");
        return -1;
    }
    
    // Cria novo_contato de tipo Cliente;
    Cliente novo_contato; 
    printf("Digite o nome do contato: ");
    scanf("%s", novo_contato.nome);
    printf("Digite o cpf: ");
    scanf("%s", novo_contato.cpf);
    printf("Digite n�mero do celular: ");
    scanf("%s", novo_contato.cel);
    printf("Digite a cidade: ");
    scanf("%s", novo_contato.cidade);
    
    agenda_cli[] = novo_contato;
    (*i)++;
    
    printf("Contato inserido com sucesso.\n");
    return 1;
    // Testei e funcionou 
} 

/*QUEST�O 2 (1.0): Implemente a fun��o buscar_contato_cliente que receba por par�metro um ponteiro para um vetor
com registros de clientes, o cpf do cliente e um contador, indicando a quantidade de contatos armazenados
no vetor. Caso o cpf esteja cadastrado, a fun��o dever� retornar o �ndice do registro no vetor. Caso n�o encontre,
a fun��o dever� retornar -1. A mensagem informando que o cpf do cliente n�o foi encontrado 
(quando acontecer) deve ser impressa na fun��o submenu_agenda_clientes().*/
int buscar_contato_cliente(Cliente agenda_cli[], char cpf[], int cont)
{	
	// Buscando o contato 
	printf("\nBuscando um contato na agenda de clientes:\n");
	
	int i;
	char cpf_contato;
    for (i = 0; i < cont; i++) {
        if (strcmp(agenda_cli[i].cpf, cpf) == 0) {
            return 1;
        }
    }
    printf("O contato \"%s\" n�o foi encontrado.\n", cpf_contato);
    return -1;
}
/*QUEST�O 3 (1.5): Implemente a fun��o imprimir_contato_cliente() que receba por par�metro um ponteiro para um vetor
com registros de clientes e o contador de contatos cadastrados. A fun��o dever� solicitar o cpf do contato
como entrada e dever� transferir esse cpf, juntamente com o vetor agenda_cli, por par�metros para a fun��o 
buscar_contato_cliente(), que verificar� se esse cpf est� cadastrado. Se o retorno da fun��o buscar_contato_cliente() 
for maior ou igual a zero (ou seja, um �ndice v�lido), a fun��o imprimir_contato_cliente() dever� imprimir o nome, o celular,
e a cidade do cliente. Caso o retorno seja -1, a fun��o dever� apresentar uma mensagem 
informando que o cpf do cliente n�o foi localizado na agenda.*/
void imprimir_contato_cliente(Cliente agenda_cli[], int cont)
{	
	printf("\nImprimindo um contato da agenda:\n");
	
	char cpf_contato[15];
    printf("Digite o n�mero do CPF do contato que deseja imprimir: ");
    scanf("%s", cpf_contato);
    
    // Vou usar a fun��o buscar_contato_cliente esccrita acima para encontrar o CPF e imprimr
    int indice_contato = buscar_contato_cliente(Cliente agenda_cli[], char cpf[], int cont); 
    if (indice_contato >= 0) {
        printf("Nome: %s\n", agenda_cli[indice_contato].nome);
        printf("Celular: %s\n", agenda_cli[indice_contato].cel);
        printf("Cidade: %s\n", agenda_cli[indice_contato].cidade);
    } else {
    	printf("CPF do cliente n�o foi localizado na agenda");
    	return -1;
	}
	// Para imprimir, usei o vettor agenda_cli e o �ndice foi o cpf buscado;
}			    		

/*QUEST�O 4 (1.75): Implemente a fun��o excluir_contato_cliente() que receber� por par�metro um ponteiro para um vetor
com registros de clientes e um ponteiro para o contador de contatos cadastrados. A fun��o dever� solicitar o cpf do contato
a ser exclu�do. Em seguida dever� transferir esse cpf, juntamente com o vetor agenda_cli, por par�metro para a fun��o 
buscar_contato_cliente(), que verificar� se esse cpf est� cadastrado. Se o retorno da fun��o buscar_contato_cliente() 
for maior ou igual a zero (ou seja, um �ndice v�lido), a fun��o imprimir_contato_cliente() dever� excluir o 
contato do vetor agenda_cli. Caso o retorno seja -1, a fun��o excluir_contato_cliente
dever� apresentar uma mensagem informando que o cpf n�o foi localizado na agenda de contatos.*/
void excluir_contato_cliente(Cliente agenda_cli[], int *cont)
{	
	//printf("\nImprimindo um contato da agenda:\n"); // � para excluir n�o?
	printf("\nExcluindo um contato da agenda:\n");
	
	int i;
	char cpf_contato[15];
	printf("Digite o n�mero do CPF do contato que deseja excluir: ");
	scanf("%s", cpf_contato);
	
	// Vou usar a fun��o Bucar_contato_cliente novaaemnte e for para deletar o contato
	int indice_contato = buscar_contato_cliente(Cliente agenda_cli[], char cpf[], int cont);
	if (indice_contato >= 0) {                             // Se encontrou o CPF, exclu� 
		for (i = indice_contato; i < cont - 1; i++) {
			agenda_cli[i] = agenda_cli[i+1];
		}
		(*cont)--;
		printf("O contato \"%s\" foi exclu�do!.\n", cpf_contato);
		return 1;
	} else {
		printf("N�o foi poss�vel excluir.\nO contato \"%d\" n�o foi encontrado na agenda!", cpf_contato);
		return -1;
	}
}

/*QUEST�O 5 (1.75): Desenvolva o c�digo da fun��o imprimir_vetor() que receber� por par�metro um 
ponteiro para um vetor com 100 elementos inteiros e percorrer� esse vetor imprimindo os seus 
elementos. Para percorrer o vetor, a fun��o dever� usar 4 ponteiros (p,q,r,s) de forma SIMULT�NEA 
posicionados conforme seguem:
p: deve iniciar na posi��o 0
q: deve iniciar na posi��o 25
r: deve iniciar na posi��o 50
s: deve iniciar na posi��o 75
*/
void imprimir_vetor(int *vet)
{	
	printf("\nImprimindo o vetor de inteiros usando quatros ponteiros\n");
	
	// Fiz como se fosse para imprimir normal, mas coloque os ponteiros em suas posi��es e incrementa em 1
	// p = 0; q = 25; r = 50; s = 75;
	int *p = vet, *q = vet + 25, *r = vet + 50, *s = vet + 75;
	int i;
    for ( i = 0; i < 25; i++) {
        printf("%d ", *p++);
        printf("%d ", *q++);
        printf("%d ", *r++);
        printf("%d ", *s++);
        printf("\n");
    }
	
}

/*QUEST�O 6 (1.25): Desenvolva o c�digo da fun��o preencher_vetor() que receber� um ponteiro para 
um vetor de inteiros (vazio) por par�metro e o preencher� automaticamente com 100 valores inteiros.*/
void preencher_vetor(int *vet)
{	
	printf("\nPreenchendo automaticamente o vetor de inteiros\n");
	
	// Esse � a mais fac�l, parece que tem alguma pegadinha hahahahah
	int i;
    for (i = 0; i < 100; i++) {
        vet[i] = i + 2; // Para sempre ser n�mero par;
    }
	
}

//Fun��o menu(): fun��o que apresenta o menu de op��es para o usu�rio
void menu(){
	printf("**************Menu de Op��es:****************\n\n");
	printf("\t1. Acessar submenu Agenda de Clientes\n");
	printf("\t2. Imprimir vetor de inteiros usando ponteiros\n");
	printf("\t3. Sair\n");
	printf("\nEscolha uma op��o (1 ou 2) ou digite 3 para encerrar o programa\n");
}
//Chamada das fun��es: (0.75)
void submenu_agenda_clientes(Cliente contatos[], int *cont){
	int op, flag;
	
	do
	{		
		printf("**************Submenu Agenda de Clientes:****************\n\n");
		printf("\t1. Inserir o contato de um novo cliente na Agenda\n");
		printf("\t2. Imprimir dados de um contato\n");
		printf("\t3. Remover o contato de um cliente da Agenda\n");
		printf("\t4. Voltar ao menu principal\n");
		printf("\nEscolha uma op��o entre 1 e 3 ou digite 4 para voltar ao menu principal\n");
		scanf("%d",&op);
	
		switch (op){
			case 1:	
				inserir_contato_cliente(Cliente agenda_cli[], int *i)	
				break;	
			// Novamente parece muito fac�l, tem pegadinha n�? KKKK				
			case 2:
				buscar_contato_cliente(agenda_cli, cpf, cont)
				break;
			// Na duvida, vou colocar uma de cada pq a� uma ctz q acerto
			case 3:
				excluir_contato_cliente(Cliente agenda_cli[],  *cont)
				break;
			case 4:
				printf("Voltando para o menu principal\n");
				break;
			default: printf("Op��o incorreta!\n");		
		}	
	} while(op >= 1 && op <3);
}

//Chamada das fun��es: (0.5)
main()
{	int op, cont = 0;
	Cliente contatos_cli[200];  
	setlocale(LC_ALL, "Portuguese");
		
	do
	{	
		menu();
		scanf("%d",&op);
		fflush(stdin);
		switch (op){
			case 1: system("cls");
			   //CHAMANDO O SUBMENU COM OP��ES PARA GERENCIAR AGENDA DE CLIENTES
				submenu_agenda_clientes(contatos_cli,&cont);			
				break;
			case 2: system("cls");
			   int vetor[100];
			   preencher_vetor(int *vet)
			   imprimir_vetor(int*vet)
			    // Prencher e imprimir; Novamente parece pegadinha
			   break;	
			case 3: system("cls");
			   printf("\nEncerrando o programa...\n"); 
			   break;
			default: printf("Op��o incorreta!\n");
		}	
	} while (op >= 1 && op <3);	
}

// Se for poss�vel, gostaria de tirar algumas d�vidas que fiquei durante a prova. Vou refazer a prova em casa :) 
// Estou travado e n�o consigo ir al�m. 
