/* PROVA PRÁTICA DE AP2S2 - I SEM DE 2023 - 05/05/2023

	Deividi Douglas de Carlo Filho - SC3029948 
	Iniciando: 19h30
	Terminando:
	
	ATENÇÃO: VOCÊ NÃO DEVE MODIFICAR OS PROTÓTIPOS DAS FUNÇÕES. 
	Não será permitido o uso de variáveis globais dentro das funções. 
*/
#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char nome[40], cpf[15], cel[15], cidade[40]; 	
} Cliente;
/*QUESTÃO 1 (1.5): Implemente a função inserir_contato_cliente que recebe por parâmetro um ponteiro para um vetor
com capacidade para até 200 registros de cliente e um ponteiro para a posição do vetor na qual o registro 
será inserido pela função. A função deverá retornar 1, caso o contato tenha sido incluído com sucesso e -1, 
caso contrário. A mensagem informando se o contato foi incluído com sucesso
ou não será impressa na função submenu_agenda_clientes().*/
int inserir_contato_cliente(Cliente agenda_cli[], int *i) 
{   
	printf("\nInserindo um novo contato na agenda:\n");
	
	// Para limitar o número máximo de clientes
	if (*i >= 200) { 
    	printf("Erro: a capacidade máxima de registros já foi atingida.\n");
        return -1;
    }
    
    // Cria novo_contato de tipo Cliente;
    Cliente novo_contato; 
    printf("Digite o nome do contato: ");
    scanf("%s", novo_contato.nome);
    printf("Digite o cpf: ");
    scanf("%s", novo_contato.cpf);
    printf("Digite número do celular: ");
    scanf("%s", novo_contato.cel);
    printf("Digite a cidade: ");
    scanf("%s", novo_contato.cidade);
    
    agenda_cli[] = novo_contato;
    (*i)++;
    
    printf("Contato inserido com sucesso.\n");
    return 1;
    // Testei e funcionou 
} 

/*QUESTÃO 2 (1.0): Implemente a função buscar_contato_cliente que receba por parâmetro um ponteiro para um vetor
com registros de clientes, o cpf do cliente e um contador, indicando a quantidade de contatos armazenados
no vetor. Caso o cpf esteja cadastrado, a função deverá retornar o índice do registro no vetor. Caso não encontre,
a função deverá retornar -1. A mensagem informando que o cpf do cliente não foi encontrado 
(quando acontecer) deve ser impressa na função submenu_agenda_clientes().*/
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
    printf("O contato \"%s\" não foi encontrado.\n", cpf_contato);
    return -1;
}
/*QUESTÃO 3 (1.5): Implemente a função imprimir_contato_cliente() que receba por parâmetro um ponteiro para um vetor
com registros de clientes e o contador de contatos cadastrados. A função deverá solicitar o cpf do contato
como entrada e deverá transferir esse cpf, juntamente com o vetor agenda_cli, por parâmetros para a função 
buscar_contato_cliente(), que verificará se esse cpf está cadastrado. Se o retorno da função buscar_contato_cliente() 
for maior ou igual a zero (ou seja, um índice válido), a função imprimir_contato_cliente() deverá imprimir o nome, o celular,
e a cidade do cliente. Caso o retorno seja -1, a função deverá apresentar uma mensagem 
informando que o cpf do cliente não foi localizado na agenda.*/
void imprimir_contato_cliente(Cliente agenda_cli[], int cont)
{	
	printf("\nImprimindo um contato da agenda:\n");
	
	char cpf_contato[15];
    printf("Digite o número do CPF do contato que deseja imprimir: ");
    scanf("%s", cpf_contato);
    
    // Vou usar a função buscar_contato_cliente esccrita acima para encontrar o CPF e imprimr
    int indice_contato = buscar_contato_cliente(Cliente agenda_cli[], char cpf[], int cont); 
    if (indice_contato >= 0) {
        printf("Nome: %s\n", agenda_cli[indice_contato].nome);
        printf("Celular: %s\n", agenda_cli[indice_contato].cel);
        printf("Cidade: %s\n", agenda_cli[indice_contato].cidade);
    } else {
    	printf("CPF do cliente não foi localizado na agenda");
    	return -1;
	}
	// Para imprimir, usei o vettor agenda_cli e o índice foi o cpf buscado;
}			    		

