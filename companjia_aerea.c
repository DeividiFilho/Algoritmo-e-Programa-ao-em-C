#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PILOTO 100
#define MAX_VOOS 100
#define MAX_VIAGENS 100

// SC3022862 - Jonatas Henrique Salles
// SC3029948 - Deividi Filho

typedef struct {
  int dia, mes, ano;
} Data;

typedef struct {
  char registro_piloto[15], nome[40], sexo[20], curso[50], emails[10][50],
      telefones[10][50];
  int qtd_emails, qtd_telefones;
  Data data_nascimento;
} Piloto;

typedef struct {
  int numero, qtd_escalas;
  char cidade_origem[50], cidade_destino[50], aeronave[50], escalas[50][10],
      tempo_medio[10];
  float distancia;
} Voo;

typedef struct {
  int numero_voo, qtd_ocorrencias;
  char registro_piloto[15], hora_saida[10], hora_chegada[10],
      ocorrencias[200][10], pk[200];
  Data data_saida, data_chegada;
} Viagem;

void menu();

// PILOTOS
void submenu_pilotos(Piloto pilotos[], int *idx_pilotos);
int inserir_piloto(Piloto pilotos[], int *idx_pilotos);
int buscar_piloto(Piloto pilotos[], char registro[], int qtd_pilotos);
void listar_piloto(Piloto pilotos[], int indice, int qtd_pilotos);
void listar_todos_pilotos(Piloto pilotos[], int qtd_pilotos);
int alterar_piloto(Piloto pilotos[], int indice, int qtd_pilotos);
int adicionar_email(Piloto pilotos[], int indice);
int alterar_email(Piloto pilotos[], int indice, int idx_email);
int remover_email(Piloto pilotos[], int indice, int idx_email);
int adicionar_telefone(Piloto pilotos[], int indice);
int alterar_telefone(Piloto pilotos[], int indice, int idx_telefone);
int remover_telefone(Piloto pilotos[], int indice, int idx_telefone);
void remover_piloto(Piloto pilotos[], int indice, int *qtd_pilotos);

// VOOS
void submenu_voos(Voo voos[], int *idx_voos);
int inserir_voo(Voo voos[], int *idx_voos);
int buscar_voo(Voo voos[], int num, int qtd_voos);
void listar_voo(Voo voos[], int indice, int qtd_voos);
void listar_todos_voos(Voo voos[], int qtd_voos);
int alterar_voo(Voo voos[], int indice, int qtd_voos);
int adicionar_escala(Voo voos[], int indice);
int alterar_escala(Voo voos[], int indice, int idx_escala);
int remover_escala(Voo voos[], int indice, int idx_escala);
void remover_voo(Voo voos[], int indice, int *qtd_voos);

// VIAGENS
void submenu_viagens(Viagem viagens[], Voo voos[], Piloto pilotos[],
                     int *idx_viagens, int idx_voos, int idx_pilotos);
int inserir_viagem(Viagem viagens[], Voo voos[], Piloto pilotos[],
                   int *idx_viagens, int idx_voos, int idx_pilotos);
int buscar_viagem(Viagem viagens[], char pk[], int qtd_viagens);
void listar_viagem(Viagem viagens[], int indice, int qtd_viagens);
void listar_todas_viagens(Viagem viagens[], int qtd_viagens);
int listar_viagens_por_voo(Viagem viagens[], int num, int qtd_viagens);
void alterar_viagem(Viagem viagens[], int indice, int qtd_viagens);
int adicionar_ocorrencia(Viagem viagens[], int indice);
int alterar_ocorrencia(Viagem viagens[], int indice, int idx_ocorrencia);
int remover_ocorrencia(Viagem viagens[], int indice, int idx_ocorrencia);
void remover_viagem(Viagem viagens[], int indice, int *qtd_viagens);

// RELATORIOS
void submenu_relatorios(Viagem viagens[], Voo voos[], Piloto pilotos[],
                        int idx_viagens, int idx_voos, int idx_pilotos);
int calcular_idade(Piloto pilotos[], int indice, int qtd_pilotos);
int verificar_intervalo_datas(Viagem viagem, Data data_x, Data data_y);

int main() {
  setlocale(LC_ALL, "Portuguese");
  int opcao, qtd_pilotos = 0, qtd_voos = 0, qtd_viagens = 0;
  Piloto pilotos[MAX_PILOTO];
  Voo voos[MAX_VOOS];
  Viagem viagens[MAX_VIAGENS];

  do {
    menu();
    scanf("%d", &opcao);
    switch (opcao) {
    case 0:
      system("cls");
      printf("\nSaindo...\n");
      break;

    case 1:
      system("cls");
      submenu_pilotos(pilotos, &qtd_pilotos);
      break;

    case 2:
      system("cls");
      submenu_voos(voos, &qtd_voos);
      break;

    case 3:
      system("cls");
      submenu_viagens(viagens, voos, pilotos, &qtd_viagens, qtd_voos,
                      qtd_pilotos);
      break;

    case 4:
      system("cls");
      submenu_relatorios(viagens, voos, pilotos, qtd_viagens, qtd_voos,
                         qtd_pilotos);
      break;

    default:
      printf("Opcao invalida!\n");
    }
  } while (opcao != 0 && opcao >= 1 && opcao <= 4);

  return 0;
}

void menu() {
  system("cls");
  printf("**********Menu de Opcoes**********\n\n");
  printf("\t1. Acessar submenu Pilotos.\n");
  printf("\t2. Acessar submenu Voos.\n");
  printf("\t3. Acessar submenu Viagens.\n");
  printf("\t4. Acessar submenu Relatorios.\n");
  printf("\nEscolha uma opcao entre 1 e 4 ou digite 0 para sair: ");
}

