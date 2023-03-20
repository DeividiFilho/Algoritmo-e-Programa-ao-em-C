// Deividi Douglas de Carlo FIlho
//	
//
//  ATIVIDADE 2 DO CONTE�DO 1 �
// AULA EAD SOBRE M�TODOS DE BUSCA
// SEQUENCIAL E BIN�RIA 

// Descri��o do exerc�cio:
// Fa�a um programa em C que crie um vetor com 500 n�meros inteiros gerados
// aleatoriamente. Em seguida, o programa dever� solicitar um valor do usu�rio a
// ser buscado no vetor e verificar se o mesmo pertence ou n�o ao vetor,
// imprimindo a mensagem ao usu�rio.
// O programa dever� implementar duas formas de busca no vetor: sequencial e
// bin�ria. Para realizar a busca bin�ria, voc� dever� criar o seu pr�prio algoritmo
// de ordena��o. 



//               RESUMO
// Pensei em fazer de duas formas esse programa:
// Fazer o usu�rio escolher entre a busca sequencial ou bin�ria
// ou fazer e mostrar o resultado da busca sequencial e binaria junto (escolhi esse)
// mas caso deseje fazer com a primeira op��o � s� usar Switch case.

// Usarei conceitos aprendido posteriormente em aula, como fun��es, ponteiros!
// Esse c�digo ser� postado no GitHub afim educacionais e para demonstrar meus avan�os na linguagem C
// Qualque duvida ou erro encontrado, entre em contato via gmail: deividi.filho@aluno.ifsp.edu.br (institucional
// deividifilhom2017@gmail.com (gmail pessoal) ou www.linkedin.com/in/Deividi-Filho


// Usaremos 3 fun��es. Uma para "sortear", outra para fazer a busca sequencial e a outra para busca bin�ria
// Desculpe pelo excesso de coment�rio, mas estou fazendo o mais did�tico poss�vel
// pq essa � a melhor forma que achei de aprender. Ensinando outra pessoa.

#include <stdio.h>  // biblioteca padr�o do C 
#include <stdlib.h> // biblioteca padr�o do C que define fun��es e macros para gerenciamento de mem�ria, convers�o de tipos de dados
#include <time.h>  //  biblioteca padr�o do C que fornece fun��es para manipula��o de data e hora.  utilizada neste programa para gerar uma semente aleat�ria para a fun��o rand.
#include <locale.h> // biblioteca para poder usar o idioma PT-Br

// Fun��o que ordena o vetor usando o algoritmo bubble sort

// Uma breve explica��o desse algoritmo: 
// � um algoritmo de ordena��o dos mais simples. A ideia � percorrer o vector diversas vezes, 
// e a cada passagem fazer flutuar para o topo o maior elemento da sequ�ncia Fonte: Wilipedia 

// Os comentarios explicativo de cada linha foi feitor com a ajuda do chatGPT 3

void bubbleSort(int *vetor, int tamanho) {
	int i, j, aux;
	for (i=0; i<tamanho-1; i++) { // como o indice do vetor come�a em 0, � preciso usar o "-1" para pegar o ultimo indice
		for (j=0; j<tamanho-i-1; j++) { // ap�s cada passagem pelo vetor, o maior elemento j� estar� na sua posi��o final. (Percorre at� a penultima posi��o n�o ordenada
			if(vetor[j] > vetor[j+1]) { // realizam a troca de posi��o de dois elementos adjacentes no vetor, caso o elemento na posi��o atual j seja maior do que o elemento na posi��o seguinte j+1. 
				aux  = vetor[j]; // A vari�vel aux � usada para armazenar temporariamente o valor do elemento na posi��o atual vetor[j]
				vetor[j] = vetor[j+1]; // sobrescrev�-lo com o valor do pr�ximo elemento vetor[j+1]. O valor do pr�ximo elemento � atribu�do � posi��o atual vetor[j]
				vetor[j+1] = aux; // e o valor armazenado em aux � atribu�do � posi��o seguinte vetor[j+1]
			}
		}
	}
}

