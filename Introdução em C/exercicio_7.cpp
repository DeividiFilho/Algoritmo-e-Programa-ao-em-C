//7- Faça um programa que receba dois números e
//execute uma das operações listadas a seguir, de
//acordo com a escolha do usuário. Se for digitada
//uma opção inválida, mostre a mensagem de erro e
//finalize o programa. As opções são:
//1. Primeiro número elevado ao segundo número;
//2. Raiz quadrada de cada número;
//3. Raiz cúbica de cada número;
//4. Produto dos números;
//OBS: Usar comando de seleção múltipla (case)

#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    int opcao;
    float num1, num2, resultado;
    setlocale(LC_ALL,"");
    
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    
    printf("Escolha uma opção:\n");
    printf("1. Primeiro número elevado ao segundo número\n");
    printf("2. Raiz quadrada de cada número\n");
    printf("3. Raiz cúbica de cada número\n");
    printf("4. Produto dos números\n");
    scanf("%d", &opcao);
    
    switch (opcao) {
        case 1:
            resultado = pow(num1, num2);
            printf("%.2f elevado a %.2f é igual a %.2f\n", num1, num2, resultado);
            break;
        case 2:
            printf("A raiz quadrada de %.2f é %.2f\n", num1, sqrt(num1));
            printf("A raiz quadrada de %.2f é %.2f\n", num2, sqrt(num2));
            break;
        case 3:
            printf("A raiz cúbica de %.2f é %.2f\n", num1, cbrt(num1));
            printf("A raiz cúbica de %.2f é %.2f\n", num2, cbrt(num2));
            break;
        case 4:
            resultado = num1 * num2;
            printf("O produto entre %.2f e %.2f é igual a %.2f\n", num1, num2, resultado);
            break;
        default:
            printf("Opção inválida.\n");
            break;
    }
    
    return 0;
}

