#include <stdio.h>

typedef struct {
    char nome[50];
    int prontuario;
    float notas_provas[3];
    float notas_trabalhos[2];
} Aluno;

void preencher_dados_aluno(Aluno *aluno) {
    printf("Nome do aluno: ");
    fgets(aluno->nome, sizeof(aluno->nome), stdin);
    printf("Prontuário do aluno: ");
    scanf("%d", &(aluno->prontuario));
    printf("Notas das provas (P1, P2, P3): ");
    scanf("%f %f %f", &(aluno->notas_provas[0]), &(aluno->notas_provas[1]), &(aluno->notas_provas[2]));
    printf("Notas dos trabalhos (T1, T2): ");
    scanf("%f %f", &(aluno->notas_trabalhos[0]), &(aluno->notas_trabalhos[1]));
    
    // Limpar o buffer do teclado
    getchar();
}

void escrever_registro_binario(FILE *arquivo, Aluno *aluno) {
    fwrite(aluno, sizeof(Aluno), 1, arquivo);
}

int main() {
    FILE *arquivo = fopen("Notas_AP2S2.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de notas.\n");
        return 1;
    }
    
    int quantidade_alunos;
    printf("Quantidade de alunos: ");
    scanf("%d", &quantidade_alunos);
    
    int i;
    for ( i = 0; i < quantidade_alunos; i++) {
        Aluno aluno;
        printf("\n--- Aluno %d ---\n", i+1);
        preencher_dados_aluno(&aluno);
        escrever_registro_binario(arquivo, &aluno);
    }
    
    fclose(arquivo);
    
    printf("Arquivo criado com sucesso.\n");
    
    return 0;
}

