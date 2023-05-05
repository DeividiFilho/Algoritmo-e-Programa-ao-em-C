// Compromisso

#include <stdio.h>

typedef struct {
	int hora;
	int minutos;
	int segundos;
} Horario;

typedef struct {
	int dia;
	int mes;
	int ano;
} Data;

typedef struct {
	Horario horario;
	Data data;
	char descricao[100];
} Compromisso;

main() {
	Horario hora;
	printf("Digite a o horario (Hora, Minutos e segundos): ");
	scanf("%d %d %d", &hora.hora, &hora.minutos, &hora.segundos);
	
	Data data;
	printf("Digite a data (Dia, mes e ano): ");
	scanf("%d %d %d", &data.dia, &data.mes, &data.ano);ex
}
