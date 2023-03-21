// Deividi Douglas de Carlo FIlho
//	
//
//  ATIVIDADE 2 DO CONTEÚDO 1 –
// AULA EAD SOBRE MÉTODOS DE BUSCA
// SEQUENCIAL E BINÁRIA 

// Descrição do exercício:
// Faça um programa em C que crie um vetor com 500 números inteiros gerados
// aleatoriamente. Em seguida, o programa deverá solicitar um valor do usuário a
// ser buscado no vetor e verificar se o mesmo pertence ou não ao vetor,
// imprimindo a mensagem ao usuário.
// O programa deverá implementar duas formas de busca no vetor: sequencial e
// binária. Para realizar a busca binária, você deverá criar o seu próprio algoritmo
// de ordenação. 



//               RESUMO
// Pensei em fazer de duas formas esse programa:
// Fazer o usuário escolher entre a busca sequencial ou binária
// ou fazer e mostrar o resultado da busca sequencial e binaria junto (escolhi esse)
// mas caso deseje fazer com a primeira opção é só usar Switch case.

// Usarei conceitos aprendido posteriormente em aula, como funções, ponteiros!
// Esse código será postado no GitHub afim educacionais e para demonstrar meus avanços na linguagem C
// Qualque duvida ou erro encontrado, entre em contato via gmail: deividi.filho@aluno.ifsp.edu.br (institucional)
// ou www.linkedin.com/in/Deividi-Filho


// Usaremos 3 funções. Uma para "sortear", outra para fazer a busca sequencial e a outra para busca binária
// Desculpe pelo excesso de comentário, mas estou fazendo o mais didático possível
// pq essa é a melhor forma que achei de aprender. Ensinando outra pessoa.

#include <stdio.h>  // biblioteca padrão do C 
#include <stdlib.h> // biblioteca padrão do C que define funções e macros para gerenciamento de memória, conversão de tipos de dados
#include <time.h>  //  biblioteca padrão do C que fornece funções para manipulação de data e hora.  utilizada neste programa para gerar uma semente aleatória para a função rand.
#include <locale.h> // biblioteca para poder usar o idioma PT-Br

// Função que ordena o vetor usando o algoritmo bubble sort

// Uma breve explicação desse algoritmo: 
// é um algoritmo de ordenação dos mais simples. A ideia é percorrer o vector diversas vezes, 
// e a cada passagem fazer flutuar para o topo o maior elemento da sequência Fonte: Wilipedia 

// Os comentarios explicativo de cada linha foi feitor com a ajuda do chatGPT 3

void bubbleSort(int *vetor, int tamanho) {
	int i, j, aux;
	for (i=0; i<tamanho-1; i++) { // como o indice do vetor começa em 0, é preciso usar o "-1" para pegar o ultimo indice
		for (j=0; j<tamanho-i-1; j++) { // após cada passagem pelo vetor, o maior elemento já estará na sua posição final. (Percorre até a penultima posição não ordenada
			if(vetor[j] > vetor[j+1]) { // realizam a troca de posição de dois elementos adjacentes no vetor, caso o elemento na posição atual j seja maior do que o elemento na posição seguinte j+1. 
				aux  = vetor[j]; // A variável aux é usada para armazenar temporariamente o valor do elemento na posição atual vetor[j]
				vetor[j] = vetor[j+1]; // sobrescrevê-lo com o valor do próximo elemento vetor[j+1]. O valor do próximo elemento é atribuído à posição atual vetor[j]
				vetor[j+1] = aux; // e o valor armazenado em aux é atribuído à posição seguinte vetor[j+1]
			}
		}
	}
}

// Explicação dessa função: (Pelo chatGPT)
// A implementação do bubble sort na função bubbleSort é feita com dois laços for aninhados. O laço externo percorre o vetor inteiro, da posição inicial até a penúltima posição, 
// e o laço interno percorre o vetor da posição inicial até a posição final não ordenada. A cada iteração do laço interno, o algoritmo compara o elemento atual vetor[j] com o 
// próximo elemento vetor[j+1]. Se vetor[j] for maior do que vetor[j+1], os elementos são trocados de posição usando uma variável auxiliar aux. Isso é repetido até que todo o vetor esteja ordenado.
//
// Dessa forma, ao final da execução da função, o vetor passado como parâmetro será ordenado em ordem crescente.

// Função que realiza a busca sequencial no vetor

int buscaSequencial(int *vetor, int tamanho, int valor) {
	int i;
	for(i=0; i<tamanho; i++) {  // Percorrendo o vetor por padrão
		if(vetor[i] == valor) { // Verifica se o valor que você procura está no vetor
			return 1;           // Valor encontrado 
		}
	}
	return 0;                  // Valor não encontrado
}

// Explicação dessa função: (Pelo chatGPT)
// A função buscaSequencial implementa o algoritmo de busca sequencial em um vetor de inteiros. Ele recebe como parâmetros um vetor de inteiros vetor, o tamanho do vetor tamanho
// e o valor que se deseja buscar valor.
// O algoritmo de busca sequencial percorre o vetor da esquerda para a direita, comparando cada elemento do vetor com o valor buscado. Se o elemento for igual ao valor buscado, 
// a busca é interrompida e a função retorna o valor 1, indicando que o valor foi encontrado. Caso contrário, a busca continua até o final do vetor.


// Função que realiza a busca binária no vetor

