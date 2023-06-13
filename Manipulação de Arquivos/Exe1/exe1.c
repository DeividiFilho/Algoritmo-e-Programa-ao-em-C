#include <stdio.h>

#define NUM_CANDIDATOS 5

void calcularVotosPorCandidato(FILE *arquivo, int votos[]) {
    int codigo;
    while (fscanf(arquivo, "%d", &codigo) == 1) {
        if (codigo >= 100 && codigo <= 500) {
            votos[codigo / 100 - 1]++;
        }
    }
}

int calcularVotosCandidatoMaisVotado(int votos[]) {
    int maxVotos = votos[0];
    int candidatoMaisVotado = 100;
    int i;
    for ( i = 1; i < NUM_CANDIDATOS; i++) {
        if (votos[i] > maxVotos) {
            maxVotos = votos[i];
            candidatoMaisVotado = (i + 1) * 100;
        }
    }
    return candidatoMaisVotado;
}

int calcularVotosCandidatoMenosVotado(int votos[]) {
    int minVotos = votos[0];
    int candidatoMenosVotado = 100;
    int i;
    for ( i = 1; i < NUM_CANDIDATOS; i++) {
        if (votos[i] < minVotos) {
            minVotos = votos[i];
            candidatoMenosVotado = (i + 1) * 100;
        }
    }
    return candidatoMenosVotado;
}

int calcularVotosNulos(FILE *arquivo) {
    int codigo;
    int votosNulos = 0;

    while (fscanf(arquivo, "%d", &codigo) == 1) {
        if (codigo < 100 || codigo > 500) {
            votosNulos++;
        }
    }

    return votosNulos;
}
int main() {
    FILE *arquivo;
    int votos[NUM_CANDIDATOS] = {0};

    // Abrir o arquivo de votos
    arquivo = fopen("votos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de votos.\n");
        return 1;
    }

    // Calcular votos por candidato
    calcularVotosPorCandidato(arquivo, votos);

    // Fechar o arquivo de votos
    fclose(arquivo);

    // Calcular e apresentar a quantidade de votos por candidato
    printf("Quantidade de votos por candidato:\n");
    int i;
    for ( i = 0; i < NUM_CANDIDATOS; i++) {
        printf("Candidato %d: %d votos\n", (i + 1) * 100, votos[i]);
    }

    // Calcular e apresentar a quantidade de votos do candidato mais votado
    int candidatoMaisVotado = calcularVotosCandidatoMaisVotado(votos);
    printf("\nCandidato mais votado: %d\n", candidatoMaisVotado);
    
    
    // Calcular e apresentar a quantidade de votos do candidato menos votado
    int candidatoMenosVotado = calcularVotosCandidatoMenosVotado(votos);
    printf("Candidato menos votado: %d\n", candidatoMenosVotado);

    // Calcular a quantidade de votos nulos
    int votosNulos;
    votosNulos = calcularVotosNulos(arquivo);

	// Apresentar a quantidade de votos nulos
    printf("Quantidade de votos nulos: %d\n", votosNulos);
    return 0;
}

