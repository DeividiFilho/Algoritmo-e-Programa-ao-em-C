#include <stdio.h>
#include <stdlib.h>

void preencher_vetor_medias(float **vetor_medias, int *tamanho) {
    float media;
    int capacidade = 10;
    int contador = 0;

    *vetor_medias = malloc(capacidade * sizeof(float));

    while (1) {
        printf("Digite a média semestral do aluno (ou -1 para encerrar): ");
        scanf("%f", &media);

        if (media == -1) {
            break;
        }

        (*vetor_medias)[contador] = media;
        contador++;

        // Verifica se o vetor precisa ser realocado
        if (contador == capacidade) {
            capacidade *= 2;
            *vetor_medias = realloc(*vetor_medias, capacidade * sizeof(float));
        }
    }

    *tamanho = contador;
}

void gravar_notas_arquivo(float *vetor_medias, int tamanho) {
    FILE *arquivo = fopen("notas_AP2S2.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para gravar as notas.\n");
        return;
    }
    
	int i;
    for ( i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%.2f\n", vetor_medias[i]);
    }

    fclose(arquivo);
    printf("Notas gravadas no arquivo 'notas_AP2S2.txt'.\n");
}

int main() {
    float *vetor_medias;
    int tamanho;

    preencher_vetor_medias(&vetor_medias, &tamanho);
    gravar_notas_arquivo(vetor_medias, tamanho);

    free(vetor_medias);

    return 0;
}