// PILOTOS
void submenu_pilotos(Piloto pilotos[], int *idx_pilotos) {
  int opcao, encontrou;
  char registro[15];
  FILE *arquivo;

  do {
    printf("\n**********Submenu de Pilotos**********\n\n");
    printf("\t1. Registrar Piloto.\n");
    printf("\t2. Listar um Piloto.\n");
    printf("\t3. Listar todos os Pilotos.\n");
    printf("\t4. Alterar Piloto.\n");
    printf("\t5. Excluir Piloto.\n");
    printf("\nEscolha uma opcao entre 1 e 5 ou digite 0 para voltar ao menu "
           "principal: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 0:
      printf("Voltando para o menu principal...\n");
      break;

    case 1:
      if (inserir_piloto(pilotos, &(*idx_pilotos)) == 1) {
        printf("Piloto registrado com sucesso!\n");
        arquivo = fopen("pilotos.txt", "a");
        if (arquivo == NULL) {
          printf("Erro ao abrir o arquivo de pilotos.\n");
          return;
        }
        fprintf(arquivo, "%s %s\n", pilotos[*idx_pilotos - 1].registro,
                pilotos[*idx_pilotos - 1].nome);
        fclose(arquivo);
      } else {
        printf("Registro de piloto ja existe!\n");
      }
      break;

    case 2:
      fflush(stdin);
      printf("Digite o registro do piloto que deseja imprimir: ");
      scanf("%s", registro);
      encontrou = buscar_piloto(pilotos, registro, *idx_pilotos);

      if (encontrou >= 0) {
        listar_piloto(pilotos, encontrou, *idx_pilotos);
      } else {
        printf("Piloto nao encontrado!\n");
      }
      break;

    case 3:
      listar_todos_pilotos(pilotos, *idx_pilotos);
      break;

    case 4:
      fflush(stdin);
      printf("Digite o registro do piloto que deseja alterar: ");
      scanf("%s", registro);
      encontrou = buscar_piloto(pilotos, registro, *idx_pilotos);

      if (encontrou >= 0) {
        alterar_piloto(pilotos, encontrou, *idx_pilotos);
        printf("Piloto alterado com sucesso!");

        arquivo = fopen("pilotos.txt", "w");
        if (arquivo == NULL) {
          printf("Erro ao abrir o arquivo de pilotos.\n");
          return;
        }
        for (int i = 0; i < *idx_pilotos; i++) {
          fprintf(arquivo, "%s %s\n", pilotos[i].registro, pilotos[i].nome);
        }
        fclose(arquivo);
      } else {
        printf("Piloto nao encontrado!\n");
      }
      break;

    case 5:
      fflush(stdin);
      printf("Digite o registro do piloto que deseja excluir: ");
                scanf("%s", registro, encontrou = buscar_piloto(pilotos, registro, *idx_pilotos);

                if (encontrou >= 0) {
        remover_piloto(pilotos, encontrou, &(*idx_pilotos));
        printf("Piloto removido com sucesso!\n");

        arquivo = fopen("pilotos.txt", "w");
        if (arquivo == NULL) {
          printf("Erro ao abrir o arquivo de pilotos.\n");
          return;
        }
        for (int i = 0; i < *idx_pilotos; i++) {
          fprintf(arquivo, "%s %s\n", pilotos[i].registro, pilotos[i].nome);
        }
        fclose(arquivo);
                } else {
        printf("Piloto nao encontrado!\n");
                }
                break;

            default:
                printf("Opcao invalida!\n");
    }
  } while (opcao != 0 && opcao >= 1 && opcao <= 5);
}

int inserir_piloto(Piloto pilotos[], int *idx_pilotos) {
  char entrada[50], registro[15];
  int i;
  FILE *arquivo;

  fflush(stdin);
  printf("\nRegistro Piloto: ");
  gets(registro);
  if (buscar_piloto(pilotos, registro, *idx_pilotos) >= 0 ||
      *idx_pilotos >= MAX_PILOTO) {
    return -1;
  }
  strcpy(pilotos[*idx_pilotos].registro_piloto, registro);
  printf("Nome: ");
  gets(pilotos[*idx_pilotos].nome);
  printf("Data de nascimento\n");
  printf("Dia: ");
  scanf("%d", &pilotos[*idx_pilotos].data_nascimento.dia);
  printf("Mes: ");
  scanf("%d", &pilotos[*idx_pilotos].data_nascimento.mes);
  printf("Ano: ");
  scanf("%d", &pilotos[*idx_pilotos].data_nascimento.ano);
  fflush(stdin);
  printf("Sexo: ");
  gets(pilotos[*idx_pilotos].sexo);
  printf("Curso: ");
  gets(pilotos[*idx_pilotos].curso);

  printf("\nInsercao de emails: Digite 0 para encerrar insercao\n\n");
  for (i = 0; i < 10; i++) {
    printf("Email %d: ", i + 1);
    gets(entrada);
    if (stricmp(entrada, "0") != 0) {
      strcpy(pilotos[*idx_pilotos].emails[i], entrada);
      pilotos[*idx_pilotos].qtd_emails++;
    } else {
      i = 10;
    }
  }

  printf("\nInsercao de telefones: Digite 0 para encerrar insercao\n\n");
  for (i = 0; i < 10; i++) {
    printf("Telefone %d: ", i + 1);
    gets(entrada);
    if (stricmp(entrada, "0") != 0) {
      strcpy(pilotos[*idx_pilotos].telefones[i], entrada);
      pilotos[*idx_pilotos].qtd_telefones++;
    } else {
      i = 10;
    }
  }

  (*idx_pilotos)++;

  arquivo = fopen("pilotos.txt", "a");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo de pilotos.\n");
    return -1;
  }
  fprintf(arquivo, "%s %s\n", pilotos[*idx_pilotos - 1].registro_piloto,
          pilotos[*idx_pilotos - 1].nome);
  fclose(arquivo);

  return 1;
}

int buscar_piloto(Piloto pilotos[], char registro[], int qtd_pilotos) {
  int i;

  for (i = 0; i < qtd_pilotos; i++) {
    if (stricmp(pilotos[i].registro_piloto, registro) == 0) {
      return i;
    }
  }
  return -1;
}

void listar_piloto(Piloto pilotos[], int indice, int qtd_pilotos) {
  FILE *arquivo;
  char registro[15], nome[50];
  int i;

  arquivo = fopen("pilotos.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo de pilotos.\n");
    return;
  }

  for (i = 0; i <= indice; i++) {
    fscanf(arquivo, "%s %[^\n]s", registro, nome);
  }

  fclose(arquivo);

  printf("\n****************************************\n");
  printf("\nImprimindo Piloto de registro: %s\n",
         pilotos[indice].registro_piloto);
  printf("\nNome: %s\n", nome);
  printf("Data de Nascimento: %2d/%02d/%04d\n",
         pilotos[indice].data_nascimento.dia,
         pilotos[indice].data_nascimento.mes,
         pilotos[indice].data_nascimento.ano);
  printf("Sexo: %s\n", pilotos[indice].sexo);
  printf("Curso: %s\n", pilotos[indice].curso);
  for (i = 0; i < pilotos[indice].qtd_emails; i++) {
    printf("Email %d: %s\n", i + 1, pilotos[indice].emails[i]);
  }
  for (i = 0; i < pilotos[indice].qtd_telefones; i++) {
    printf("Telefone %d: %s\n", i + 1, pilotos[indice].telefones[i]);
  }
  printf("\n****************************************\n");
}

void listar_todos_pilotos(Piloto pilotos[], int qtd_pilotos) {
  FILE *arquivo;
  char registro[15], nome[50];
  int i;

  arquivo = fopen("pilotos.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo de pilotos.\n");
    return;
  }

  for (i = 0; i < qtd_pilotos; i++) {
    fscanf(arquivo, "%s %[^\n]s", registro, nome);
    listar_piloto(pilotos, i, qtd_pilotos);
    printf("\n");
  }

  fclose(arquivo);
}

