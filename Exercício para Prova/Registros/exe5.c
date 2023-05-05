// Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
// conter a matr´icula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
// da terceira prova.
// (a) Permita ao usuario entrar com os dados de 5 alunos. ´
// (b) Encontre o aluno com maior nota da primeira prova.
// (c) Encontre o aluno com maior media geral. ´
// (d) Encontre o aluno com menor media geral ´
// (e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
// aprovac¸ao

#include <stdio.h>

struct Aluno {
	int matricula;
	char nome[50];
	float nota1, nota2, nota3, maior_media, media;
};

main() {
	struct Aluno aluno[5];
	int i, nota_maior, max_prova_idx = 0, indice_menor_media = 0, indice_maior_media;
	int indice_maior_nota1, media;
	
	for(i = 0; i < 5; i++) {
		printf("\nDigite a matricula do aluno %d: ", i+1);
		scanf("%d", &aluno[i].matricula);
		printf("Digite o nome do aluno %d: ", i+1);
		scanf("%s", aluno[i].nome);
		printf("Digite a nota1, nota2 e nota3: do aluno %d: ", i+1);
		scanf("%f %f %f", &aluno[i].nota1, &aluno[i].nota2, &aluno[i].nota3);
		
		// calculando a media;
		aluno[i].media = (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3) / 3.0;
	}
	for(i = 0; i < 5; i++) { // Busca pela maior nota 1;
		if(aluno[i].nota1 > aluno[nota_maior].nota1) {
			nota_maior = i;
		}
	}
	
	for(i = 0; i < 5; i++) { // Busca pela maior media 
		if(aluno[i].media > aluno[indice_maior_media].media)
			indice_maior_media = i;
	}
	for(i = 0; i < 5; i++) { // Busca pela menor media
		if(aluno[i].media > aluno[indice_menor_media].media)
			indice_menor_media = i;
	}
	
	printf("\nIMPRIMINDO DADOS DO ALUNOS, AGUARDE");
	for(i= 0; i < 5; i++) {
		printf("\n\nALUNO %d", i+1);
		printf("\nMatricula: %d", aluno[i].matricula);
		printf("\nNome: %s", aluno[i].nome);
		printf("\nNota 1: %d", aluno[i].nota1);
		printf("\nNota 2: %d", aluno[i].nota2);
		printf("\nNota 3: %d", aluno[i].nota3);
		
		if (media >= 6) {
        	printf("\nSituacao: Aprovado");
    	} else {
       		printf("\nSituacao: Reprovado");
    	}	
	}
	printf("\n\nIMPRIMINDO OUTRAS INFORMACOES");
	printf("\nAluno com maior nota na primeira prova");
	printf("\nNome: %s", aluno[nota_maior].nome);
	printf("\nMatricula: %d", aluno[nota_maior].matricula);
	printf("\nNota 1: %d", aluno[nota_maior].nota1);
	printf("\n");
	
	printf("\nAluno com MAIOR media geral\n");
	printf("\nNome: %s", aluno[indice_maior_media].nome);
	printf("\nMatricula: %d", aluno[indice_maior_media].matricula);
	printf("\nMedia: %.2f", aluno[indice_maior_media].media);
	
	printf("\nAluno com MENOR media geral\n");
	printf("\nNome: %s", aluno[indice_menor_media].nome);
	printf("\nMatricula: %d", aluno[indice_menor_media].matricula);
	printf("\nMedia: %.2f", aluno[indice_menor_media].media);
			
}
