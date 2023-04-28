#include <stdio.h>
#include <string.h>

int main() {
    char string[100];
    int i, j, flag = 1;

    printf("Digite uma string: ");
    gets(string);

    for(i = 0, j = strlen(string) - 1; i < j; i++, j--) {
        if(string[i] != string[j]) {
            flag = 0;
            break;
        }
    }

    if(flag) {
        printf("%s eh um palindromo.", string);
    } else {
        printf("%s nao eh um palindromo.", string);
    }

    return 0;
}

