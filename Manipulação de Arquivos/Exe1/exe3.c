#include <stdio.h>

void calcular_estatisticas(float *notas, int quantidade) {
    float media_geral = 0;
    int aprovados = 0;
    int reprovados = 0;
    int ifs = 0;

	int i;
    for ( i = 0; i < quantidade; i++) {
        media_geral += notas[i];

        if (notas[i] >= 6.0) {
            aprovados++;
        } else if (notas[i] < 4.0) {
            reprovados++;
        } else {
            ifs++;
        }
    }

    media_geral /= quantidade;

    float porcentagem_aprovados = (aprovados / (float)quantidade) * 100;
    float porcentagem_reprovados = (reprovados / (float)quantidade) * 100;
    float porcentagem_ifs = (ifs / (float)quantidade) * 100;

    printf("Média geral da turma: %.2f\n", media_geral);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", porcentagem_aprovados);
    printf("Porcentagem de alunos reprovados: %.2f%%\n", porcentagem_reprovados);
    printf("Porcentagem de alunos que farão IFS: %.2f%%\n", porcentagem_ifs);
}

int main() {
    FILE *arquivo = fopen("notas_AP2S2.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de notas.\n");
        return 1;
    }

    int capacidade = 10;
    int quantidade = 0;
    float *notas = (float *)malloc(capacidade * sizeof(float));

    float nota;
    while (fscanf(arquivo, "%f", &nota) == 1) {
        notas[quantidade] = nota;
        quantidade++;

        if (quantidade == capacidade) {
            capacidade *= 2;
            notas = (float *)realloc(notas, capacidade * sizeof(float));
        }
    }

    fclose(arquivo);

    calcular_estatisticas(notas, quantidade);

    free(notas);

    return 0;
}