int alterar_piloto(Piloto pilotos[], int indice, int qtd_pilotos) {
  int opcao, opcao_email, opcao_telefone, i;
  FILE *arquivo;
  char nome_arquivo[100];

  sprintf(nome_arquivo, "piloto_%s.txt", pilotos[indice].registro_piloto);

  arquivo = fopen(nome_arquivo, "w");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  printf("Alterando Piloto de registro: %s\n", pilotos[indice].registro_piloto);

  do {
    listar_piloto(pilotos, indice, qtd_pilotos);

    printf("**********Menu de Alteracao**********\n\n");
    printf("\t1. Alterar nome\n");
    printf("\t2. Alterar data de nascimento\n");
    printf("\t3. Alterar sexo\n");
    printf("\t4. Alterar curso\n");
    printf("\t5. Submenu emails\n");
    printf("\t6. Submenu telefones\n");
    printf("\nEscolha uma opcao de 1 a 6 ou digite 0 para voltar ao submenu de "
           "pilotos: ");
    scanf("%d", &opcao);
    fflush(stdin);

    switch (opcao) {
    case 0:
      printf("Voltando ao submenu de pilotos\n");
      break;

    case 1:
      printf("Nome: ");
      gets(pilotos[indice].nome);
      fprintf(arquivo, "Nome: %s\n", pilotos[indice].nome);
      break;

    case 2:
      printf("Data de Nascimento: ");
      printf("Dia: ");
      scanf("%d", &pilotos[indice].data_nascimento.dia);
      printf("Mes: ");
      scanf("%d", &pilotos[indice].data_nascimento.mes);
      printf("Ano: ");
      scanf("%d", &pilotos[indice].data_nascimento.ano);
      fflush(stdin);
      fprintf(arquivo, "Data de Nascimento: %02d/%02d/%04d\n",
              pilotos[indice].data_nascimento.dia,
              pilotos[indice].data_nascimento.mes,
              pilotos[indice].data_nascimento.ano);
      break;

    case 3:
      printf("Sexo: ");
      gets(pilotos[indice].sexo);
      fprintf(arquivo, "Sexo: %s\n", pilotos[indice].sexo);
      break;

    case 4:
      printf("Curso: ");
      gets(pilotos[indice].curso);
      fprintf(arquivo, "Curso: %s\n", pilotos[indice].curso);
      break;

    case 5:
      system("cls");
      printf("**********Submenu de alteracao de emails**********\n\n");
      printf("\t1. Adicionar email\n");
      printf("\t2. Alterar email\n");
      printf("\t3. Remover email\n");
      printf("\nEscolha uma opcao de 1 a 3 ou digite 0 para voltar ao ao menu "
             "de alteracao: ");
      scanf("%d", &opcao_email);

      switch (opcao_email) {
      case 0:
        printf("Voltando ao submenu de pilotos...");
        break;

      case 1:
        if (adicionar_email(pilotos, indice) == 1) {
          printf("Email adicionado com sucesso!\n");
          fprintf(arquivo, "Email: %s\n",
                  pilotos[indice].emails[pilotos[indice].qtd_emails - 1]);
        } else {
          printf("Limite de emails atingido\n");
        }

        break;

      case 2:
        system("cls");
        fflush(stdin);

        for (i = 0; i < pilotos[indice].qtd_emails; i++) {
          printf("%d: %s\n", i + 1, pilotos[indice].emails[i]);
        }

        printf("Insira o indice do email que deseja alterar: ");
        scanf("%d", &i);

        if (alterar_email(pilotos, indice, i - 1) == 1) {
          printf("Email alterado com sucesso!\n");
          fseek(arquivo, 0, SEEK_END);
          fprintf(arquivo, "Email: %s\n", pilotos[indice].emails[i - 1]);
        } else {
          printf("Indice de email invalido!\n");
        }

        break;

      case 3:
        system("cls");
        fflush(stdin);

        for (i = 0; i < pilotos[indice].qtd_emails; i++) {
          printf("%d: %s\n", i + 1, pilotos[indice].emails[i]);
        }

        printf("Insira o indice do email que deseja remover: ");
        scanf("%d", &i);

        if (remover_email(pilotos, indice, i - 1) == 1) {
          printf("Email removido com sucesso!\n");
          fseek(arquivo, 0, SEEK_END);
          fprintf(arquivo, "Email removido\n");
        } else {
          printf("Indice de email invalido!\n");
        }

        break;

      default:
        printf("Opcao invalida!\n");
      }
      break;

    case 6:
      system("cls");
      printf("**********Submenu de alteracao de telefones**********\n\n");
      printf("\t1. Adicionar telefone\n");
      printf("\t2. Alterar telefone\n");
      printf("\t3. Remover telefone\n");
      printf("\nEscolha uma opcao de 1 a 3 ou digite 0 para voltar ao menu de "
             "alteracao: ");
      scanf("%d", &opcao_telefone);

      switch (opcao_telefone) {
      case 0:
        printf("Voltando ao submenu de pilotos...");
        break;

      case 1:
        if (adicionar_telefone(pilotos, indice) == 1) {
          printf("Telefone adicionado com sucesso!\n");
          fprintf(arquivo, "Telefone: %s\n",
                  pilotos[indice].telefones[pilotos[indice].qtd_telefones - 1]);
        } else {
          printf("Limite de telefones atingido\n");
        }

        break;

      case 2:
        system("cls");
        fflush(stdin);

        for (i = 0; i < pilotos[indice].qtd_telefones; i++) {
          printf("%d: %s\n", i + 1, pilotos[indice].telefones[i]);
        }
        printf("Insira o indice do telefone que deseja alterar: ");
        scanf("%d", &i);

        if (alterar_telefone(pilotos, indice, i - 1) == 1) {
          printf("Telefone alterado com sucesso!\n");
          fseek(arquivo, 0, SEEK_END);
          fprintf(arquivo, "Telefone: %s\n", pilotos[indice].telefones[i - 1]);
        } else {
          printf("Indice de telefone invalido!\n");
        }

        break;

      case 3:
        system("cls");
        fflush(stdin);

        for (i = 0; i < pilotos[indice].qtd_telefones; i++) {
          printf("%d: %s\n", i + 1, pilotos[indice].telefones[i]);
        }

        printf("Insira o indice do telefone que deseja remover: ");
        scanf("%d", &i);

        if (remover_telefone(pilotos, indice, i - 1) == 1) {
          printf("Telefone removido com sucesso!\n");
          fseek(arquivo, 0, SEEK_END);
          fprintf(arquivo, "Telefone removido\n");
        } else {
          printf("Indice de telefone invalido!\n");
        }

        break;
      }
      break;

    default:
      printf("Opcao invalida!\n");
    }
  } while (opcao != 0 && opcao >= 1 && opcao <= 6);

  fclose(arquivo);

  return 1;
}

int adicionar_email(Piloto pilotos[], int indice) {
  int idx_email = pilotos[indice].qtd_emails;
  if (idx_email >= 10) {
    return -1;
  }

  FILE *arquivo = fopen("alteracoes.txt", "a");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  fflush(stdin);
  printf("Email: ");
  gets(pilotos[indice].emails[idx_email]);

  pilotos[indice].qtd_emails++;

  fseek(arquivo, 0, SEEK_END);
  fprintf(arquivo, "Email: %s\n", pilotos[indice].emails[idx_email]);

  fclose(arquivo);

  return 1;
}

int alterar_email(Piloto pilotos[], int indice, int idx_email) {
  int qtd_emails = pilotos[indice].qtd_emails;
  if (idx_email >= qtd_emails) {
    return -1;
  }

  FILE *arquivo = fopen("alteracoes.txt", "a");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  fflush(stdin);
  printf("Email: ");
  gets(pilotos[indice].emails[idx_email]);

  fseek(arquivo, 0, SEEK_END);
  fprintf(arquivo, "Email alterado: %s\n", pilotos[indice].emails[idx_email]);

  fclose(arquivo);

  return 1;
}

int remover_email(Piloto pilotos[], int indice, int idx_email) {
  int qtd_emails = pilotos[indice].qtd_emails, i;
  if (idx_email >= qtd_emails) {
    return -1;
  }

  FILE *arquivo = fopen("alteracoes.txt", "a");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  fseek(arquivo, 0, SEEK_END);
  fprintf(arquivo, "Email removido: %s\n", pilotos[indice].emails[idx_email]);

  fclose(arquivo);

  for (i = idx_email; i < qtd_emails - 1; i++) {
    strcpy(pilotos[indice].emails[i], pilotos[indice].emails[i + 1]);
  }

  pilotos[indice].qtd_emails--;
  return 1;
}

int adicionar_telefone(Piloto pilotos[], int indice) {
  int idx_telefone = pilotos[indice].qtd_telefones;
  if (idx_telefone >= 10) {
    return -1;
  }

  FILE *arquivo = fopen("alteracoes.txt", "a");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  fflush(stdin);
  printf("Telefone: ");
  gets(pilotos[indice].telefones[idx_telefone]);

  fseek(arquivo, 0, SEEK_END);
  fprintf(arquivo, "Telefone adicionado: %s\n",
          pilotos[indice].telefones[idx_telefone]);

  fclose(arquivo);

  pilotos[indice].qtd_telefones++;

  return 1;
}

