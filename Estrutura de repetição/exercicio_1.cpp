//1- Em um campeonato de futebol existem 5 times com 11
//jogadores cada. Faça um programa que receba a
//idade, o peso e a altura de cada um dos jogadores,
//calcule e mostre:
// A quantidade de jogadores com menos de 18 anos;
// A média de idade dos jogadores de cada time;
// A altura média de todos os jogadores do
//campeonato;
// A porcentagem de jogadores de todos os times com
//mais de 80 quilos.

#include <stdio.h>

#define NUM_TIMES 1
#define NUM_JOGADORES 4

int main() {
    int idade, i, j, num_menores_idade = 0, num_jogadores = 0, num_jogadores_pesados = 0;
    float peso, altura, soma_idades = 0.0, soma_alturas = 0.0;
    float media_idade, media_altura, perc_jogadores_pesados;

    // Loop pelos times
    for (i = 1; i <= NUM_TIMES; i++) {
        float soma_idades_time = 0.0;
        // Loop pelos jogadores de cada time
        for (j = 1; j <= NUM_JOGADORES; j++) {
            printf("Digite a idade, peso e altura do jogador %d do time %d: ", j, i);
            scanf("%d %f %f", &idade, &peso, &altura);

            if (idade < 18) {
                num_menores_idade++;
            }
            if (peso > 80.0) {
                num_jogadores_pesados++;
            }

            soma_idades += idade;
            soma_idades_time += idade;
            soma_alturas += altura;
            num_jogadores++;
        }
        media_idade = soma_idades_time / NUM_JOGADORES;
        printf("Média de idade do time %d: %.2f\n", i, media_idade);
    }

    media_altura = soma_alturas / (NUM_TIMES * NUM_JOGADORES);
    printf("Altura média dos jogadores: %.2f\n", media_altura);

    perc_jogadores_pesados = 100.0 * num_jogadores_pesados / num_jogadores;
    printf("Porcentagem de jogadores com mais de 80 kg: %.2f%%\n", perc_jogadores_pesados);

    printf("Quantidade de jogadores com menos de 18 anos: %d\n", num_menores_idade);

    return 0;
}

