//  Construa uma estrutura aluno com nome, numero de matr ´ ´icula e curso. Leia do usuario 
// a informac¸ao de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na tela.

#include <stdio.h>

struct Aluno {
    char nome[50];
    int matricula;
    char curso[30];
};

main() {
 struct Aluno alunos[5];
    int i;
    
    for(i=0; i<5; i++) {
        printf("\nDigite o nome do aluno %d: ", i+1);
        scanf("%s", alunos[i].nome);
        printf("Digite a matricula do aluno %d: ", i+1);
        scanf("%d", &alunos[i].matricula);
        printf("Digite o curso do aluno %d: ", i+1);
        scanf("%s", alunos[i].curso);
    }
    
    printf("\nDados dos alunos:\n");
    for(i=0; i<5; i++) {
        printf("\nNome: %s", alunos[i].nome);
        printf("\nMatricula: %d", alunos[i].matricula);
        printf("\nCurso: %s\n", alunos[i].curso);
    }
}
