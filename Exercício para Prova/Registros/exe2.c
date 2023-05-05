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
	printf("Digite o horario (Hora, Minutos e segundos): ");
	scanf("%d %d %d", &hora.hora, &hora.minutos, &hora.segundos);
	
	Data data;
	printf("Digite a data (Dia, Mes e Ano): ");
	scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
	
	Compromisso compromisso;
	compromisso.data = data;
	compromisso.horario = hora;
	printf("Digite a descricao: ");
	scanf("%s", &compromisso.descricao);
//	strcpy(compromisso.descricao, "Reuniao com a equipe");
	
	printf("\nData: %d/%d/%d\n", compromisso.data.dia, compromisso.data.mes, compromisso.data.ano);
	printf("Horario: %d:%d:%d\n", compromisso.horario.hora, compromisso.horario.minutos, compromisso.horario.segundos);
	printf("Descricao: %s\n", compromisso.descricao);
}
