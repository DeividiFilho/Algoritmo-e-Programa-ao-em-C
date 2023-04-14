#include <stdio.h>

struct habitante {
  float salario;
  char sexo;
  int idade;
  int num_filhos;
};

	float media_salarios(struct habitante habitantes[], int n) {
	float soma = 0;
	int i;
 	for (i = 0; i < n; i++) {
 		soma += habitantes[i].salario;
 	}
	return soma / n;
	}

	float media_filhos(struct habitante habitantes[], int n) {
    float soma = 0;
    int i;
    for (i = 0; i < n; i++) {
    	soma += habitantes[i].num_filhos;
   }
   return soma / n;
}

	void maior_menor_salario(struct habitante habitantes[], int n, float *maior, float *menor) {
   *maior = habitantes[0].salario;
   *menor = habitantes[0].salario;
   int i;
	for ( i = 1; i < n; i++) {
    if (habitantes[i].salario > *maior) {
      *maior = habitantes[i].salario;
    }
    if (habitantes[i].salario < *menor) {
      *menor = habitantes[i].salario;
    }
  }
}

	float percentual_mulheres_salario_alto(struct habitante habitantes[], int n) {
	int total_mulheres = 0;
  	int mulheres_salario_alto = 0;
  	int i;
  	for ( i = 0; i < n; i++) {
    if (habitantes[i].sexo == 'F') {
      total_mulheres++;
      if (habitantes[i].salario > 1500.0) {
        mulheres_salario_alto++;
      }
    }
  }
  return 100.0 * mulheres_salario_alto / total_mulheres;
}


int main() {
  struct habitante habitantes[500];
  int n;

  printf("Digite o número de habitantes: ");
  scanf("%d", &n);

	int i;
    for ( i = 0; i < n; i++) {
    printf("Habitante %d:\n", i+1);
    printf("Salário: ");
    scanf("%f", &habitantes[i].salario);
    printf("Sexo (M/F): ");
    scanf(" %c", &habitantes[i].sexo);
    printf("Idade: ");
    scanf("%d", &habitantes[i].idade);
    printf("Número de filhos: ");
    scanf("%d", &habitantes[i].num_filhos);
  }

  printf("\nMédia de salários: %.2f\n", media_salarios(habitantes, n));
  printf("Número médio de filhos: %.2f\n", media_filhos(habitantes, n));

  float maior_salario, menor_salario;
  maior_menor_salario(habitantes, n, &maior_salario, &menor_salario);
  printf("Maior salário: %.2f\n", maior_salario);
  printf("Menor salário: %.2f\n", menor_salario);

  printf("Percentual de mulheres com salário superior a R$1.500,00: %.2f%%\n",
         percentual_mulheres_salario_alto(habitantes, n));

  return 0;
}

