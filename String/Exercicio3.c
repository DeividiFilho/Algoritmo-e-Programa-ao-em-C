// 3) Faça um programa que leia 10 nomes, ordene-os deforma crescente e mostre-os na tela.

#include <stdio.h>
#include <string.h>

#define TAM 10

int main() {
    char nomes[TAM][50];
    char aux[50];
    int i, j;
    
    for ( i = 0; i < TAM; i++) {
        printf("Digite o nome %d: ", i+1);
        fgets(nomes[i], 50, stdin);
        nomes[i][strlen(nomes[i])-1] = '\0'; // remove o caractere de quebra de linha \n do final 
    }
    
    for ( i = 0; i < TAM-1; i++) {   // ordenação dos nomes em ordem crescente, poderia usar o bubble sort tbm
        for ( j = i+1; j < TAM; j++) {
            if (strcmp(nomes[i], nomes[j]) > 0) { // strcmp comparas as string
                strcpy(aux, nomes[i]); // usa a var "aux" para auxiliar na atribuição da string
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], aux);
            }
        }
    }
    
    printf("\nNomes ordenados:\n"); // // printa os nomes ordenados
    for ( i = 0; i < TAM; i++) {
        printf("%d. %s\n", i+1, nomes[i]);
    }
}

