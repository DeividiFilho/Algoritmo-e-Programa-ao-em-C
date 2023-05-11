typedef struct {
	int numero_voo;
	char piloto[MAX_PILOTO][50];
	char data_saida[11];
    char hora_saida[6];
    char data_chegada[11];
    char hora_chegada[6];
    char ocorrencias[200];
} Viagem;


void incluir_viagem() {
	
	Viagem voos[MAX_VOO];
	int num_voos = 0;
	int i;
	
    if (num_voos >= MAX_VOO) {
        printf("Não é possível adicionar mais viagens.\n");
        return;
    }
    
    Viagem nova_viagem;
    
    printf("Número do Voo: ");
    scanf("%d", &nova_viagem.numero_voo);
    
    for (i = 0; i < num_voos; i++) {
        if (voos[i].numero_voo == nova_viagem.numero_voo) {
            printf("Já existe uma viagem com este número.\n");
            return;
        }
    }
    
    printf("Piloto 1: ");
    scanf("%s", nova_viagem.piloto[0]);
    
    printf("Piloto 2 (ou deixe em branco): ");
    scanf("%s", nova_viagem.piloto[1]);
    
    printf("Data da Saída (DD/MM/AAAA): ");
    scanf("%s", nova_viagem.data_saida);
    
    printf("Hora Saída (HH:MM): ");
    scanf("%s", nova_viagem.hora_saida);
    
    printf("Data da Chegada (DD/MM/AAAA): ");
    scanf("%s", nova_viagem.data_chegada);
    
    printf("Hora Chegada (HH:MM): ");
    scanf("%s", nova_viagem.hora_chegada);
    
    printf("Ocorrências: ");
    scanf(" %[^\n]s", nova_viagem.ocorrencias);
    
    voos[num_voos] = nova_viagem;
    num_voos++;
    
    printf("Viagem adicionada com sucesso.\n");
}

void listar_viagens() {
	Viagem voos[MAX_VOO];
	int num_voos = 0;
	int i;
	
    if (num_voos == 0) {
        printf("Não há viagens cadastradas.\n");
        return;
    }
    
    printf("Viagens cadastradas:\n");
    printf("Número do Voo | Pilotos | Data da Saída | Hora Saída | Data da Chegada | Hora Chegada | Ocorrências\n");
    
    for (i = 0; i < num_voos; i++) {
        printf("%-14d| %-7s", voos[i].numero_voo, voos[i].piloto[0]);
        if (voos[i].piloto[1][0] != '\0') {
            printf(" %-7s", voos[i].piloto[1]);
        } else {
            printf(" %-7s", "-");
        }
        printf("| %-13s| %-11s| %-15s| %-12s| %-s\n", voos[i].data_saida, voos[i].hora_saida, voos[i].data_chegada, voos[i].hora_chegada, voos[i].ocorrencias);
    	
	}
}

void listarE_viagem(int numero_voo) {
	Viagem voos[MAX_VOO];
	int num_voos = 0;
	int i;
	
    for (i = 0; i < num_voos; i++) {
        if (voos[i].numero_voo == numero_voo) {
            printf("Número do Voo: %d\n", voos[i].numero_voo);
            printf("Pilotos: %s", voos[i].piloto[0]);
            if (voos[i].piloto[1][0] != '\0') {
                printf(", %s\n", voos[i].piloto[1]);
            } else {
                printf("\n");
            }
            printf("Data da Saída: %s\n", voos[i].data_saida);
            printf("Hora da Saída: %s\n", voos[i].hora_saida);
            printf("Data da Chegada: %s\n", voos[i].data_chegada);
            printf("Hora da Chegada: %s\n", voos[i].hora_chegada);
            printf("Ocorrências: %s\n", voos[i].ocorrencias);
            return;
        }
    }
    printf("Viagem com número %d não encontrada.\n", numero_voo);
}
















// ATUAL UBMENU VIAGEM




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOO 100
#define MAX_PILOTO 2

typedef struct {
	int numero_voo;
	char piloto[MAX_PILOTO][50];
	char data_saida[11];
    char hora_saida[6];
    char data_chegada[11];
    char hora_chegada[6];
    char ocorrencias[200];
} Viagem;

int buscar_viagem(Viagem viagens[], int num_viagens, int num_voo) {
	int i;
    for (i = 0; i < num_viagens; i++) {
        if (viagens[i].numero_voo == num_voo) {
            return i; // retorna o índice da viagem no vetor
        }
    }
    return -1; // se não encontrar a viagem, retorna -1
}

void incluir_viagem() {
	
	Viagem voos[MAX_VOO];
	int num_voos = 0;
	int i;
	
    if (num_voos >= MAX_VOO) {
        printf("Não é possível adicionar mais viagens.\n");
        return;
    }
    
    Viagem nova_viagem;
    
    printf("Número do Voo: ");
    scanf("%d", &nova_viagem.numero_voo);
    
    for (i = 0; i < num_voos; i++) {
        if (voos[i].numero_voo == nova_viagem.numero_voo) {
            printf("Já existe uma viagem com este número.\n");
            return;
        }
    }
    
    printf("Piloto 1: ");
    scanf("%s", nova_viagem.piloto[0]);
    
    printf("Piloto 2 (ou deixe em branco): ");
    scanf("%s", nova_viagem.piloto[1]);
    
    printf("Data da Saída (DD/MM/AAAA): ");
    scanf("%s", nova_viagem.data_saida);
    
    printf("Hora Saída (HH:MM): ");
    scanf("%s", nova_viagem.hora_saida);
    
    printf("Data da Chegada (DD/MM/AAAA): ");
    scanf("%s", nova_viagem.data_chegada);
    
    printf("Hora Chegada (HH:MM): ");
    scanf("%s", nova_viagem.hora_chegada);
    
    printf("Ocorrências: ");
    scanf(" %[^\n]s", nova_viagem.ocorrencias);
    
    voos[num_voos] = nova_viagem;
    num_voos++;
    
    printf("Viagem adicionada com sucesso.\n");
}

