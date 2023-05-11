#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOOS 100

typedef struct {
    int numero;
    char cidade_origem[50];
    char cidade_destino[50];
    float distancia;
    float tempo_medio;
    char aeronave[50];
    int escalas;
} Voo;


int buscar_voo(Voo voos[], int num_voos, int num) {
	int i;
    for (i = 0; i < num_voos; i++) {
        if (voos[i].numero == num) {
            return i; // retorna o índice do voo no vetor
        }
    }
    return -1; // se não encontrar o voo, retorna -1
}

void incluir_voo(Voo voos[], int *num_voos) {
    if (*num_voos >= MAX_VOOS) {
        printf("Erro: limite de voos atingido.\n");
        return;
    }

    Voo novo_voo;
    printf("Digite o numero do voo: ");
    scanf("%d", &novo_voo.numero);

    int indice = buscar_voo(voos, *num_voos, novo_voo.numero);
    if (indice != -1) {
        printf("Erro: número de voo ja cadastrado.\n");
        return;
    }

    printf("Digite a cidade de origem: ");
    scanf(" %[^\n]s", novo_voo.cidade_origem);

    printf("Digite a cidade de destino: ");
    scanf(" %[^\n]s", novo_voo.cidade_destino);

    printf("Digite a distância em km: ");
    scanf("%f", &novo_voo.distancia);

    printf("Digite o tempo médio em horas: ");
    scanf("%f", &novo_voo.tempo_medio);

    printf("Digite o nome da aeronave: ");
    scanf(" %[^\n]s", novo_voo.aeronave);

    printf("Digite o número de escalas: ");
    scanf("%d", &novo_voo.escalas);

    voos[*num_voos] = novo_voo;
    (*num_voos)++;

    printf("Voo cadastrado com sucesso!\n");
}

void listar_voo(Voo voos[], int num_voos) {
    int numero_voo;
    printf("Digite o número do voo que deseja listar: ");
    scanf("%d", &numero_voo);

    int indice = buscar_voo(voos, num_voos, numero_voo);
    if (indice == -1) {
        printf("Voo com número %d nao encontrado.\n", numero_voo);
        return;
    }

    printf("Número: %d\n", voos[indice].numero);
    printf("Cidade origem: %s\n", voos[indice].cidade_origem);
    printf("Cidade destino: %s\n", voos[indice].cidade_destino);
    printf("Distância: %.2f\n", voos[indice].distancia);
    printf("Tempo medio: %.2f\n", voos[indice].tempo_medio);
    printf("Aeronave: %s\n", voos[indice].aeronave);
    printf("Escalas: %s\n", voos[indice].escalas);
}

void listar_especifica_voo(Voo voos[], int num_voos) {
    int numero;
    printf("Digite o número do voo: ");
    scanf("%d", &numero);

    int indice = buscar_voo(voos, num_voos, numero);
    if (indice == -1) {
        printf("Voo com número %d nao encontrado.\n", numero);
        return;
    }

    printf("Voo encontrado. Qual informacao voce deseja listar?\n");
    printf("1. Número\n");
    printf("2. Cidade origem\n");
    printf("3. Cidade destino\n");
    printf("4. Distância\n");
    printf("5. Tempo médio\n");
    printf("6. Aeronave\n");
    printf("7. Escalas\n");
    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("N[u]mero do voo: %d\n", voos[indice].numero);
            break;
        case 2:
            printf("Cidade origem: %s\n", voos[indice].cidade_origem);
            break;
        case 3:
            printf("Cidade destino: %s\n", voos[indice].cidade_destino);
            break;
        case 4:
            printf("Distância: %.2f km\n", voos[indice].distancia);
            break;
        case 5:
            printf("Tempo médio: %.2f horas\n", voos[indice].tempo_medio);
            break;
        case 6:
            printf("Aeronave: %s\n", voos[indice].aeronave);
            break;
        case 7:
            printf("Escalas: %s\n", voos[indice].escalas);
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
}

void alterar_voo(Voo voos[], int num_voos) {
    int numero;
    printf("Digite o número do voo que deseja alterar: ");
    scanf("%d", &numero);

    int indice = buscar_voo(voos, num_voos, numero);
    if (indice == -1) {
        printf("Voo com número %d nao encontrado.\n", numero);
        return;
    }

    printf("Voo encontrado. O que voce deseja alterar?\n");
    printf("1. Cidade de origem\n");
    printf("2. Cidade de destino\n");
    printf("3. Distância\n");
    printf("4. Tempo médio\n");
    printf("5. Aeronave\n");
    printf("6. Escalas\n");
    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite a nova cidade de origem: ");
            scanf(" %[^\n]s", voos[indice].cidade_origem);
            break;
        case 2:
            printf("Digite a nova cidade de destino: ");
            scanf(" %[^\n]s", voos[indice].cidade_destino);
            break;
        case 3:
            printf("Digite a nova distância: ");
            scanf("%f", &voos[indice].distancia);
            break;
        case 4:
            printf("Digite o novo tempo médio: ");
            scanf("%f", &voos[indice].tempo_medio);
            break;
        case 5:
            printf("Digite a nova aeronave: ");
            scanf(" %[^\n]s", voos[indice].aeronave);
            break;
        case 6:
            printf("Digite as novas escalas: ");
            scanf(" %[^\n]s", voos[indice].escalas);
            break;
        default:
            printf("Opcão inválida.\n");
            break;
    }
}

void excluir_voo(Voo voos[], int& num_voos, int num) {
    int indice = buscar_voo(voos, num_voos, num);
    int i;
    if (indice == -1) {
        printf("Voo com número %d nao encontrado.\n", num);
        return;
    }

    printf("Deseja realmente excluir o voo %d? (S/N)\n", num);
    char resposta;
    scanf(" %c", &resposta);
    if (resposta == 'S' || resposta == 's') {
        for (i = indice; i < num_voos - 1; i++) {
            voos[i] = voos[i + 1];
        }
        num_voos--;
        printf("Voo excluído com sucesso.\n");
    } else {
        printf("Operação cancelada pelo usuário.\n");
    }
}

