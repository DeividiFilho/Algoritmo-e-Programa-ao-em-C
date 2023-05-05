/* PROVA PRÁTICA DE AP2S2 - II SEM DE 2022 - 17/10/2022
	Deividi Douglas de Carlo Filho -- SC3029948
	
	ATENÇÃO: VOCÊ NÃO DEVE MODIFICAR OS PROTÓTIPOS DAS FUNÇÕES. 
	Não será permitido o uso de variáveis globais dentro das funções. 
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

/*QUESTÃO 1 (2.0): Implemente a função inserir_contato() que recebe por parâmetro um ponteiro para um vetor
com capacidade para até 200 registros de pessoas e um ponteiro para a posição do vetor na qual o registro 
será inserido pela função. A função deverá retornar 1, caso o contato tenha sido incluído com sucesso e -1, 
caso contrário. A mensagem informando se o contato foi incluído com sucesso
ou não será impressa na função submenu_agenda_contatos().*/

int inserir_contato(Pessoa* vetor_contatos, int* posicao_atual) {
    if (*posicao_atual >= 200) {
        printf("Erro: a capacidade máxima de registros já foi atingida.\n");
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


/*QUESTÃO 2 (1.0): Implemente a função buscar_contato() que receba por parâmetro um ponteiro para um vetor
com registros de pessoas, o nome do contato e o contador indicando a quantidade de contatos armazenados
no vetor. A função deverá retornar a posição (índice) do primeiro registro encontrado com aquele nome, 
caso ele exista e -1, caso ele não seja encontrado. A mensagem informando que o nome não foi encontrado 
(quando acontecer) deve ser impressa imprimir_contatos().*/

int buscar_contato(Pessoa* vetor_contatos, char* nome_contato, int num_contatos) {
	int i;
    for (i = 0; i < num_contatos; i++) {
        if (strcmp(vetor_contatos[i].nome, nome_contato) == 0) {
            return i;
        }
    }
    printf("O contato \"%s\" não foi encontrado.\n", nome_contato);
    return -1;
}


/*QUESTÃO 3 (1.0): Implemente a função imprimir_contato() que receba por parâmetro um ponteiro para um vetor
com registros de pessoas e o contador de contatos cadastrados. A função deverá solicitar o nome do contato
como entrada e deverá transferir esse nome, juntamente com o vetor de contatos, por parâmetros para a função 
buscar_contato(), que verificará se esse nome está cadastrado. Se o retorno da função buscar_contato() 
for maior ou igual a zero (ou seja, um índice válido), a função imprimir_contato() deverá imprimir o telefone fixo,
o celular e a cidade daquele contato. Caso o retorno seja -1, deve apresentar uma mensagem 
informando que o nome não foi localizado na agenda de contatos.*/

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
	    		

/*QUESTÃO 4 (2.0): Implemente a função excluir_contato() que recebe por parâmetro um ponteiro para um vetor
de pessoas e um ponteiro para o contador de contatos cadastrados. A função deverá retornar 1, caso o contato 
tenha sido excluído com sucesso e -1, caso o contato não tenha sido encontrado. A mensagem informando se o 
contato foi excluído ou não deve ser impressa pela função submenu_agenda_contatos().
OBS: utilize a função buscar_contato() para verificar se o contato existe na agenda. */

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
        printf("O contato \"%s\" foi excluído com sucesso.\n", nome_contato);
        return 1;
    } else {
        printf("O contato \"%s\" não foi encontrado na agenda de contatos.\n", nome_contato);
        return -1;
    }
}


/*QUESTÃO 5 (2.0): Desenvolva o código da função imprimir_vetor() que receberá por parâmetro um 
ponteiro para um vetor com 100 elementos inteiros e percorrerá esse vetor imprimindo os seus 
elementos. Para percorrer o vetor, a função deverá usar 4 ponteiros (p,q,r,s) de forma SIMULTÂNEA 
posicionados conforme seguem:
p: deve iniciar na posição 0
q: deve iniciar na posição 25
r: deve iniciar na posição 50
s: deve iniciar na posição 75
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


/*QUESTÃO 6 (0.75): Desenvolva o código da função preencher_vetor() que receberá um ponteiro para 
um vetor vazio por parâmetro e o preencherá automaticamente com 100 valores inteiros.*/
void preencher_vetor(int* vetor) {
	int i;
    for (i = 0; i < 100; i++) {
        vetor[i] = i + 1;
    }
}


//Função menu(): função que apresenta o menu de opções para o usuário
void menu(){
	printf("**************Menu de Opções:****************\n\n");
	printf("\t1. Acessar submenu Agenda de Contatos\n");
	printf("\t2. Imprimir vetor usando 4 ponteiros\n ");
	printf("\t3. Sair\n");
	printf("\nEscolha uma opção entre 1 e 2 ou digite 3 para encerrar o programa\n");
}
//Chamada das funções: (0.75)
void submenu_agenda_contatos(Pessoa contatos[], int *cont){
	int op, flag;
	
	do
	{		
		printf("**************Submenu Agenda:****************\n\n");
		printf("\t1. Inserir contato na agenda\n ");
		printf("\t2. Imprimir dados de um contato\n");
		printf("\t3. Excluir um contato\n");
		printf("\t4. Voltar ao menu principal\n");
		printf("\nEscolha uma opção entre 1 e 3 ou digite 4 para voltar ao menu principal\n");
		scanf("%d",&op);
	
		switch (op){
		case 1:
		/*INSIRA AQUI A CHAMADA DA FUNÇÃO inserir_contato_agenda(), RESPEITANDO OS 
		PARÂMETROS CONFORME O PROTÓTIPO DA FUNÇÃO*/		
			inserir_contato_agenda(contatos, cont);	
			break;					
		case 2:
		/*INSIRA AQUI A CHAMADA DA FUNÇÃO imprimir_contato(), RESPEITANDO OS 
		PARÂMETROS CONFORME O PROTÓTIPO DA FUNÇÃO*/
			imprimir_contato(contatos, *cont);
			break;
		case 3:
		/*INSIRA AQUI A CHAMADA DA FUNÇÃO excluir_contato(), RESPEITANDO OS 
		PARÂMETROS CONFORME O PROTÓTIPO DA FUNÇÃO*/
			excluir_contato(contatos, cont);
			break;
		case 4:
			printf("Voltando para o menu principal\n");
			break;
		default: printf("Opção incorreta!\n");		
	}	
	} while(op >= 1 && op <4);
}

//Chamada das funções: (0.5)
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
		    /*INSIRA AQUI AS CHAMADAS DAS FUNÇÕES preencher_vetor() e imprimir_vetor(), RESPEITANDO OS 
		    PARÂMETROS E O VALOR DE RETORNO (QUANDO HOUVER), CONFORME O PROTÓTIPO DE CADA FUNÇÃO*/
		    preencher_vetor(vetor);
		    imprimir_vetor(vetor);
		    break;
		case 3: 
			system("cls");
			printf("\nEncerrando o programa...\n"); 
			break;
		default: 
			printf("Opção incorreta!\n");
	}	
	
	} while (op >= 1 && op <3);	
}

