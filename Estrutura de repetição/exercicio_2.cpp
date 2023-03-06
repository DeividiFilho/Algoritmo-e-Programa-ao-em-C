//2- Faça um programa que receba um número inteiro
//maior que 1 e verifique se o número é primo. 
//Considere que um número primo é divisível apenas por
//1 e por ele mesmo.
//Obs: Faça três versões do programa, uma para
//cada estrutura de repetição (for, while e do- while).

// Com for
#include <stdio.h>

int main() {
    int num, i, eh_primo = 1;

    printf("Digite um número inteiro maior que 1: ");
    scanf("%d", &num);

    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            eh_primo = 0;
            break;
        }
    }

    if (eh_primo == 1) {
        printf("%d é primo\n", num);
    } else {
        printf("%d não é primo\n", num);
    }

    return 0;
}

// Com while
//#include <stdio.h>
//
//int main() {
//    int num, i = 2, eh_primo = 1;
//
//    printf("Digite um número inteiro maior que 1: ");
//    scanf("%d", &num);
//
//    while (i < num) {
//        if (num % i == 0) {
//            eh_primo = 0;
//            break;
//        }
//        i++;
//    }
//
//    if (eh_primo == 1) {
//        printf("%d é primo\n", num);
//    } else {
//        printf("%d não é primo\n", num);
//    }
//
//    return 0;
//}

// Com Do While
//#include <stdio.h>
//
//int main() {
//    int num, i = 2, eh_primo = 1;
//
//    printf("Digite um número inteiro maior que 1: ");
//    scanf("%d", &num);
//
//    do {
//        if (num % i == 0) {
//            eh_primo = 0;
//            break;
//        }
//        i++;
//    } while (i < num);
//
//    if (eh_primo == 1) {
//        printf("%d é primo\n", num);
//    } else {
//        printf("%d não é primo\n", num);
//    }
//
//    return 0;
//}


