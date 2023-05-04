#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char frase[100];
    int i, vogais = 0;
    
    printf("Digite uma frase: ");
    fgets(frase, 100, stdin);
    
    for (i = 0; i < strlen(frase); i++) {
        switch (tolower(frase[i])) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vogais++;
                break;
            default:
                break;
        }
    }
    
    printf("\nA frase tem %d vogais.\n", vogais);
    
    return 0;
}

