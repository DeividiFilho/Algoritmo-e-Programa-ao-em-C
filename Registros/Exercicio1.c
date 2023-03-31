#include <stdio.h>
#include <string.h>

struct Funcionario {
    int codigo;
    char cargo[50];
    char nome[50];
    int num_dependentes;
    float salario;
};

int main() {
    struct Funcionario funcionario;        // é criado um novo funcionário com os dados inseridos pelo usuário utilizando a 
										  //função scanf(). Em seguida, são exibidos os dados do funcionário criado.
    printf("Digite o codigo do funcionario: ");
    scanf("%d", &funcionario.codigo);

    printf("Digite o cargo do funcionario: ");
    scanf("%s", funcionario.cargo);

    printf("Digite o nome do funcionario: ");
    scanf("%s", funcionario.nome);

    printf("Digite o numero de dependentes do funcionario: ");
    scanf("%d", &funcionario.num_dependentes);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario.salario);

    printf("\nFuncionario criado:\n");
    printf("Codigo: %d\n", funcionario.codigo);
    printf("Cargo: %s\n", funcionario.cargo);
    printf("Nome: %s\n", funcionario.nome);
    printf("Numero de dependentes: %d\n", funcionario.num_dependentes);
    printf("Salario: R$%.2f\n\n", funcionario.salario);

    printf("Digite o novo cargo do funcionario: ");
    scanf("%s", funcionario.cargo);

    printf("Digite o novo salario do funcionario: ");
    scanf("%f", &funcionario.salario);

    printf("\nFuncionario atualizado:\n");
    printf("Codigo: %d\n", funcionario.codigo);
    printf("Cargo: %s\n", funcionario.cargo);
    printf("Nome: %s\n", funcionario.nome);
    printf("Numero de dependentes: %d\n", funcionario.num_dependentes);
    printf("Salario: R$%.2f\n", funcionario.salario);

    return 0;
}