// Explica��o dessa fun��o: (Pelo chatGPT)
// A implementa��o do bubble sort na fun��o bubbleSort � feita com dois la�os for aninhados. O la�o externo percorre o vetor inteiro, da posi��o inicial at� a pen�ltima posi��o, 
// e o la�o interno percorre o vetor da posi��o inicial at� a posi��o final n�o ordenada. A cada itera��o do la�o interno, o algoritmo compara o elemento atual vetor[j] com o 
// pr�ximo elemento vetor[j+1]. Se vetor[j] for maior do que vetor[j+1], os elementos s�o trocados de posi��o usando uma vari�vel auxiliar aux. Isso � repetido at� que todo o vetor esteja ordenado.
//
// Dessa forma, ao final da execu��o da fun��o, o vetor passado como par�metro ser� ordenado em ordem crescente.

// Fun��o que realiza a busca sequencial no vetor

int buscaSequencial(int *vetor, int tamanho, int valor) {
	int i;
	for(i=0; i<tamanho; i++) {  // Percorrendo o vetor por padr�o
		if(vetor[i] == valor) { // Verifica se o valor que voc� procura est� no vetor
			return 1;           // Valor encontrado 
		}
	}
	return 0;                  // Valor n�o encontrado
}

// Explica��o dessa fun��o: (Pelo chatGPT)
// A fun��o buscaSequencial implementa o algoritmo de busca sequencial em um vetor de inteiros. Ele recebe como par�metros um vetor de inteiros vetor, o tamanho do vetor tamanho
// e o valor que se deseja buscar valor.
// O algoritmo de busca sequencial percorre o vetor da esquerda para a direita, comparando cada elemento do vetor com o valor buscado. Se o elemento for igual ao valor buscado, 
// a busca � interrompida e a fun��o retorna o valor 1, indicando que o valor foi encontrado. Caso contr�rio, a busca continua at� o final do vetor.


// Fun��o que realiza a busca bin�ria no vetor

int buscaBinaria(int *vetor, int tamanho, int valor){
	int inicio = 0;
	int fim = tamanho - 1;
	int meio; 
	while (inicio <= fim) {
		meio = (inicio + fim) / 2; // "Calcula" o meio do vetor
		if (vetor[meio] == valor) { // Verifica se o meio do vetor � o n�mero sendo procurado
			return 1;
		} else if (vetor[meio] < valor){
			inicio = meio + 1;    // Verifica se o meio � menor do que o n�mero procurado (o valor procurado est� a direita)
		} else {
			fim = meio - 1;      // Verifica se o meio � maior do que o n�mero procurado (o valor procurado est� a esquerda)
		}
	}
	return 0;                   // Valor n�o encontrado	
}

// Explica��o dessa fun��o: (Pelo chatGPT)
// A fun��o buscaBinaria implementa o algoritmo de busca bin�ria em um vetor de inteiros. Ele recebe como par�metros um vetor de inteiros vetor, o tamanho do vetor tamanho 
// e o valor que se deseja buscar valor.
// inicialmente definimos as vari�veis inicio e fim, que representam o intervalo em que vamos procurar o valor. No in�cio, o intervalo � todo o vetor, por isso inicio � definido como 0 
// e fim � definido como tamanho-1.
// Em seguida, temos um la�o while que � executado enquanto o intervalo de busca n�o se reduzir a zero. A cada itera��o do la�o, o algoritmo calcula o �ndice do meio do intervalo meio 
// como a m�dia entre inicio e fim. Em seguida, o algoritmo verifica se o valor buscado est� no elemento do meio vetor[meio]. Se o valor for encontrado, a fun��o retorna o valor 1 indicando
// que o valor foi encontrado.
// Se o valor buscado n�o estiver no elemento do meio, o algoritmo verifica se o valor buscado � maior ou menor que o elemento do meio. Se o valor buscado for maior que o elemento do meio, 
// significa que o valor procurado est� na metade direita do intervalo, ent�o o algoritmo redefine inicio como meio + 1. Caso contr�rio, o valor procurado est� na metade esquerda do intervalo, 
// ent�o o algoritmo redefine fim como meio - 1.