int alterar_telefone(Piloto pilotos[], int indice, int idx_telefone) {
  int qtd_telefones = pilotos[indice].qtd_telefones;
  if (idx_telefone >= qtd_telefones) {
    return -1;
  }

  FILE *arquivo = fopen("alteracoes.txt", "a");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  fflush(stdin);
  printf("Telefone: ");
  gets(pilotos[indice].telefones[idx_telefone]);

  fseek(arquivo, 0, SEEK_END);
  fprintf(arquivo, "Telefone alterado: %s\n",
          pilotos[indice].telefones[idx_telefone]);

  fclose(arquivo);

  return 1;
}

int remover_telefone(Piloto pilotos[], int indice, int idx_telefone) {
  int qtd_telefones = pilotos[indice].qtd_telefones, i;
  if (idx_telefone >= qtd_telefones) {
    return -1;
  }

  FILE *arquivo = fopen("alteracoes.txt", "a");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  fseek(arquivo, 0, SEEK_END);
  fprintf(arquivo, "Telefone removido: %s\n",
          pilotos[indice].telefones[idx_telefone]);

  fclose(arquivo);

  for (i = idx_telefone; i < qtd_telefones - 1; i++) {
    strcpy(pilotos[indice].telefones[i], pilotos[indice].telefones[i + 1]);
  }

  pilotos[indice].qtd_telefones--;

  return 1;
}

void remover_piloto(Piloto pilotos[], int indice, int *qtd_pilotos) {
  int i;

  FILE *arquivo = fopen("alteracoes.txt", "a");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  fseek(arquivo, 0, SEEK_END);
  fprintf(arquivo, "Piloto removido: %s\n", pilotos[indice].nome);

  fclose(arquivo);

  for (i = indice; i < (*qtd_pilotos) - 1; i++) {
    pilotos[i] = pilotos[i + 1];
  }

  (*qtd_pilotos)--;
}

// VOOS
void submenu_voos(Voo voos[], int *idx_voos) {
  int num, opcao, encontrou;
  do {
    printf("\n**********Submenu de Voos**********\n\n");
    printf("\t1. Registrar Voo.\n");
    printf("\t2. Listar um Voo.\n");
    printf("\t3. Listar todos os Voos.\n");
    printf("\t4. Alterar Voo.\n");
    printf("\t5. Excluir Voo.\n");
    printf("\nEscolha uma opcao entre 1 e 5 ou digite 0 para voltar ao menu "
           "principal: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 0:
      printf("Voltando para o menu principal...\n");
      break;

    case 1:
      if (inserir_voo(voos, &(*idx_voos)) == 1) {
        printf("Voo registrado com sucesso!\n");
      } else {
        printf("Numero de voo ja existe!\n");
      }
      break;

    case 2:
      fflush(stdin);
      printf("Digite o numero de voo que deseja imprimir: ");
      scanf("%d", &num);
      encontrou = buscar_voo(voos, num, *idx_voos);

      if (encontrou >= 0) {
        listar_voo(voos, encontrou, *idx_voos);
      } else {
        printf("Voo nao encontrado!\n");
      }
      break;

    case 3:
      listar_todos_voos(voos, *idx_voos);
      break;

    case 4:
      fflush(stdin);
      printf("Digite o numero do voo que deseja alterar: ");
      scanf("%d", &num);
      encontrou = buscar_voo(voos, num, *idx_voos);

      if (encontrou >= 0) {
        alterar_voo(voos, encontrou, *idx_voos);
        printf("Voo alterado com sucesso!\n");
      } else {
        printf("Voo nao encontrado!\n");
      }

      break;

    case 5:
      fflush(stdin);
      printf("Digite o numero do voo que deseja excluir: ");
      scanf("%d", &num);
      encontrou = buscar_voo(voos, num, *idx_voos);

      if (encontrou >= 0) {
        remover_voo(voos, encontrou, &(*idx_voos));
        printf("Voo removido com sucesso!\n");
      } else {
        printf("Voo nao encontrado!\n");
      }

      break;

    default:
      printf("Opcao invalida!\n");
    }
  } while (opcao != 0 && opcao >= 1 && opcao <= 5);
}

int inserir_voo(Voo voos[], int *idx_voos) {
  int numero, i;
  char escala[50];

  printf("\nNumero do Voo: ");
  scanf("%d", &numero);
  fflush(stdin);

  if (buscar_voo(voos, numero, *idx_voos) >= 0 || *idx_voos >= MAX_VOOS) {
    return -1;
  }

  // Escrever o novo voo no arquivo
  FILE *arquivo = fopen("voos.bin", "ab");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }
  fwrite(&novoVoo, sizeof(Voo), 1, arquivo);
  fclose(arquivo);

  (*idx_voos)++;
  return 1;
}

int buscar_voo(Voo voos[], int num, int qtd_voos) {
  int i;
  for (i = 0; i < qtd_voos; i++) {
    if (voos[i].numero == num) {
      return i;
    }
  }
  return -1;
}

void listar_voo(Voo voos[], int indice, int qtd_voos) {
  //	int i;

  // Abrir arquivo para leitura
  FILE *arquivo = fopen("voos.bin", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  // Procurar o voo no arquivo
  Voo voo;
  int encontrado = 0;
  int numeroVoo;
  while (fread(&voo, sizeof(Voo), 1, arquivo)) {
    if (voo.numero == numeroVoo) {
      encontrado = 1;
      break;
    }
  }

  // Exibir o voo encontrado (ou mensagem de erro)
  if (encontrado) {
    printf("Voo encontrado:\n");
    printf("Número: %d\n", voo.numero);
    printf("Quantidade de escalas: %d\n", voo.qtd_escalas);
    printf("Cidade de origem: %s\n", voo.cidade_origem);
    printf("Cidade de destino: %s\n", voo.cidade_destino);
    printf("Aeronave: %s\n", voo.aeronave);
    printf("Tempo médio: %s\n", voo.tempo_medio);
    printf("Distância: %.2f\n", voo.distancia);
  }
}

void listar_todos_voos(Voo voos[], int qtd_voos) {

  // Abrir arquivo para leitura
  FILE *arquivo = fopen("voos.bin", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  // Ler e exibir todos os voos do arquivo
  Voo voo;
  while (fread(&voo, sizeof(Voo), 1, arquivo)) {
    printf("Número: %d\n", voo.numero);
    printf("Quantidade de escalas: %d\n", voo.qtd_escalas);
    printf("Cidade de origem: %s\n", voo.cidade_origem);
    printf("Cidade de destino: %s\n", voo.cidade_destino);
    printf("Aeronave: %s\n", voo.aeronave);
    printf("Tempo médio: %s\n", voo.tempo_medio);
    printf("Distância: %.2f\n", voo.distancia);
    printf("\n");
  }

  fclose(arquivo);
}

int alterar_voo(Voo voos[], int indice, int qtd_voos) {
  int opcao, opcao_escala, i;

  printf("Alterando Voo de numero: %d\n", voos[indice].numero);

  // Abrir arquivo para leitura e escrita
  FILE *arquivo = fopen("voos.bin", "rb+");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  // Procurar o voo no arquivo
  Voo voo;
  int encontrado = 0;
  int numeroVoo;
  while (fread(&voo, sizeof(Voo), 1, arquivo)) {
    if (voo.numero == numeroVoo) {
      encontrado = 1;
      break;
    }
  }

  // Alterar o voo encontrado (ou exibir menagem de erro)
  if (encontrado) {
    printf("Voo encontrado. Insira os novos dados:\n");
    printf("Quantidade de escalas: ");
    scanf("%d", &voo.qtd_escalas);
    printf("Cidade de origem: ");
    scanf(" %[^\n]", voo.cidade_origem);
    printf("Cidade de destino: ");
    scanf(" %[^\n]", voo.cidade_destino);
    printf("Aeronave: ");
    scanf(" %[^\n]", voo.aeronave);
    printf("Tempo médio: ");
    scanf(" %[^\n]", voo.tempo_medio);
    printf("Distância: ");
    scanf("%f", &voo.distancia);

    // Posicionar o ponteiro de arquivo na posição coreta
    fseek(arquivo, -sizeof(Voo), SEEK_CUR);

    // Escrever o voo alterado no arquivo
    fwrite(&voo, sizeof(Voo), 1, arquivo);

    printf("Voo alterado com sucesso.\n");
  } else {
    printf("Voo não encontrado.\n");
  }

  fclose(arquivo);
}

int adicionar_escala(Voo voos[], int indice) {
  int idx_escala = voos[indice].qtd_escalas;
  if (idx_escala >= MAX_ESCALAS) {
    return -1;
  }

  fflush(stdin);
  printf("Escala: ");
  gets(voos[indice].escalas[idx_escala]);

  voos[indice].qtd_escalas++;

  FILE *arquivo = fopen("voos.bin", "ab");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return -1;
  }

  fwrite(&voos[indice], sizeof(Voo), 1, arquivo);
  fclose(arquivo);

  return 1;
}

int alterar_escala(Voo voos[], int indice, int idx_escala) {
  int qtd_escalas = voos[indice].qtd_escalas;
  if (idx_escala >= qtd_escalas) {
    return -1;
  }

  fflush(stdin);
  printf("Escala: ");
  gets(voos[indice].escalas[idx_escala]);

  FILE *arquivo = fopen("voos.bin", "rb+");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return -1;
  }

  fseek(arquivo, indice * sizeof(Voo), SEEK_SET);
  fwrite(&voos[indice], sizeof(Voo), 1, arquivo);
  fclose(arquivo);

  return 1;
}

