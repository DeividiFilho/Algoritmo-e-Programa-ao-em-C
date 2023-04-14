#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Função que verifica se duas strings são anagramas
int ehAnagrama(char* str1, char* str2) {
    int tam1 = strlen(str1);
    int tam2 = strlen(str2);
    
    // Verifica se as strings têm o mesmo tamanho
    if (tam1 != tam2) {
        return 0;
    }
    
    // Remove espaços em branco e acentuação das strings e converte todos os caracteres para minúsculas
    char str1_formatada[tam1+1];
    char str2_formatada[tam2+1];
    int i, j;
    for (i = 0, j = 0; str1[i]; i++) {
        if (!isspace(str1[i])) {
            str1_formatada[j] = tolower(str1[i]);
            j++;
        }
    }
    str1_formatada[j] = '\0';
    for (i = 0, j = 0; str2[i]; i++) {
        if (!isspace(str2[i])) {
            str2_formatada[j] = tolower(str2[i]);
            j++;
        }
    }
    str2_formatada[j] = '\0';
    
    int frequencia[256] = {0};
    for (i = 0; i < tam1; i++) {
        frequencia[(int)str1_formatada[i]]++;
        frequencia[(int)str2_formatada[i]]--;
    }
    for (i = 0; i < 256; i++) {
        if (frequencia[i] != 0) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    char str1[100], str2[100];
    printf("Digite a primeira string: ");
    fgets(str1, 100, stdin);
    printf("Digite a segunda string: ");
    fgets(str2, 100, stdin);
    
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';
    
    if (ehAnagrama(str1, str2)) {
        printf("As strings '%s' e '%s' formam um anagrama.\n", str1, str2);
    } else {
        printf("As strings '%s' e '%s' NÃO formam um anagrama.\n", str1, str2);
    }
    
    return 0;
}