void listar_viagem(Viagem viagens[], int num_viagens, int num_voo) {
    int indice;
    printf("Digite o número do voo: ");
    scanf("%d", &num_voo);

    indice = buscar_viagem(viagens, num_viagens, num_voo);
    if (indice == -1) {
        printf("Viagem com número de voo %d nao encontrada.\n", num_voo);
        return;
    }

    printf("Número do voo: %d\n", viagens[indice].numero_voo);
    printf("Piloto: %s\n", viagens[indice].piloto);
    printf("Data da saída: %s\n", viagens[indice].data_saida);
    printf("Hora da saída: %s\n", viagens[indice].hora_saida);
    printf("Data da chegada: %s\n", viagens[indice].data_chegada);
    printf("Hora da chegada: %s\n", viagens[indice].hora_chegada);
    printf("Ocorrências: %s\n", viagens[indice].ocorrencias);
}


void listar_especifica_viagem(Viagem viagens[], int num_viagens, int num_voo) {
    int indice;
    printf("Digite o número do voo: ");
    scanf("%d", &num_voo);

    indice = buscar_viagem(viagens, num_viagens, num_voo);
    if (indice == -1) {
        printf("Viagem com número de voo %d nao encontrada.\n", num_voo);
        return;
    }

    printf("Viagem encontrada. Qual item voce deseja listar?\n");
    printf("1. Número do voo\n");
    printf("2. Piloto\n");
    printf("3. Data da saída\n");
    printf("4. Hora da saóda\n");
    printf("5. Data da chegada\n");
    printf("6. Hora da chegada\n");
    printf("7. Ocorrências\n");
    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Número do voo: %d\n", viagens[indice].numero_voo);
            break;
        case 2:
            printf("Piloto: %s\n", viagens[indice].piloto);
            break;
        case 3:
            printf("Data da saída: %s\n", viagens[indice].data_saida);
            break;
        case 4:
            printf("Hora da saída: %s\n", viagens[indice].hora_saida);
            break;
        case 5:
            printf("Data da chegada: %s\n", viagens[indice].data_chegada);
            break;
        case 6:
            printf("Hora da chegada: %s\n", viagens[indice].hora_chegada);
            break;
        case 7:
            printf("Ocorrências: %s\n", viagens[indice].ocorrencias);
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
}


void alterar_viagem(Viagem viagens[], int num_viagens, int num_voo) {
    int indice = buscar_viagem(viagens, num_viagens, num_voo);
    if (indice == -1) {
        printf("Viagem com numero de voo %d nao encontrada.\n", num_voo);
        return;
    }

    printf("Viagem encontrada. O que voce deseja alterar?\n");
    printf("1. Piloto\n");
    printf("2. Data da saída\n");
    printf("3. Hora da saída\n");
    printf("4. Data da chegada\n");
    printf("5. Hora da chegada\n");
    printf("6. Ocorrências\n");
    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite o novo nome do piloto: ");
            scanf(" %[^\n]s", viagens[indice].piloto);
            break;
        case 2:
            printf("Digite a nova data da saída: ");
            scanf("%s", viagens[indice].data_saida);
            break;
        case 3:
            printf("Digite a nova hora da saída: ");
            scanf("%s", viagens[indice].hora_saida);
            break;
        case 4:
            printf("Digite a nova data da chegada: ");
            scanf("%s", viagens[indice].data_chegada);
            break;
        case 5:
            printf("Digite a nova hora da chegada: ");
            scanf("%s", viagens[indice].hora_chegada);
            break;
        case 6:
            printf("Digite as novas ocorrências: ");
            scanf(" %[^\n]s", viagens[indice].ocorrencias);
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
}

void excluir_viagem(Viagem viagens[], int *num_viagens, int num_voo) {
	int i;
    int indice = buscar_viagem(viagens, *num_viagens, num_voo);
    if (indice == -1) {
        printf("Viagem com numero de voo %d nao encontrada.\n", num_voo);
        return;
    }

    printf("Viagem encontrada. Deseja realmente excluir esta viagem? (s/n)\n");
    char resposta;
    scanf(" %c", &resposta);
    if (resposta == 's' || resposta == 'S') {
        for (i = indice; i < (*num_viagens)-1; i++) {
            viagens[i] = viagens[i+1];
        }
        (*num_viagens)--;
        printf("Viagem excluida com sucesso.\n");
    } else {
        printf("Operacao cancelada pelo usuario.\n");
    }
}

/* Viagem* buscar_por_num_voo(Viagem* viagens, int num_voo, int n, int i) {
	Viagem voos[MAX_VOO];
	int num_voos = 0;
    for (i = 0; i < n; i++) {
        if (viagens[i].numero_voo == num_voos) {
            return &viagens[i];
        }
    }
    return NULL;
}  */ 