int remover_escala(Voo voos[], int indice, int idx_escala) {
  int qtd_escalas = voos[indice].qtd_escalas, i;
  if (idx_escala >= qtd_escalas) {
    return -1;
  }

  for (i = idx_escala; i < qtd_escalas - 1; i++) {
    strcpy(voos[indice].escalas[i], voos[indice].escalas[i + 1]);
  }

  voos[indice].qtd_escalas--;

  FILE *arquivo = fopen("voos.bin", "rb+");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return -1;
  }

  fseek(arquivo, indice * sizeof(Voo), SEEK_SET);
  fwrite(&voos[indice], sizeof(Voo), 1, arquivo);
  fclose(arquivo);

  return 1;
}

void remover_voo(Voo voos[], int indice, int *qtd_voos) {
  int numeroVoo;

  // Solicitar número do voo ao usuário
  printf("Número do voo: ");
  scanf("%d", &numeroVoo);

  // Abrir arquivo para leitura e escrita
  FILE *arquivo = fopen("voos.bin", "rb+");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  // Procurar o voo no arquivo
  Voo voo;
  int encontrado = 0;
  long posicao = 0;
  while (fread(&voo, sizeof(Voo), 1, arquivo)) {
    if (voo.numero == numeroVoo) {
      encontrado = 1;
      break;
    }
    posicao = ftell(arquivo);
  }

  // Excluir o voo encontrado (ou exibir mensagem de erro)
  if (encontrado) {
    // Voltar para a posição correta antes de excluir o voo
    fseek(arquivo, posicao, SEEK_SET);

    // Criar um registro vazio para substituir o voo a ser excluído
    Voo vazio = {0};

    // Escrever o registro vazio no lugar do voo a ser excluído
    fwrite(&vazio, sizeof(Voo), 1, arquivo);

    printf("Voo excluído com sucesso.\n");
  } else {
    printf("Voo não encontrado.\n");
  }

  fclose(arquivo);
}

// VIAGENS
void submenu_viagens(Viagem viagens[], Voo voos[], Piloto pilotos[],
                     int *idx_viagens, int idx_voos, int idx_pilotos) {
  int opcao, encontrou, numero_voo, i;
  char registro[15];

  do {
    printf("\n**********Submenu de Viagens**********\n\n");
    printf("\t1. Registrar Viagem.\n");
    printf("\t2. Listar viagem por indice.\n");
    printf("\t3. Listar todas viagens.\n");
    printf("\t4. Listar viagens por voo.\n");
    printf("\t5. Alterar viagem.\n");
    printf("\t6. Remover viagem.\n");
    printf("\nEscolha uma opcao entre 1 e 6 ou digite 0 para voltar ao menu "
           "principal: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 0:
      printf("Voltando para o menu principal...\n");
      break;

    case 1:
      i = inserir_viagem(viagens, voos, pilotos, &(*idx_viagens), idx_voos,
                         idx_pilotos) == 1;
      if (i == 1) {
        printf("Viagem adicionada com sucesso!\n");
      } else {
        if (i == 0) {
          printf("Dado(s) de viagem invalido(s)\n");
        } else {
          printf("Viagem ja existe\n");
        }
      }
      break;

    case 2:
      printf("Digite o indice da viagem que deseja imprimir: ");
      scanf("%d", &i);
      if (i <= *idx_viagens) {
        listar_viagem(viagens, i, *idx_viagens);
      } else {
        printf("Indice invalido\n");
      }
      break;

    case 3:
      listar_todas_viagens(viagens, *idx_viagens);
      break;

    case 4:
      printf("Insira o numero do Voo que deseja listar: ");
      scanf("%d", &numero_voo);
      if (listar_viagens_por_voo(viagens, numero_voo, *idx_viagens) == -1) {
        printf("Nenhuma viagem encontrada\n");
      }

      break;

    case 5:
      printf("Digite o indice da viagem que deseja alterar: ");
      scanf("%d", &i);

      if (i <= *idx_viagens) {
        alterar_viagem(viagens, i - 1, *idx_viagens);
        printf("Viagem alterada com sucesso!\n");
      } else {
        printf("Indice invalido\n");
      }
      break;

    case 6:
      printf("Digite o indice da viagem que deseja remover: ");
      scanf("%d", &i);

      if (i <= *idx_viagens) {
        remover_viagem(viagens, i - 1, &(*idx_viagens));
        printf("Viagem removida com sucesso!\n");
      } else {
        printf("Indice invalido\n");
      }
      break;

    default:
      printf("Opcao invalida!\n");
    }
  } while (opcao != 0 && opcao >= 1 && opcao <= 6);
}

