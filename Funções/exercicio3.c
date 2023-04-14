#include <stdio.h>
#include <string.h>

void remover_caractere(char *str, char c) {
    char *p = strchr(str, c);
    if (p != NULL) {
        memmove(p, p + 1, strlen(p));
    }
}

int main() {
    char str[100], c;
    printf("Digite uma string: ");
    fgets(str, 100, stdin);
    printf("Digite um caractere a ser removido: ");
    scanf("%c", &c);
    remover_caractere(str, c);
    printf("String resultante: %s", str);
    return 0;
}


