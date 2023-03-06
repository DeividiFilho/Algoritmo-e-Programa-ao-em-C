//5- Fazer um programa que leia um conjunto de valores
//correspondentes �s notas que alunos obtiveram em
//uma prova. Quando o valor fornecido for um n�mero
//negativo, significa que n�o existem mais pontos para
//serem lidos. Ap�s isso seu programa dever�:
//	
//a. Escrever quantas notas s�o maiores ou iguais a
//6.0
//b. Escrever quantas notas s�o maiores ou iguais a
//4.0 e menores que 6.0
//c. Escrever quantos notas s�o menores que 4.0

#include <stdio.h>

int main() {
    int nota, num_notas_maiores_igual_6 = 0, num_notas_entre_4_e_6 = 0, num_notas_menores_4 = 0;

    // Loop para ler as notas
    while (1) {  // Loop infinito
        printf("Digite a nota (ou um n�mero negativo para sair): ");
        scanf("%d", &nota);

        // Verifica se o usu�rio digitou um n�mero negativo para sair do loop
        if (nota < 0) {
            break;  // Sai do loop
        }

        // Classifica a nota e incrementa o contador correspondente
        if (nota >= 6) {
            num_notas_maiores_igual_6++;
        } else if (nota >= 4) {
            num_notas_entre_4_e_6++;
        } else {
            num_notas_menores_4++;
        }
    }

    // Exibe os resultados
    printf("\nNotas maiores ou iguais a 6.0: %d\n", num_notas_maiores_igual_6);
    printf("Notas entre 4.0 e 6.0: %d\n", num_notas_entre_4_e_6);
    printf("Notas menores que 4.0: %d\n", num_notas_menores_4);

    return 0;
}


