#include <stdio.h>

#define MAX_HABITANTES 20

typedef struct {
    float salario;
    char sexo;
    int idade;
    int num_filhos;
} Habitante;

int main() {
    Habitante habitantes[MAX_HABITANTES];
    int i, num_habitantes;
    float soma_salarios = 0, media_salarios, num_total_filhos = 0, media_filhos;
    float maior_salario = 0, menor_salario = 9999999, percentual_mulheres = 0;

    printf("Informe o n�mero de habitantes (at� 20): ");
    scanf("%d", &num_habitantes);

    // Ler os dados de cada habitante
    for (i = 0; i < num_habitantes; i++) {
        printf("Informe os dados do habitante %d:\n", i+1);
        printf("Sal�rio: ");
        scanf("%f", &habitantes[i].salario);
        printf("Sexo (M ou F): ");
        scanf(" %c", &habitantes[i].sexo);
        printf("Idade: ");
        scanf("%d", &habitantes[i].idade);
        printf("N�mero de filhos: ");
        scanf("%d", &habitantes[i].num_filhos);

        // Atualizar informa��es gerais
        soma_salarios += habitantes[i].salario;
        num_total_filhos += habitantes[i].num_filhos;
        if (habitantes[i].salario > maior_salario) {
            maior_salario = habitantes[i].salario;
        }
        if (habitantes[i].salario < menor_salario) {
            menor_salario = habitantes[i].salario;
        }
        if (habitantes[i].sexo == 'F' && habitantes[i].salario > 1500) {
            percentual_mulheres++;
        }
    }

    // Calcular as informa��es pedidas
    media_salarios = soma_salarios / num_habitantes;
    media_filhos = num_total_filhos / num_habitantes;
    percentual_mulheres = (percentual_mulheres / num_habitantes) * 100;

    // Imprimir os resultados
    printf("\nM�dia de sal�rios: R$%.2f\n", media_salarios);
    printf("N�mero m�dio de filhos: %.1f\n", media_filhos);
    printf("Maior sal�rio: R$%.2f\n", maior_salario);
    printf("Menor sal�rio: R$%.2f\n", menor_salario);
    printf("Percentual de mulheres com sal�rio superior a R$1.500,00: %.1f%%\n", percentual_mulheres);

    return 0;
}