/*QUESTÃO 4 (1.75): Implemente a função excluir_contato_cliente() que receberá por parâmetro um ponteiro para um vetor
com registros de clientes e um ponteiro para o contador de contatos cadastrados. A função deverá solicitar o cpf do contato
a ser excluído. Em seguida deverá transferir esse cpf, juntamente com o vetor agenda_cli, por parâmetro para a função 
buscar_contato_cliente(), que verificará se esse cpf está cadastrado. Se o retorno da função buscar_contato_cliente() 
for maior ou igual a zero (ou seja, um índice válido), a função imprimir_contato_cliente() deverá excluir o 
contato do vetor agenda_cli. Caso o retorno seja -1, a função excluir_contato_cliente
deverá apresentar uma mensagem informando que o cpf não foi localizado na agenda de contatos.*/
void excluir_contato_cliente(Cliente agenda_cli[], int *cont)
{	
	//printf("\nImprimindo um contato da agenda:\n"); // É para excluir não?
	printf("\nExcluindo um contato da agenda:\n");
	
	int i;
	char cpf_contato[15];
	printf("Digite o número do CPF do contato que deseja excluir: ");
	scanf("%s", cpf_contato);
	
	// Vou usar a função Bucar_contato_cliente novaaemnte e for para deletar o contato
	int indice_contato = buscar_contato_cliente(Cliente agenda_cli[], char cpf[], int cont);
	if (indice_contato >= 0) {                             // Se encontrou o CPF, excluí 
		for (i = indice_contato; i < cont - 1; i++) {
			agenda_cli[i] = agenda_cli[i+1];
		}
		(*cont)--;
		printf("O contato \"%s\" foi excluído!.\n", cpf_contato);
		return 1;
	} else {
		printf("Não foi possível excluir.\nO contato \"%d\" não foi encontrado na agenda!", cpf_contato);
		return -1;
	}
}

/*QUESTÃO 5 (1.75): Desenvolva o código da função imprimir_vetor() que receberá por parâmetro um 
ponteiro para um vetor com 100 elementos inteiros e percorrerá esse vetor imprimindo os seus 
elementos. Para percorrer o vetor, a função deverá usar 4 ponteiros (p,q,r,s) de forma SIMULTÂNEA 
posicionados conforme seguem:
p: deve iniciar na posição 0
q: deve iniciar na posição 25
r: deve iniciar na posição 50
s: deve iniciar na posição 75
*/
void imprimir_vetor(int *vet)
{	
	printf("\nImprimindo o vetor de inteiros usando quatros ponteiros\n");
	
	// Fiz como se fosse para imprimir normal, mas coloque os ponteiros em suas posições e incrementa em 1
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

/*QUESTÃO 6 (1.25): Desenvolva o código da função preencher_vetor() que receberá um ponteiro para 
um vetor de inteiros (vazio) por parâmetro e o preencherá automaticamente com 100 valores inteiros.*/
void preencher_vetor(int *vet)
{	
	printf("\nPreenchendo automaticamente o vetor de inteiros\n");
	
	// Esse é a mais facíl, parece que tem alguma pegadinha hahahahah
	int i;
    for (i = 0; i < 100; i++) {
        vet[i] = i + 2; // Para sempre ser número par;
    }
	
}

//Função menu(): função que apresenta o menu de opções para o usuário
void menu(){
	printf("**************Menu de Opções:****************\n\n");
	printf("\t1. Acessar submenu Agenda de Clientes\n");
	printf("\t2. Imprimir vetor de inteiros usando ponteiros\n");
	printf("\t3. Sair\n");
	printf("\nEscolha uma opção (1 ou 2) ou digite 3 para encerrar o programa\n");
}
//Chamada das funções: (0.75)
void submenu_agenda_clientes(Cliente contatos[], int *cont){
	int op, flag;
	
	do
	{		
		printf("**************Submenu Agenda de Clientes:****************\n\n");
		printf("\t1. Inserir o contato de um novo cliente na Agenda\n");
		printf("\t2. Imprimir dados de um contato\n");
		printf("\t3. Remover o contato de um cliente da Agenda\n");
		printf("\t4. Voltar ao menu principal\n");
		printf("\nEscolha uma opção entre 1 e 3 ou digite 4 para voltar ao menu principal\n");
		scanf("%d",&op);
	
		switch (op){
			case 1:	
				inserir_contato_cliente(Cliente agenda_cli[], int *i)	
				break;	
			// Novamente parece muito facíl, tem pegadinha né? KKKK				
			case 2:
				buscar_contato_cliente(agenda_cli, cpf, cont)
				break;
			// Na duvida, vou colocar uma de cada pq aí uma ctz q acerto
			case 3:
				excluir_contato_cliente(Cliente agenda_cli[],  *cont)
				break;
			case 4:
				printf("Voltando para o menu principal\n");
				break;
			default: printf("Opção incorreta!\n");		
		}	
	} while(op >= 1 && op <3);
}

//Chamada das funções: (0.5)
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
			   //CHAMANDO O SUBMENU COM OPÇÕES PARA GERENCIAR AGENDA DE CLIENTES
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
			default: printf("Opção incorreta!\n");
		}	
	} while (op >= 1 && op <3);	
}

// Se for possível, gostaria de tirar algumas dúvidas que fiquei durante a prova. Vou refazer a prova em casa :) 
// Estou travado e não consigo ir além. 