int inserir_viagem(Viagem viagens[], Voo voos[], Piloto pilotos[],
                   int *idx_viagens, int idx_voos, int idx_pilotos) {

  FILE *arquivo = fopen("viagens.bin", "ab");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  int num, dia, mes, ano, i;
  char registro[15], hora_saida[10], ocorrencia[200], pk[200], str[10];
  strcpy(pk, "");

  // RECEBENDO DADOS QUE FORMAM PK
  printf("\nNumero Voo: ");
  scanf("%d", &num);
  fflush(stdin);

  if (buscar_voo(voos, num, idx_voos) == -1) {
    printf("Voo nao encontrado!\n");
    return 0;
  }

  sprintf(str, "%d", num);
  strcat(pk, str);

  printf("Registro do piloto: ");
  gets(registro);

  if (buscar_piloto(pilotos, registro, idx_pilotos) == -1) {
    printf("Piloto nao encontrado!\n");
    return 0;
  }

  strcat(pk, registro);

  printf("Data Saida: \n");
  printf("Dia (1-31): ");
  scanf("%d", &dia);
  sprintf(str, "%d", dia);
  strcat(pk, str);
  printf("Mes (1-12): ");
  scanf("%d", &mes);
  sprintf(str, "%d", mes);
  strcat(pk, str);
  printf("Ano (1900 - 2100): ");
  scanf("%d", &ano);
  sprintf(str, "%d", ano);
  strcat(pk, str);
  fflush(stdin);

  printf("Hora saida (HH:MM): ");
  gets(hora_saida);
  strcat(pk, hora_saida);

  if (buscar_viagem(viagens, pk, *idx_viagens) >= 0) {
    return -1;
  }

  strcpy(viagens[*idx_viagens].pk, pk);

  // SALVANDO DADOS
  viagens[*idx_viagens].numero_voo = num;
  strcpy(viagens[*idx_viagens].registro_piloto, registro);
  viagens[*idx_viagens].data_saida.dia = dia;
  viagens[*idx_viagens].data_saida.mes = mes;
  viagens[*idx_viagens].data_saida.ano = ano;
  strcpy(viagens[*idx_viagens].hora_saida, hora_saida);

  // LEITURA E GRAVACAO DOS DADOS RESTANTES
  printf("Data chegada: ");
  printf("Dia (1-31): ");
  scanf("%d", &viagens[*idx_viagens].data_chegada.dia);
  printf("Mes (1-12): ");
  scanf("%d", &viagens[*idx_viagens].data_chegada.mes);
  printf("Ano (1900 - 2100): ");
  scanf("%d", &viagens[*idx_viagens].data_chegada.ano);
  fflush(stdin);
  printf("Hora chegada (HH:MM): ");
  gets(viagens[*idx_viagens].hora_chegada);

  printf("\nInsercao de ocorrencias: Digite 0 para encerrar insercao\n\n");
  for (i = 0; i < 10; i++) {
    printf("Ocorrencia %d: ", i + 1);
    gets(ocorrencia);

    if (stricmp(ocorrencia, "0") != 0) {
      strcpy(viagens[*idx_viagens].ocorrencias[i], ocorrencia);
      viagens[*idx_viagens].qtd_ocorrencias++;
    } else {
      i = 50;
    }
  }
  // Escrever a estrutura Viagem no arquivo
  fwrite(&viagens[*idx_viagens], sizeof(Viagem), 1, arquivo);

  // Fechar o arquivo
  fclose(arquivo);
  (*idx_viagens)++;
  return 1;
}

int buscar_viagem(Viagem viagens[], const char *pk, int qtd_viagens) {
  FILE *arquivo = fopen("viagens.bin", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return -1;
  }

  Viagem viagem;

  // Procurando a viagem pelo PK no arquivo
  while (fread(&viagem, sizeof(Viagem), 1, arquivo) == 1) {
    if (strcmp(viagem.pk, pk) == 0) {
      fclose(arquivo);
      return 1; // Viagem encontrada
    }
  }

  fclose(arquivo);
  return 0; // Viagem não encontrada
}

