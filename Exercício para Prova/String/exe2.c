/*Defina um registro de Funcion?rio capaz de armazenar o c?digo, 
o cargo, o nome, o n?mero de dependentes e o sal?rio de um funcion?rio.*/

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#define max 100 // define o tamanho m?ximo do vetor de funcion?rios

struct Funcionario
{
	int cod, num_dep;
	char nome[40], cargo[40];
	float salario;	
};

//declarando as fun??es
int cadastrar_funcionario(struct Funcionario vet_func[], int *posicao);
void consultar_funcionario(struct Funcionario vet_func[], int posicao, int cod_func);
int busca_funcionario(struct Funcionario vet_fun[], int posicao, int cod_func);
int remover_funcionario(struct Funcionario vet_fun[], int *posicao, int cod_func);

main()
{
	struct Funcionario funcionarios[max]; // vetor de funcion?rios
	int posicao = 0, opcao, codigo; // guarda a posi??o de inser??o de um novo funcion?rio no vetor de funcionarios.
	
	setlocale(LC_ALL,"Portuguese");
	
	do 
	{
		printf("Menu de op??es:\n\t1. Inserir Funcion?rio\n\t2.Consultar Funcionario\n\t3. Remover Funcionario\n\t4. Sair");
		scanf("%d",&opcao);
		
		switch(opcao)
		{
			case 1: //chama a fun??o inserir funcionario
				printf("\nInserindo um novo funcion?rio.");
				if(cadastrar_funcionario(funcionarios,&posicao) == 1)
				{
					printf("Funcionario cadastrado com sucesso!");
					system("pause");
				}
				else{
					printf("\nO cadastrado n?o pode ser realizado!");
					system("pause");
				}
				break;
			case 2: //chama a fun??o consultar funcionario
				printf("\nConsultando dados de um funcion?rio.");
				printf("\nDigite o c?digo do funcion?rio que deseja consultar: ");
				scanf("%d",&codigo);
				consultar_funcionario(funcionarios,posicao,codigo);
				break;
			case 3: //chama a fun??o remover funcionario
				printf("\nRemovendo um funcion?rio.");
				printf("\nDigite o c?digo do funcion?rio que deseja remover: ");
				scanf("%d",&codigo);
				if(remover_funcionario(funcionarios,&posicao,codigo) == 1)
				{
					printf("\nFuncionario removido com sucesso!");
					system("pause");
				}
				else{
					printf("Funcionario n?o localizado!");
					system("pause");
				}
				break;
			default:
				printf("Finalizando o programa.");
		}
		system("cls"); //limpa a tela
	} while(opcao != 4);
	
}

int cadastrar_funcionario(struct Funcionario vet_func[], int *posicao)
{
	if (*posicao<max) // testa se ainda h? espa?o no vetor antes de inserir o funcionario
	{
		fflush(stdin);
		printf("Digite o nome do fucion?rio: ");
		gets(vet_func[*posicao].nome);
		printf("\nDigite o cargo do fucion?rio: ");
		gets(vet_func[*posicao].cargo);
		printf("\nDigite o c?digo do fucion?rio: ");
		scanf("%d",&vet_func[*posicao].cod);
		printf("\nDigite o n?mero de dependentes do funcion?rio: ");
		scanf("%d",&vet_func[*posicao].num_dep);
		printf("\nDigite o sal?rio do fucion?rio: ");
		scanf("%f",&vet_func[*posicao].salario);	
		(*posicao)++;/* incrementa a variavel definida na fun??o main que guarda a posicao de inser??o
					 de um novo funcionario.	*/
		return 1; //retorna 1 para indicar que o cadastro deu certo
	}
	return 0; //retorna 0 para indicar que o cadastro n?o deu certo
}

void consultar_funcionario(struct Funcionario vet_func[], int posicao, int cod_func)
{
	int i, achou = 0;
	
	for(i=0; i<posicao; i++)
	{
		if(vet_func[i].cod == cod_func)
		{
			achou = 1;
			printf("\nNome: %s\nCargo: %s\n", vet_func[i].nome,vet_func[i].cargo);
			printf("\nSal?rio: %.3f\nDependentes: %d",vet_func[i].salario,vet_func[i].num_dep);
		}
	}
	if (!achou)
		printf("\nN?o foi encontrado nenhum funcion?rio com o c?digo informado.");
}

int busca_funcionario(struct Funcionario vet_fun[], int posicao, int cod_func)
{
	int i;
	
	for(i=0; i<posicao; i++)
	{
		if (vet_fun[i].cod == cod_func)
			return i; //retorna a posi??o no vetor onde se encontra o c?digo do funcionario
	}
	return -1; //retorna -1 para indicar que n?o encontrou o funcion?rio com aquele c?digo
}

int remover_funcionario(struct Funcionario vet_func[], int *posicao, int cod_func)
{
	int i, j, pos;
	
	//chama a fun??o buscar_funcionario() para ver se o funcionario existe
	pos = busca_funcionario(vet_func,*posicao,cod_func);	
	if (pos >= 0) //se >= zero indica que encontrou o c?digo
	{
		for(i=pos; i<*posicao-1; i++)
		{
			vet_func[i] = vet_func[i+1];
		}
		(*posicao)--;
		return 1; // indica que removeu
	}
	return 0; // indica que n?o foi poss?vel remover
}
