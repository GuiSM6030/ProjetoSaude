// lista.c
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// inicia a lista vazia
void inicializar_lista(Lista *lista)
{
    lista->inicio = NULL;
    lista->qtde = 0;
}

// cadastra um paciente novo e joga no inicio da lista
void cadastrar_paciente(Lista *lista)
{
    printf("\n--- CADASTRO DE PACIENTE ---\n");

    char nome[100];
    int idade;
    char rg[20];
    int dia, mes, ano;

    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &idade);

    printf("RG: ");
    scanf("%s", rg);

    printf("Data de entrada (dia mes ano): ");
    scanf("%d %d %d", &dia, &mes, &ano);

    Data *entrada = criar_data(dia, mes, ano);
    Registro *novo_paciente = criar_registro(nome, idade, rg, entrada);

    // Insere no início da lista
    Elista *novo_elemento = (Elista *)malloc(sizeof(Elista));
    novo_elemento->dados = novo_paciente;
    novo_elemento->proximo = lista->inicio;
    lista->inicio = novo_elemento;
    lista->qtde++;

    printf("\nPaciente cadastrado com sucesso!\n");
}

// libera geral da memoria da lista
void liberar_lista(Lista *lista)
{
    Elista *atual = lista->inicio;
    while (atual != NULL)
    {
        Elista *temp = atual;
        atual = atual->proximo;
        liberar_registro(temp->dados);
        free(temp);
    }
    lista->inicio = NULL;
    lista->qtde = 0;
}

// busca paciente pelo rg
Registro *consultar_paciente(Lista *lista, char rg[])
{
    Elista *atual = lista->inicio;
    while (atual != NULL)
    {
        if (strcmp(atual->dados->rg, rg) == 0)
        {
            return atual->dados; // Retorna o paciente se encontrado
        }
        atual = atual->proximo;
    }
    return NULL; // Retorna NULL se não encontrado
}

// mostra todos os pacientes da lista
void mostrar_lista_completa(Lista *lista)
{
    if (lista->inicio == NULL)
    {
        printf("\n--- LISTA VAZIA ---\nNenhum paciente cadastrado.\n");
        return;
    }

    printf("\n--- LISTA COMPLETA DE PACIENTES ---\n");
    Elista *atual = lista->inicio;
    int contador = 1;

    while (atual != NULL)
    {
        printf("\n[%d] Nome: %s\n", contador, atual->dados->nome);
        printf("    RG: %s\n", atual->dados->rg);
        printf("    Idade: %d\n", atual->dados->idade);
        printf("    Data de entrada: %02d/%02d/%04d\n",
               atual->dados->entrada->dia,
               atual->dados->entrada->mes,
               atual->dados->entrada->ano);
        atual = atual->proximo;
        contador++;
    }
    printf("\nTotal: %d paciente(s)\n", lista->qtde);
}