void listar_viagem(const char *pk) {
  FILE *arquivo = fopen("viagens.bin", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  Viagem viagem;

  // Procurando a viagem pelo PK no arquivo
  while (fread(&viagem, sizeof(Viagem), 1, arquivo) == 1) {
    if (strcmp(viagem.pk, pk) == 0) {
      printf("\n****************************************\n");
      printf("\nImprimindo Viagem\n");
      printf("Numero Voo: %d\n", viagem.numero_voo);
      printf("Registro Piloto: %s\n", viagem.registro_piloto);
      printf("Data saida: %02d/%02d/%04d\n", viagem.data_saida.dia,
             viagem.data_saida.mes, viagem.data_saida.ano);
      printf("Hora saida: %s\n", viagem.hora_saida);
      printf("Data chegada: %02d/%02d/%04d\n", viagem.data_chegada.dia,
             viagem.data_chegada.mes, viagem.data_chegada.ano);
      printf("Hora chegada: %s\n", viagem.hora_chegada);

      int i;
      for (i = 0; i < viagem.qtd_ocorrencias; i++) {
        printf("Ocorrencia %d: %s\n", i + 1, viagem.ocorrencias[i]);
      }

      printf("\n****************************************\n");

      fclose(arquivo);
      return;
    }
  }

  printf("Viagem nao encontrada.\n");
  fclose(arquivo);
}

void listar_todas_viagens() {
  FILE *arquivo = fopen("viagens.bin", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  Viagem viagem;

  // Imprimindo todas as viagens do arquivo
  printf("Listagem de todas as viagens:\n");
  while (fread(&viagem, sizeof(Viagem), 1, arquivo) == 1) {
    printf("********** Viagem **********\n");
    printf("Numero Voo: %d\n", viagem.numero_voo);
    printf("Registro Piloto: %s\n", viagem.registro_piloto);
    printf("Data saida: %02d/%02d/%04d\n", viagem.data_saida.dia,
           viagem.data_saida.mes, viagem.data_saida.ano);
    printf("Hora saida: %s\n", viagem.hora_saida);
    printf("Data chegada: %02d/%02d/%04d\n", viagem.data_chegada.dia,
           viagem.data_chegada.mes, viagem.data_chegada.ano);
    printf("Hora chegada: %s\n", viagem.hora_chegada);

    int i;
    for (i = 0; i < viagem.qtd_ocorrencias; i++) {
      printf("Ocorrencia %d: %s\n", i + 1, viagem.ocorrencias[i]);
    }

    printf("\n");
  }

  fclose(arquivo);
}

void listar_viagens_por_voo(int numero_voo) {
  FILE *arquivo = fopen("viagens.bin", "rb");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  Viagem viagem;

  // Listar todas as viagens com o número de voo especificado
  printf("Listagem de viagens para o voo %d:\n", numero_voo);
  while (fread(&viagem, sizeof(Viagem), 1, arquivo) == 1) {
    if (viagem.numero_voo == numero_voo) {
      printf("********** Viagem **********\n");
      printf("Numero Voo: %d\n", viagem.numero_voo);
      printf("Registro Piloto: %s\n", viagem.registro_piloto);
      printf("Data saida: %02d/%02d/%04d\n", viagem.data_saida.dia,
             viagem.data_saida.mes, viagem.data_saida.ano);
      printf("Hora saida: %s\n", viagem.hora_saida);
      printf("Data chegada: %02d/%02d/%04d\n", viagem.data_chegada.dia,
             viagem.data_chegada.mes, viagem.data_chegada.ano);
      printf("Hora chegada: %s\n", viagem.hora_chegada);

      int i;
      for (i = 0; i < viagem.qtd_ocorrencias; i++) {
        printf("Ocorrencia %d: %s\n", i + 1, viagem.ocorrencias[i]);
      }

      printf("\n");
    }
  }

  fclose(arquivo);
}

void alterar_viagem(int indice) {
  FILE *arquivo = fopen("viagens.bin", "rb+");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  Viagem viagem;

  // Localizar a viagem no arquivo
  if (fseek(arquivo, indice * sizeof(Viagem), SEEK_SET) != 0) {
    printf("Erro ao posicionar no registro da viagem.\n");
    fclose(arquivo);
    return;
  }

  // Ler a viagem do arquivo
  if (fread(&viagem, sizeof(Viagem), 1, arquivo) != 1) {
    printf("Erro ao ler a viagem do arquivo.\n");
    fclose(arquivo);
    return;
  }

  int opcao, opcao_ocorrencia, i;

  printf("Alterando viagem do indice: %d\n", indice);

  do {
    listar_viagem(viagem, 0, 1);

    printf("**********Menu de Alteracao**********\n\n");
    printf("\t1. Data de chegada\n");
    printf("\t2. Hora de chegada\n");
    printf("\t3. Submenu ocorrencias\n");
    printf("\nEscolha uma opcao de 1 a 3 ou digite 0 para voltar ao submenu "
           "de viagens: ");
    scanf("%d", &opcao);
    fflush(stdin);

    switch (opcao) {
    case 0:
      printf("Voltando ao submenu de viagens\n");
      break;

    case 1:
      printf("Data chegada: \n");
      printf("Dia (1-31): ");
      scanf("%d", &viagem.data_chegada.dia);
      printf("Mes (1-12): ");
      scanf("%d", &viagem.data_chegada.mes);
      printf("Ano (1900 - 2100): ");
      scanf("%d", &viagem.data_chegada.ano);
      fflush(stdin);

      // Escrever a viagem alterada no arquivo
      if (fseek(arquivo, indice * sizeof(Viagem), SEEK_SET) != 0) {
        printf("Erro ao posicionar no registro da viagem.\n");
        fclose(arquivo);
        return;
      }
      if (fwrite(&viagem, sizeof(Viagem), 1, arquivo) != 1) {
        printf("Erro ao escrever a viagem no arquivo.\n");
        fclose(arquivo);
        return;
      }

      printf("Viagem alterada com sucesso!\n");
      break;

    case 2:
      printf("Hora chegada (HH:MM): ");
      scanf("%s", viagem.hora_chegada);
      fflush(stdin);

      // Escrever a viagem alterada no arquivo
      if (fseek(arquivo, indice * sizeof(Viagem), SEEK_SET) != 0) {
        printf("Erro ao posicionar no registro da viagem.\n");
        fclose(arquivo);
        return;
      }
      if (fwrite(&viagem, sizeof(Viagem), 1, arquivo) != 1) {
        printf("Erro ao escrever a viagem no arquivo.\n");
        fclose(arquivo);
        return;
      }

      printf("Viagem alterada com sucesso!\n");
      break;
    case 3:
      system("cls");
      fflush(stdin);

      printf("**********Submenu de alteracao de ocorrencias**********\n\n");
      printf("\t1. Adicionar ocorrencia\n");
      printf("\t2. Alterar ocorrencia\n");
      printf("\t3. Remover ocorrencia\n");
      printf("\nEscolha uma opcao de 1 a 3 ou digite 0 para retornar ao menu "
             "de alteracao: ");
      scanf("%d", &opcao_ocorrencia);

      switch (opcao_ocorrencia) {
      case 0:
        printf("Voltando ao menu de alteracao...");
        break;

      case 1:
        if (adicionar_ocorrencia(viagem) == 1) {
          printf("Ocorrencia adicionada com sucesso!\n");
        } else {
          printf("Limite de ocorrencias atingido\n");
        }

        // Escrever a viagem alterada no arquivo
        if (fseek(arquivo, indice * sizeof(Viagem), SEEK_SET) != 0) {
          printf("Erro ao posicionar no registro da viagem.\n");
          fclose(arquivo);
          return;
        }
        if (fwrite(&viagem, sizeof(Viagem), 1, arquivo) != 1) {
          printf("Erro ao escrever a viagem no arquivo.\n");
          fclose(arquivo);
          return;
        }

        break;

      case 2:
        system("cls");
        fflush(stdin);

        for (i = 0; i < viagem.qtd_ocorrencias; i++) {
          printf("%d: %s\n", i + 1, viagem.ocorrencias[i]);
        }

        printf("Insira o indice da ocorrencia que deseja alterar: ");
        scanf("%d", &i);

        if (alterar_ocorrencia(viagem, i - 1) == 1) {
          printf("Ocorrencia alterada com sucesso!\n");
        } else {
          printf("Indice de ocorrencia invalido\n");
        }

        // Escrever a viagem alterada no arquivo
        if (fseek(arquivo, indice * sizeof(Viagem), SEEK_SET) != 0) {
          printf("Erro ao posicionar no registro da viagem.\n");
          fclose(arquivo);
          return;
        }
        if (fwrite(&viagem, sizeof(Viagem), 1, arquivo) != 1) {
          printf("Erro ao escrever a viagem no arquivo.\n");
          fclose(arquivo);
          return;
        }

        break;

      case 3:
        system("cls");
        fflush(stdin);

        for (i = 0; i < viagem.qtd_ocorrencias; i++) {
          printf("%d: %s\n", i + 1, viagem.ocorrencias[i]);
        }

        printf("Insira o indice da ocorrencia que deseja remover: ");
        scanf("%d", &i);

        if (remover_ocorrencia(viagem, i - 1) == 1) {
          printf("Ocorrencia removida com sucesso!\n");
        } else {
          printf("Indice de ocorrencia invalido\n");
        }

        // Escrever a viagem alterada no arquivo
        if (fseek(arquivo, indice * sizeof(Viagem), SEEK_SET) != 0) {
          printf("Erro ao posicionar no registro da viagem.\n");
          fclose(arquivo);
          return;
        }
        if (fwrite(&viagem, sizeof(Viagem), 1, arquivo) != 1) {
          printf("Erro ao escrever a viagem no arquivo.\n");
          fclose(arquivo);
          return;
        }

        break;
      }
      break;

    default:
      printf("Opcao invalida!\n");
    }
  } while (opcao != 0 && opcao >= 1 && opcao <= 3);

  fclose(arquivo);
}

int adicionar_ocorrencia(Viagem viagens[], int indice) {
  int idx_ocorrencia = viagens[indice].qtd_ocorrencias;
  if (idx_ocorrencia >= 10) {
    return -1;
  }

  FILE *arquivo = fopen("viagens.bin", "rb+");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  // Posicionar no registro da viagem no arquivo
  if (fseek(arquivo, indice * sizeof(Viagem), SEEK_SET) != 0) {
    printf("Erro ao posicionar no registro da viagem.\n");
    fclose(arquivo);
    return 0;
  }

  // Ler a viagem do arquivo
  Viagem viagem;
  if (fread(&viagem, sizeof(Viagem), 1, arquivo) != 1) {
    printf("Erro ao ler a viagem do arquivo.\n");
    fclose(arquivo);
    return 0;
  }

  fflush(stdin);
  printf("Ocorrencia: ");
  gets(viagem.ocorrencias[idx_ocorrencia]);

  viagem.qtd_ocorrencias++;

  // Escrever a viagem atualizada no arquivo
  if (fseek(arquivo, indice * sizeof(Viagem), SEEK_SET) != 0) {
    printf("Erro ao posicionar no registro da viagem.\n");
    fclose(arquivo);
    return 0;
  }
  if (fwrite(&viagem, sizeof(Viagem), 1, arquivo) != 1) {
    printf("Erro ao escrever a viagem no arquivo.\n");
    fclose(arquivo);
    return 0;
  }

  fclose(arquivo);

  return 1;
}

int alterar_ocorrencia(Viagem viagens[], int indice, int idx_ocorrencia) {
  int qtd_ocorrencias = viagens[indice].qtd_ocorrencias;

  if (idx_ocorrencia >= qtd_ocorrencias) {
    return -1;
  }

  FILE *arquivo = fopen("viagens.bin", "rb+");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  // Posicionar no registro da viagem no arquivo
  if (fseek(arquivo, indice * sizeof(Viagem), SEEK_SET) != 0) {
    printf("Erro ao posicionar no registro da viagem.\n");
    fclose(arquivo);
    return 0;
  }

  // Ler a viagem do arquivo
  Viagem viagem;
  if (fread(&viagem, sizeof(Viagem), 1, arquivo) != 1) {
    printf("Erro ao ler a viagem do arquivo.\n");
    fclose(arquivo);
    return 0;
  }

  fflush(stdin);
  printf("Ocorrencia: ");
  gets(viagem.ocorrencias[idx_ocorrencia]);

  // Escrever a viagem atualizada no arquivo
  if (fseek(arquivo, indice * sizeof(Viagem), SEEK_SET) != 0) {
    printf("Erro ao posicionar no registro da viagem.\n");
    fclose(arquivo);
    return 0;
  }
  if (fwrite(&viagem, sizeof(Viagem), 1, arquivo) != 1) {
    printf("Erro ao escrever a viagem no arquivo.\n");
    fclose(arquivo);
    return 0;
  }

  fclose(arquivo);

  return 1;
}

int remover_ocorrencia(Viagem viagens[], int indice, int idx_ocorrencia) {
  int qtd_ocorrencias = viagens[indice].qtd_ocorrencias, i;

  if (idx_ocorrencia >= qtd_ocorrencias) {
    return -1;
  }

  FILE *arquivo = fopen("viagens.bin", "rb+");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 0;
  }

  // Posicionar no registro da viagem no arquivo
  if (fseek(arquivo, indice * sizeof(Viagem), SEEK_SET) != 0) {
    printf("Erro ao posicionar no registro da viagem.\n");
    fclose(arquivo);
    return 0;
  }

  // Ler a viagem do arquivo
  Viagem viagem;
  if (fread(&viagem, sizeof(Viagem), 1, arquivo) != 1) {
    printf("Erro ao ler a viagem do arquivo.\n");
    fclose(arquivo);
    return 0;
  }

  // Remover a ocorrência da estrutura
  for (i = idx_ocorrencia; i < qtd_ocorrencias - 1; i++) {
    strcpy(viagem.ocorrencias[i], viagem.ocorrencias[i + 1]);
  }

  viagem.qtd_ocorrencias--;

  // Escrever a viagem atualizada no arquivo
  if (fseek(arquivo, indice * sizeof(Viagem), SEEK_SET) != 0) {
    printf("Erro ao posicionar no registro da viagem.\n");
    fclose(arquivo);
    return 0;
  }
  if (fwrite(&viagem, sizeof(Viagem), 1, arquivo) != 1) {
    printf("Erro ao escrever a viagem no arquivo.\n");
    fclose(arquivo);
    return 0;
  }

  fclose(arquivo);

  return 1;
}

void remover_viagem(Viagem viagens[], int indice, int *qtd_viagens) {
  FILE *arquivo = fopen("viagens.bin", "rb+");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  // Verificar se o índice está dentro dos limites
  if (indice < 0 || indice >= *qtd_viagens) {
    printf("Índice inválido.\n");
    fclose(arquivo);
    return;
  }

  // Deslocar as viagens subsequentes para preencher o espaço vazio
  for (int i = indice; i < (*qtd_viagens) - 1; i++) {
    viagens[i] = viagens[i + 1];
  }

  // Atualizar o número de viagens
  (*qtd_viagens)--;

  // Escrever as viagens atualizadas no arquivo
  if (fseek(arquivo, 0, SEEK_SET) != 0) {
    printf("Erro ao posicionar no início do arquivo.\n");
    fclose(arquivo);
    return;
  }

  // RELATORIOS
  void submenu_relatorios(Viagem viagens[], Voo voos[], Piloto pilotos[],
                          int idx_viagens, int idx_voos, int idx_pilotos) {
    int opcao, idade, idade_buscada, encontrou;
    char cidade[50];
    Voo voo;
    Data data_inicial, data_final;

    do {
      printf("\n**********Submenu de Relatorios**********\n\n");
      printf("\t1. Listar piloto acima de certa idade.\n");
      printf("\t2. Listar voo por cidade na escala.\n");
      printf("\t3. Listar viagens por intervalo de data.\n");
      printf("\nEscolha uma opcao entre 1 e 3 ou digite 0 para voltar ao "
             "menu principal: ");
      scanf("%d", &opcao);

      switch (opcao) {
      case 0:
        printf("Voltando para o menu principal...\n");
        break;

      case 1:
        printf("Idade: ");
        scanf("%d", &idade_buscada);
        for (int i = 0; i < idx_pilotos; i++) {
          idade = calcular_idade(pilotos, i, idx_pilotos);

          if (idade == -1 || idade_buscada <= 0) {
            printf("Erro ao calcular idade");
          }
          if (idade > idade_buscada) {
            listar_piloto(pilotos, i, idx_pilotos);
          }
        }
        break;

      case 2:
        fflush(stdin);
        printf("Cidade: ");
        gets(cidade);

        for (int i = 0; i < idx_voos; i++) {
          voo = voos[i];
          for (int j = 0; j < voo.qtd_escalas; j++) {
            if (stricmp(cidade, voo.escalas[j]) == 0) {
              listar_voo(voos, i, idx_voos);
            }
          }
        }
        break;

      case 3:
        printf("Data inicial do intervalo\n");
        printf("Dia: ");
        scanf("%d", &data_inicial.dia);
        printf("Mes: ");
        scanf("%d", &data_inicial.mes);
        printf("Ano: ");
        scanf("%d", &data_inicial.ano);
        printf("Data final do intervalo\n");
        printf("Dia: ");
        scanf("%d", &data_final.dia);
        printf("Mes: ");
        scanf("%d", &data_final.mes);
        printf("Ano: ");
        scanf("%d", &data_final.ano);

        for (int i = 0; i < idx_viagens; i++) {
          if (verificar_intervalo_datas(viagens[i], data_inicial, data_final) ==
              1) {
            encontrou =
                buscar_piloto(pilotos, viagens[i].registro_piloto, idx_pilotos);
            printf("\n****************************************\n");
            printf("Viagem comandada pelo piloto: %s\n",
                   pilotos[encontrou].nome);
            listar_viagem(viagens, i, idx_viagens);
          }
        }
        break;

      default:
        printf("Opcao invalida!\n");
      }
    } while (opcao != 0 && opcao >= 1 && opcao <= 3);
  }

  // Relatóra A
  int calcular_idade(Piloto pilotos[], int indice, int qtd_pilotos) {
    Data data_atual;
    int dia, mes, ano, idade;
    FILE *arquivo;

    arquivo = fopen("data_atual.txt", "r");
    if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo de data atual.\n");
      return -1;
    }

    fscanf(arquivo, "%d %d %d", &dia, &mes, &ano);
    fclose(arquivo);

    if (ano < pilotos[indice].data_nascimento.ano) {
      return -1;
    }

    idade = ano - pilotos[indice].data_nascimento.ano;

    if (pilotos[indice].data_nascimento.mes == mes) {
      if (pilotos[indice].data_nascimento.dia > dia) {
        idade--;
      }
    } else if (pilotos[indice].data_nascimento.mes > mes) {
      idade--;
    }

    return idades;
  }

  // Relatóra C
  int verificar_intervalo_datas(Viagem viagem, Data data_x, Data data_y) {
    Data data_viagem;
    FILE *arquivo;
    int retorno;

    arquivo = fopen("data_viagem.txt", "r");
    if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo de data da viagem.\n");
      return 0;
    }

    fscanf(arquivo, "%d %d %d", &data_viagem.dia, &data_viagem.mes,
           &data_viagem.ano);
    fclose(arquivo);

    retorno = 1;
    if (data_x.ano > data_viagem.ano || data_y.ano < data_viagem.ano) {
      retorno = 0;
    } else if (data_x.ano == data_viagem.ano) {
      if (data_x.mes > data_viagem.mes) {
        retorno = 0;
      } else if (data_x.mes == data_viagem.mes &&
                 data_x.dia > data_viagem.dia) {
        retorno = 0;
      }
    } else if (data_y.ano == data_viagem.ano) {
      if (data_y.mes < data_viagem.mes) {
        retorno = 0;
      } else if (data_y.mes == data_viagem.mes &&
                 data_y.dia < data_viagem.dia) {
        retorno = 0;
      }
    }

    return retorno;
  }
}
}
}
