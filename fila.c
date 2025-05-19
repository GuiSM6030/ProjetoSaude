#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

// inicia a fila zerada
void inicializar_fila(Fila *fila)
{
    fila->head = NULL;
    fila->tail = NULL;
    fila->qtde = 0;
}

// joga paciente no fim da fila
void enfileirar(Fila *fila, Registro *paciente)
{
    EFila *novo = (EFila *)malloc(sizeof(EFila));
    novo->dados = paciente;
    novo->proximo = NULL;

    if (fila->tail == NULL)
    { // fila ta vazia
        fila->head = novo;
    }
    else
    {
        fila->tail->proximo = novo;
    }
    fila->tail = novo;
    fila->qtde++;
}

// tira paciente do comeco da fila
Registro *desenfileirar(Fila *fila)
{
    if (fila->head == NULL)
        return NULL; // fila vazia

    EFila *removido = fila->head;
    Registro *paciente = removido->dados;

    fila->head = fila->head->proximo;
    if (fila->head == NULL)
        fila->tail = NULL; // fila esvaziou

    free(removido);
    fila->qtde--;
    return paciente;
}

// mostra geral que ta na fila
void mostrar_fila(Fila *fila)
{
    if (fila->head == NULL)
    {
        printf("\n--- FILA VAZIA ---\nNenhum paciente aguardando.\n");
        return;
    }

    printf("\n--- FILA DE ATENDIMENTO ---\n");
    EFila *atual = fila->head;
    int posicao = 1;

    while (atual != NULL)
    {
        printf("[%d] %s (RG: %s)\n", posicao++, atual->dados->nome, atual->dados->rg);
        atual = atual->proximo;
    }
    printf("Total na fila: %d\n", fila->qtde);
}

// libera tudo da memoria
void liberar_fila(Fila* fila) {
    while (fila->head != NULL) {
        EFila* temp = fila->head;
        fila->head = fila->head->proximo;
        free(temp);
    }
    fila->tail = NULL;
    fila->qtde = 0;
}
