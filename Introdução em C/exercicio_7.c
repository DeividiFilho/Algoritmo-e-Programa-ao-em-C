//7- Fa�a um programa que receba dois n�meros e
//execute uma das opera��es listadas a seguir, de
//acordo com a escolha do usu�rio. Se for digitada
//uma op��o inv�lida, mostre a mensagem de erro e
//finalize o programa. As op��es s�o:
//1. Primeiro n�mero elevado ao segundo n�mero;
//2. Raiz quadrada de cada n�mero;
//3. Raiz c�bica de cada n�mero;
//4. Produto dos n�meros;
//OBS: Usar comando de sele��o m�ltipla (case)

#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    int opcao;
    float num1, num2, resultado;
    setlocale(LC_ALL,"");
    
    printf("Digite o primeiro n�mero: ");
    scanf("%f", &num1);
    
    printf("Digite o segundo n�mero: ");
    scanf("%f", &num2);
    
    printf("Escolha uma op��o:\n");
    printf("1. Primeiro n�mero elevado ao segundo n�mero\n");
    printf("2. Raiz quadrada de cada n�mero\n");
    printf("3. Raiz c�bica de cada n�mero\n");
    printf("4. Produto dos n�meros\n");
    scanf("%d", &opcao);
    
    switch (opcao) {
        case 1:
            resultado = pow(num1, num2);
            printf("%.2f elevado a %.2f � igual a %.2f\n", num1, num2, resultado);
            break;
        case 2:
            printf("A raiz quadrada de %.2f � %.2f\n", num1, sqrt(num1));
            printf("A raiz quadrada de %.2f � %.2f\n", num2, sqrt(num2));
            break;
        case 3:
            printf("A raiz c�bica de %.2f � %.2f\n", num1, cbrt(num1));
            printf("A raiz c�bica de %.2f � %.2f\n", num2, cbrt(num2));
            break;
        case 4:
            resultado = num1 * num2;
            printf("O produto entre %.2f e %.2f � igual a %.2f\n", num1, num2, resultado);
            break;
        default:
            printf("Op��o inv�lida.\n");
            break;
    }
    
    return 0;
}

