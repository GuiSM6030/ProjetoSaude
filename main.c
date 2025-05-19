//bibliotecas ultilizadas
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "fila.h"
#include "heap.h"
#include "pilha.h"
#include "arvore.h"

// variaveis que vao ser usadas em todo o programa
Fila fila_atendimento;
Lista lista_pacientes;
Heap heap_prioritario;
NoArvore* arvore_ano = NULL;
NoArvore* arvore_mes = NULL;
NoArvore* arvore_dia = NULL;
NoArvore* arvore_idade = NULL;
PilhaOperacoes log_operacoes;

//menu principal
void mostrar_menu() {
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

//submenu cadastrar (ultiliza lista dinamica encadeada)
void submenu_cadastrar(Lista *lista) {
    int opcao;
    do {
        printf("\n--- SUBMENU CADASTRO ---\n");
        printf("1. Cadastrar novo paciente\n");
        printf("2. Consultar paciente por RG\n");
        printf("3. Mostrar lista completa\n");
        printf("4. Atualizar paciente\n");
        printf("5. Remover paciente\n");
        printf("0. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                cadastrar_paciente(lista);
                break;
            case 2: {
                char rg_busca[20];
                printf("\nDigite o RG do paciente: ");
                scanf("%s", rg_busca);
                Registro *paciente = consultar_paciente(lista, rg_busca);
                if (paciente != NULL) {
                    printf("\n--- PACIENTE ENCONTRADO ---\n");
                    printf("Nome: %s\n", paciente->nome);
                    printf("Idade: %d\n", paciente->idade);
                    printf("RG: %s\n", paciente->rg);
                    printf("Data de entrada: %02d/%02d/%04d\n",
                           paciente->entrada->dia,
                           paciente->entrada->mes,
                           paciente->entrada->ano);
                } else {
                    printf("\nPaciente não encontrado.\n");
                }
                break;
            }
            case 3:
                mostrar_lista_completa(lista);
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

// joga paciente na fila normal e salva essa ação no log
void enfileirar_paciente_fila(Fila* fila, Registro* paciente, PilhaOperacoes* log) {
    enfileirar(fila, paciente);
    registrar_operacao(log, ENFILEIRAR, paciente);
}

// tira paciente da fila normal e salva no log tbm
Registro* desenfileirar_paciente_fila(Fila* fila, PilhaOperacoes* log) {
    Registro* paciente = desenfileirar(fila);
    if (paciente != NULL) {
        registrar_operacao(log, DESENFILEIRAR, paciente);
    }
    return paciente;
}

// submenu do atendimento normal (fila)
void submenu_atendimento(Lista *lista, Fila *fila, PilhaOperacoes* log) {
    int opcao;
    do {
        printf("\n--- ATENDIMENTO ---\n");
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
                    enfileirar_paciente_fila(fila, paciente, log);
                    printf("\n%s entrou na fila!\n", paciente->nome);
                } else {
                    printf("\nPaciente não encontrado!\n");
                }
                break;
            }
            case 2: {
                Registro* paciente = desenfileirar_paciente_fila(fila, log);
                if (paciente != NULL) {
                    printf("\n%s atendido(a)!\n", paciente->nome);
                } else {
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

// atendimento prioritário (usa heap)
void submenu_atendimento_prioritario(Lista* lista, Heap* heap) {
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
                    enfileirar_heap(heap, paciente);
                    printf("\n%s entrou na fila prioritária!\n", paciente->nome);
                } else {
                    printf("\nPaciente não encontrado!\n");
                }
                break;
            }
            case 2: {
                Registro* paciente = desenfileirar_heap(heap);
                if (paciente != NULL) {
                    printf("\n%s atendido(a)!\n", paciente->nome);
                } else {
                    printf("\nFila prioritária vazia!\n");
                }
                break;
            }
            case 3:
                mostrar_heap(heap);
                break;
            case 0:
                return;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);
}

//submenu pesquisa (usa arvore binaria)
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
                liberar_arvore(arvore_ano);
                arvore_ano = NULL;
                printf("\nConstruindo árvore por ano...\n");
                Elista* atual = lista_pacientes.inicio;
                while (atual != NULL) {
                    inserir_por_ano(&arvore_ano, atual->dados);
                    atual = atual->proximo;
                }
                printf("\n--- PACIENTES POR ANO ---\n");
                mostrar_em_ordem_ano(arvore_ano);
                break;
            case 2:
                liberar_arvore(arvore_mes);
                arvore_mes = NULL;
                printf("\nConstruindo árvore por mês...\n");
                atual = lista_pacientes.inicio;
                while (atual != NULL) {
                    inserir_por_mes(&arvore_mes, atual->dados);
                    atual = atual->proximo;
                }
                printf("\n--- PACIENTES POR MÊS ---\n");
                mostrar_em_ordem_mes(arvore_mes);
                break;
            case 3:
                liberar_arvore(arvore_dia);
                arvore_dia = NULL;
                printf("\nConstruindo árvore por dia...\n");
                atual = lista_pacientes.inicio;
                while (atual != NULL) {
                    inserir_por_dia(&arvore_dia, atual->dados);
                    atual = atual->proximo;
                }
                printf("\n--- PACIENTES POR DIA ---\n");
                mostrar_em_ordem_dia(arvore_dia);
                break;
            case 4:
                liberar_arvore(arvore_idade);
                arvore_idade = NULL;
                printf("\nOrdenando por idade...\n");
                atual = lista_pacientes.inicio;
                while (atual != NULL) {
                    inserir_por_idade(&arvore_idade, atual->dados);
                    atual = atual->proximo;
                }
                printf("\n--- PACIENTES POR IDADE ---\n");
                mostrar_em_ordem_idade(arvore_idade);
                break;
            case 0:
                return;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);
}

//submenu dezfazer (ultilza pilha)
void submenu_desfazer(Fila* fila, PilhaOperacoes* log) {
    int opcao;
    do {
        printf("\n--- DESFAZER ---\n");
        printf("1. Mostrar histórico\n");
        printf("2. Desfazer última operação\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                mostrar_log(log);
                break;
            case 2: {
                Operacao* op = desfazer_operacao(log);
                if (op != NULL) {
                    printf("\nOperação a desfazer: %s %s\n", 
                           op->tipo == ENFILEIRAR ? "ENFILEIRAR" : "DESENFILEIRAR",
                           op->paciente->nome);
                    
                    printf("Confirmar (s/n)? ");
                    char confirmacao;
                    scanf(" %c", &confirmacao);
                    
                    if (confirmacao == 's' || confirmacao == 'S') {
                        if (op->tipo == ENFILEIRAR) {
                            desenfileirar(fila);
                        } else {
                            enfileirar(fila, op->paciente);
                        }
                        printf("Operação desfeita!\n");
                    } else {
                        registrar_operacao(log, op->tipo, op->paciente);
                    }
                } else {
                    printf("\nNada para desfazer!\n");
                }
                break;
            }
            case 0:
                return;
            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);
}


//le e salva arquvi com dados dos pscientes
void submenu_carregar_salvar(Lista* lista) {
    int opcao;
    char nome_arquivo[100];

    do {
        printf("\n--- CARREGAR/SALVAR ---\n");
        printf("1. Carregar dados\n");
        printf("2. Salvar dados\n");
        printf("0. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                printf("\nDigite o nome do arquivo para carregar: ");
                scanf("%99s", nome_arquivo);
                carregar_lista_arquivo(lista, nome_arquivo);
                break;
            case 2:
                printf("\nDigite o nome do arquivo para salvar: ");
                scanf("%99s", nome_arquivo);
                salvar_lista_arquivo(lista, nome_arquivo);
                break;
            case 0:
                return;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
}


//dados projeto
void mostrar_sobre() {
    printf("\n--- SOBRE O PROJETO ---\n");
    printf("Gerenciador de Atendimento Médico\n");
    printf("Desenvolvido por: Guilherme Silva Meireles || Natasha Almeida Trindade\n");
    printf("Matrícula/RM:     22.123.094-9             || 22.123.084-0\n");
    printf("Curso: Ciência da Computação\n");
    printf("Disciplina: Estrutura de Dados\n");
    printf("Professor: Luciano Rossi\n");
    printf("Instituição: Centro Universitário FEI\n");
    printf("Semestre: 4º/2025\n");
    printf("\nEste sistema gerencia:\n");
    printf("- Cadastro de pacientes\n");
    printf("- Atendimento regular e prioritário\n");
    printf("- Pesquisas personalizadas\n");
    printf("- Histórico de operações\n");
}

int main() {
    // Inicializa todas as estruturas
    inicializar_pilha(&log_operacoes);
    inicializar_lista(&lista_pacientes);
    inicializar_fila(&fila_atendimento);
    inicializar_heap(&heap_prioritario, 20);

    int opcao;
    do {
        mostrar_menu();
        scanf("%d", &opcao);

        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                submenu_cadastrar(&lista_pacientes);
                break;
            case 2:
                submenu_atendimento(&lista_pacientes, &fila_atendimento, &log_operacoes);
                break;
            case 3:
                submenu_atendimento_prioritario(&lista_pacientes, &heap_prioritario);
                break;
            case 4:
                submenu_pesquisa();
                break;
            case 5:
                submenu_desfazer(&fila_atendimento, &log_operacoes);
                break;
case 6:
    submenu_carregar_salvar(&lista_pacientes);
    break;
            case 7:
                mostrar_sobre();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção não existe, escolha uma de 0 a 7\n");
        }
    } while (opcao != 0);

    // Libera memória
    liberar_lista(&lista_pacientes);
    liberar_fila(&fila_atendimento);
    liberar_heap(&heap_prioritario);
    liberar_arvore(arvore_ano);
    liberar_arvore(arvore_mes);
    liberar_arvore(arvore_dia);
    liberar_arvore(arvore_idade);

    return 0;
}
