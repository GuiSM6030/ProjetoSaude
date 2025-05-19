#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"
#include "heap.h"
#include "arvore.h"


  Fila fila_atendimento;
  Lista lista_pacientes;
  Heap heap_prioritario;
  NoArvore* arvore_ano = NULL;
  NoArvore* arvore_mes = NULL;
  NoArvore* arvore_dia = NULL;

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
    case 4:
      atualizar_paciente(lista);
      break;
    case 5:
      remover_paciente(lista);
      break;
    case 0:
      return;
    default:
      printf("Opção inválida!\n");
    }
  } while (opcao != 0);
}

void submenu_atendimento(Lista *lista, Fila *fila)
{
  int opcao;
  do
  {
    printf("\n--- ATENDIMENTO ---\n");
    printf("1. Enfileirar paciente\n");
    printf("2. Desenfileirar paciente\n");
    printf("3. Mostrar fila\n");
    printf("0. Voltar\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    while (getchar() != '\n')
      ;

    switch (opcao)
    {
    case 1:
    {
      char rg[20];
      printf("\nDigite o RG do paciente: ");
      scanf("%s", rg);
      Registro *paciente = consultar_paciente(lista, rg);
      if (paciente != NULL)
      {
        enfileirar(fila, paciente);
        printf("\n%s entrou na fila!\n", paciente->nome);
      }
      else
      {
        printf("\nPaciente não encontrado!\n");
      }
      break;
    }
    case 2:
    {
      Registro *paciente = desenfileirar(fila);
      if (paciente != NULL)
      {
        printf("\n%s atendido(a)!\n", paciente->nome);
      }
      else
      {
        printf("\nFila vazia!\n");
      }
      break;
    }
    case 3:
      mostrar_fila(fila);
      break;
    case 0:
      return;
    default:
      printf("\nOpção inválida!\n");
    }
  } while (opcao != 0);
}

void submenu_atendimento_prioritario(Lista* lista, Heap* heap_prioritario) {  // Renomeei o parâmetro
    int opcao;
    do {
        printf("\n--- ATENDIMENTO PRIORITÁRIO ---\n");
        printf("1. Enfileirar paciente\n");
        printf("2. Desenfileirar paciente\n");
        printf("3. Mostrar fila\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        while (getchar() != '\n');

        switch (opcao) {
            case 1: {
                char rg[20];
                printf("\nDigite o RG do paciente: ");
                scanf("%s", rg);
                Registro* paciente = consultar_paciente(lista, rg);
                if (paciente != NULL) {
                    enfileirar_heap(heap_prioritario, paciente);  // Usando o parâmetro renomeado
                    printf("\n%s entrou na fila prioritária!\n", paciente->nome);
                } else {
                    printf("\nPaciente não encontrado!\n");
                }
                break;
            }
            case 2: {
                Registro* paciente = desenfileirar_heap(heap_prioritario);  // Aqui estava o erro
                if (paciente != NULL) {
                    printf("\n%s atendido(a)!\n", paciente->nome);
                } else {
                    printf("\nFila prioritária vazia!\n");
                }
                break;
            }
            case 3:
    mostrar_heap(heap_prioritario);
    break;
            case 0:
                return;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);
}

void submenu_pesquisa() {
    int opcao;
    do {
        printf("\n--- PESQUISA ---\n");
        printf("1. Por ano de registro\n");
        printf("2. Por mês\n");
        printf("3. Por dia\n");
        printf("4. Por idade\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                if (arvore_ano == NULL) {
                    printf("\nConstruindo árvore...\n");
                    // Percorre a lista e insere na árvore
                    Elista* atual = lista_pacientes.inicio;
                    while (atual != NULL) {
                        inserir_por_ano(&arvore_ano, atual->dados);
                        atual = atual->proximo;
                    }
                }
                printf("\n--- PACIENTES POR ANO ---\n");
                mostrar_em_ordem_ano(arvore_ano);
                break;
                case 2:
    if (arvore_mes == NULL) {
        printf("\nConstruindo árvore por mês...\n");
        Elista* atual = lista_pacientes.inicio;
        while (atual != NULL) {
            inserir_por_mes(&arvore_mes, atual->dados);
            atual = atual->proximo;
        }
    }
    printf("\n--- PACIENTES POR MÊS ---\n");
    mostrar_em_ordem_mes(arvore_mes);
    break;
case 3: 
    // a gente usa pra liberar a árvore antiga antes de criar outa
    liberar_arvore(arvore_dia);
    arvore_dia = NULL; 

    printf("\nConstruindo árvore por dia...\n");
    Elista* atual = lista_pacientes.inicio;
    while (atual != NULL) {
        inserir_por_dia(&arvore_dia, atual->dados);
        atual = atual->proximo;
    }

    printf("\n--- PACIENTES ORDENADOS POR DIA ---\n");
    if (arvore_dia == NULL) {
        printf("Nenhum paciente cadastrado.\n");
    } else {
        mostrar_em_ordem_dia(arvore_dia);
    }
    break;
            case 0:
                return;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);
}

int main()
{


    inicializar_lista(&lista_pacientes);
  inicializar_heap(&heap_prioritario, 20);


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
      submenu_atendimento(&lista_pacientes, &fila_atendimento);
      break;
case 3:
    submenu_atendimento_prioritario(&lista_pacientes, &heap_prioritario);
    break;
case 4:
    submenu_pesquisa();
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