// edita paciente se achar pelo rg
void atualizar_paciente(Lista *lista)
{
    char rg_atualizar[20];
    printf("\nDigite o RG do paciente que deseja atualizar: ");
    scanf("%s", rg_atualizar);

    Elista *atual = lista->inicio;
    while (atual != NULL)
    {
        if (strcmp(atual->dados->rg, rg_atualizar) == 0)
        {
            printf("\n--- EDITANDO PACIENTE ---\n");
            printf("Dados atuais:\n");
            printf("Nome: %s\n", atual->dados->nome);
            printf("Idade: %d\n", atual->dados->idade);
            printf("RG: %s\n", atual->dados->rg);
            printf("Data de entrada: %02d/%02d/%04d\n",
                   atual->dados->entrada->dia,
                   atual->dados->entrada->mes,
                   atual->dados->entrada->ano);

            // Opções de atualização
            char novo_nome[100];
            int nova_idade, novo_dia, novo_mes, novo_ano;

            printf("\nNovo nome (ou ENTER para manter): ");
            getchar(); // Limpa o buffer
            fgets(novo_nome, sizeof(novo_nome), stdin);
            novo_nome[strcspn(novo_nome, "\n")] = '\0'; // Remove o \n

            if (strlen(novo_nome) > 0)
            {
                strcpy(atual->dados->nome, novo_nome);
            }

            printf("Nova idade (digite 0 para manter): ");
            scanf("%d", &nova_idade);
            if (nova_idade > 0)
            {
                atual->dados->idade = nova_idade;
            }

            printf("Nova data (dia mês ano, digite 0 0 0 para manter): ");
            scanf("%d %d %d", &novo_dia, &novo_mes, &novo_ano);
            if (novo_dia > 0 && novo_mes > 0 && novo_ano > 0)
            {
                atual->dados->entrada->dia = novo_dia;
                atual->dados->entrada->mes = novo_mes;
                atual->dados->entrada->ano = novo_ano;
            }

            printf("\nPaciente atualizado com sucesso!\n");
            return;
        }
        atual = atual->proximo;
    }
    printf("\nPaciente com RG %s não encontrado.\n", rg_atualizar);
}

// remove paciente pelo rg se achar
void remover_paciente(Lista* lista) {
    if (lista->inicio == NULL) {
        printf("\nLista vazia! Nenhum paciente para remover.\n");
        return;
    }

    char rg_remover[20];
    printf("\nDigite o RG do paciente que deseja remover: ");
    scanf("%s", rg_remover);

    Elista* atual = lista->inicio;
    Elista* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->dados->rg, rg_remover) == 0) {
            printf("\n--- REMOVENDO PACIENTE ---\n");
            printf("Nome: %s\n", atual->dados->nome);
            printf("RG: %s\n", atual->dados->rg);

            // Ajusta os ponteiros da lista
            if (anterior == NULL) {
                lista->inicio = atual->proximo; // Remove o primeiro
            } else {
                anterior->proximo = atual->proximo; // Remove no meio/fim
            }

            // Libera a memória
            liberar_registro(atual->dados);
            free(atual);
            lista->qtde--;

            printf("\nPaciente removido com sucesso!\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("\nPaciente com RG %s não encontrado.\n", rg_remover);
}

// salva lista em arquivo texto
void salvar_lista_arquivo(Lista* lista, const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para escrita!\n");
        return;
    }

    Elista* atual = lista->inicio;
    while (atual != NULL) {
        fprintf(arquivo, "%s;%d;%s;%d;%d;%d\n",
                atual->dados->nome,
                atual->dados->idade,
                atual->dados->rg,
                atual->dados->entrada->dia,
                atual->dados->entrada->mes,
                atual->dados->entrada->ano);
        atual = atual->proximo;
    }

    fclose(arquivo);
    printf("Dados salvos em '%s'!\n", nome_arquivo);
}

// carrega dados do arquivo e monta a lista
void carregar_lista_arquivo(Lista* lista, const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Arquivo '%s' não encontrado!\n", nome_arquivo);
        return;
    }

    // Limpa a lista atual antes de carregar
    liberar_lista(lista);
    inicializar_lista(lista);

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        char nome[100], rg[20];
        int idade, dia, mes, ano;

        if (sscanf(linha, "%[^;];%d;%[^;];%d;%d;%d",
                   nome, &idade, rg, &dia, &mes, &ano) == 6) {
            Data* entrada = criar_data(dia, mes, ano);
            Registro* paciente = criar_registro(nome, idade, rg, entrada);
            inserir_lista(lista, paciente);
        }
    }

    fclose(arquivo);
    printf("Dados carregados de '%s'!\n", nome_arquivo);
}

// insere paciente no inicio da lista (usado pelo carregar)
void inserir_lista(Lista* lista, Registro* registro) {
    Elista* novo = (Elista*)malloc(sizeof(Elista));
    novo->dados = registro;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->qtde++;
}