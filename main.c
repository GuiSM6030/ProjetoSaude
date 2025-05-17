// main.c
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void mostrar_menu()
{
  printf("\n-- ATENDIMENTO DE SAÚDE --\n");
  printf("\n---- Hospital da FEI ----\n");
  printf("1. Cadastrar paciente\n");
  printf("2. Atendimento\n");
  printf("3. Atendimento prioritário\n");
  printf("4. Pesquisa\n");
  printf("5. Desfazer\n");
  printf("6. Carregar / Salvar\n");
  printf("7. Sobre\n");
  printf("0. Sair\n");
  printf("Escolha uma opcao: ");
}

void submenu_cadastrar(Lista *lista)
{
  int opcao;
  do
  {
    printf("\n--- SUBMENU CADASTRO ---\n");
    printf("1. Cadastrar novo paciente\n");
    printf("2. Consultar paciente por RG\n");
    printf("3. Mostrar lista completa\n");
    printf("4. Atualizar paciente\n");
    printf("5. Remover paciente\n");
    printf("0. Voltar ao menu principal\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    while (getchar() != '\n')
      ; // Limpar buffer

    switch (opcao)
    {
    case 1:
      cadastrar_paciente(lista);
      break;
    case 2:
    {
      char rg_busca[20];
      printf("\nDigite o RG do paciente: ");
      scanf("%s", rg_busca);
      Registro *paciente = consultar_paciente(lista, rg_busca);
      if (paciente != NULL)
      {
        printf("\n--- PACIENTE ENCONTRADO ---\n");
        printf("Nome: %s\n", paciente->nome);
        printf("Idade: %d\n", paciente->idade);
        printf("RG: %s\n", paciente->rg);
        printf("Data de entrada: %02d/%02d/%04d\n",
               paciente->entrada->dia,
               paciente->entrada->mes,
               paciente->entrada->ano);
      }
      else
      {
        printf("\nPaciente não encontrado.\n");
      }
      break;
    }
    case 3:
      mostrar_lista_completa(lista); // Já está lá!
      break;
    case 0:
      return;
    default:
      printf("Opção inválida!\n");
    }
  } while (opcao != 0);
}

int main()
{
  Lista lista_pacientes;
  inicializar_lista(&lista_pacientes);

  int opcao;
  do
  {
    mostrar_menu();
    scanf("%d", &opcao);

    while (getchar() != '\n')
      ; // Limpar buffer

    switch (opcao)
    {
    case 1:
      submenu_cadastrar(&lista_pacientes);
      break;
    case 2:
      printf("Atendimento (a ser implementado)\n");
      break;
    case 3:
      printf("Atendimento prioritário (a ser implementado)\n");
      break;
    case 4:
      printf("Pesquisa (a ser implementado)\n");
      break;
    case 5:
      printf("Desfazer (a ser implementado)\n");
      break;
    case 6:
      printf("Carregar / Salvar (a ser implementado)\n");
      break;
    case 7:
      printf("Sobre (a ser implementado)\n");
      break;
    case 0:
      printf("Saindo do sistema...\n");
      break;
    default:
      printf("Opção não existe, escolha uma de 0 a 7\n");
    }
  } while (opcao != 0);

  liberar_lista(&lista_pacientes);
  return 0;
}