int buscaBinaria(int *vetor, int tamanho, int valor){
	int inicio = 0;
	int fim = tamanho - 1;
	int meio; 
	while (inicio <= fim) {
		meio = (inicio + fim) / 2; // "Calcula" o meio do vetor
		if (vetor[meio] == valor) { // Verifica se o meio do vetor é o número sendo procurado
			return 1;
		} else if (vetor[meio] < valor){
			inicio = meio + 1;    // Verifica se o meio é menor do que o número procurado (o valor procurado está a direita)
		} else {
			fim = meio - 1;      // Verifica se o meio é maior do que o número procurado (o valor procurado está a esquerda)
		}
	}
	return 0;                   // Valor não encontrado	
}

// Explicação dessa função: (Pelo chatGPT)
// A função buscaBinaria implementa o algoritmo de busca binária em um vetor de inteiros. Ele recebe como parâmetros um vetor de inteiros vetor, o tamanho do vetor tamanho 
// e o valor que se deseja buscar valor.
// inicialmente definimos as variáveis inicio e fim, que representam o intervalo em que vamos procurar o valor. No início, o intervalo é todo o vetor, por isso inicio é definido como 0 
// e fim é definido como tamanho-1.
// Em seguida, temos um laço while que é executado enquanto o intervalo de busca não se reduzir a zero. A cada iteração do laço, o algoritmo calcula o índice do meio do intervalo meio 
// como a média entre inicio e fim. Em seguida, o algoritmo verifica se o valor buscado está no elemento do meio vetor[meio]. Se o valor for encontrado, a função retorna o valor 1 indicando
// que o valor foi encontrado.
// Se o valor buscado não estiver no elemento do meio, o algoritmo verifica se o valor buscado é maior ou menor que o elemento do meio. Se o valor buscado for maior que o elemento do meio, 
// significa que o valor procurado está na metade direita do intervalo, então o algoritmo redefine inicio como meio + 1. Caso contrário, o valor procurado está na metade esquerda do intervalo, 
// então o algoritmo redefine fim como meio - 1.


int main(){ // Função main é a função principal. Um tipo de ponto de partida
    setlocale(LC_ALL,"Portuguese"); // estamos definindo a localização para Portugal 
	
	int vetor[5000];
	int i, valor, encontradoSeq, encontradoBin;
	
	srand(time(NULL)); // Gera os 500 números aleatórios. OBS: Precisei de uma ajuda do chatGPT pq estava dando erro e não encontrei a solução
	for(i=0; i<50; i++){
		vetor[i] = rand() % 1000; // Gera números aleatório de 1 a 1000;
	}
	
	bubbleSort(vetor, 500); // Ordena o vetor com o Bubble sort, a primeira função criada
	
	printf("\n Digite um valor a ser buscado no vetor: "); // Solicita um valor para ser buscado
	scanf("%d", &valor);
	
	encontradoSeq = buscaSequencial(vetor, 500, valor); // Realiza a busca sequencial (Chama a função e passa os paramêtros)
	if (encontradoSeq) {
		printf("\n O valor %d foi encontrado no vetor usando o algoritmo de busca SEQUENCIAL", valor);
	} else {
		printf("\n O valor %d NÃO foi encontrado no vetor usando o algoritmo de busca SEQUENCIAL", valor);
	}
	
	encontradoBin = buscaBinaria(vetor, 500, valor); // Realiza a busca sequencial (Chama a função e passa os paramêtros)
	if (encontradoBin){
		printf("\n O valor %d foi encontrado no vetor usando o algoritmo de busca BINÁRIA", valor);
	} else {
		printf("\n O valor %d NÃO foi encontrado no vetor usando o algoritmo de busca BINÁRIA", valor);
	}
	return 0;
}

// Explicação dessa função: (Pelo chatGPT)
// a primeira coisa que é feita é definir a localização para o Brasil, com suporte a caracteres UTF-8, usando a função setlocale.
// Em seguida, é criado um vetor de 500 inteiros e é utilizado a função srand(time(NULL)) para inicializar a semente do gerador de
// números aleatórios, garantindo que cada vez que o programa for executado, os números gerados serão diferentes. Então, são gerados
//  500 números aleatórios de 1 a 1000 usando a função rand().
//
// Depois, é utilizado o algoritmo Bubble Sort para ordenar o vetor gerado. Em seguida, o programa solicita que o usuário digite um valor
// a ser buscado no vetor.
//
// A função buscaSequencial é chamada para realizar a busca sequencial no vetor. Se o valor for encontrado, a mensagem 
// "O valor X foi encontrado no vetor usando o algoritmo de busca SEQUENCIAL" é impressa na tela. Caso contrário, a mensagem 
// "O valor X NÃO foi encontrado no vetor usando o algoritmo de busca SEQUENCIAL" é exibida.
//
// A função buscaBinaria é chamada para realizar a busca binária no vetor. Se o valor for encontrado, a mensagem 
// "O valor X foi encontrado no vetor usando busca BINÁRIA" é impressa na tela. Caso contrário, a mensagem 
// "O valor X NÃO foi encontrado no vetor usando busca BINÁRIA" é exibida.
// Por fim, a função main retorna 0, indicando que o programa foi executado com sucesso.

// Fiz pouco teste, aparentemente quando escolhe o valor "0" para ser procurado sempre é encontrado. 
// Provavelmente um "bug" que precisa ser corrigido. Apenas testar e dizer que não pode ser 0. 