int main(){ // Fun��o main � a fun��o principal. Um tipo de ponto de partida
    setlocale(LC_ALL,"Portuguese"); // estamos definindo a localiza��o para Portugal 
	
	int vetor[5000];
	int i, valor, encontradoSeq, encontradoBin;
	
	srand(time(NULL)); // Gera os 500 n�meros aleat�rios. OBS: Precisei de uma ajuda do chatGPT pq estava dando erro e n�o encontrei a solu��o
	for(i=0; i<50; i++){
		vetor[i] = rand() % 1000; // Gera n�meros aleat�rio de 1 a 1000;
	}
	
	bubbleSort(vetor, 500); // Ordena o vetor com o Bubble sort, a primeira fun��o criada
	
	printf("\n Digite um valor a ser buscado no vetor: "); // Solicita um valor para ser buscado
	scanf("%d", &valor);
	
	encontradoSeq = buscaSequencial(vetor, 500, valor); // Realiza a busca sequencial (Chama a fun��o e passa os param�tros)
	if (encontradoSeq) {
		printf("\n O valor %d foi encontrado no vetor usando o algoritmo de busca SEQUENCIAL", valor);
	} else {
		printf("\n O valor %d N�O foi encontrado no vetor usando o algoritmo de busca SEQUENCIAL", valor);
	}
	
	encontradoBin = buscaBinaria(vetor, 500, valor); // Realiza a busca sequencial (Chama a fun��o e passa os param�tros)
	if (encontradoBin){
		printf("\n O valor %d foi encontrado no vetor usando o algoritmo de busca BIN�RIA", valor);
	} else {
		printf("\n O valor %d N�O foi encontrado no vetor usando o algoritmo de busca BIN�RIA", valor);
	}
	return 0;
}

// Explica��o dessa fun��o: (Pelo chatGPT)
// a primeira coisa que � feita � definir a localiza��o para o Brasil, com suporte a caracteres UTF-8, usando a fun��o setlocale.
// Em seguida, � criado um vetor de 500 inteiros e � utilizado a fun��o srand(time(NULL)) para inicializar a semente do gerador de
// n�meros aleat�rios, garantindo que cada vez que o programa for executado, os n�meros gerados ser�o diferentes. Ent�o, s�o gerados
//  500 n�meros aleat�rios de 1 a 1000 usando a fun��o rand().
//
// Depois, � utilizado o algoritmo Bubble Sort para ordenar o vetor gerado. Em seguida, o programa solicita que o usu�rio digite um valor
// a ser buscado no vetor.
//
// A fun��o buscaSequencial � chamada para realizar a busca sequencial no vetor. Se o valor for encontrado, a mensagem 
// "O valor X foi encontrado no vetor usando o algoritmo de busca SEQUENCIAL" � impressa na tela. Caso contr�rio, a mensagem 
// "O valor X N�O foi encontrado no vetor usando o algoritmo de busca SEQUENCIAL" � exibida.
//
// A fun��o buscaBinaria � chamada para realizar a busca bin�ria no vetor. Se o valor for encontrado, a mensagem 
// "O valor X foi encontrado no vetor usando busca BIN�RIA" � impressa na tela. Caso contr�rio, a mensagem 
// "O valor X N�O foi encontrado no vetor usando busca BIN�RIA" � exibida.
// Por fim, a fun��o main retorna 0, indicando que o programa foi executado com sucesso.

// Fiz pouco teste, aparentemente quando escolhe o valor "0" para ser procurado sempre � encontrado. 
// Provavelmente um "bug" que precisa ser corrigido. Apenas testar e dizer que n�o pode ser 0. 



