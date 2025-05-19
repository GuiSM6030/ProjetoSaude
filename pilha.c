#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

void inicializar_pilha(PilhaOperacoes* p) {
    p->topo = NULL;
    p->tamanho = 0;
}

void registrar_operacao(PilhaOperacoes* p, TipoOperacao tipo, Registro* paciente) {
    NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha));
    novo->op.tipo = tipo;
    novo->op.paciente = paciente;
    novo->anterior = p->topo;
    p->topo = novo;
    p->tamanho++;
}

Operacao* desfazer_operacao(PilhaOperacoes* p) {
    if (p->topo == NULL) return NULL;
    
    NoPilha* temp = p->topo;
    Operacao* op = &(temp->op);
    p->topo = temp->anterior;
    free(temp);
    p->tamanho--;
    
    return op;
}

void mostrar_log(PilhaOperacoes* p) {
    if (p->topo == NULL) {
        printf("\nNenhuma operação registrada.\n");
        return;
    }
    
    printf("\n--- ÚLTIMAS OPERAÇÕES ---\n");
    NoPilha* atual = p->topo;
    while (atual != NULL) {
        printf("%s: %s (RG: %s)\n",
               atual->op.tipo == ENFILEIRAR ? "ENFILEIRAR" : "DESENFILEIRAR",
               atual->op.paciente->nome,
               atual->op.paciente->rg);
        atual = atual->anterior;
    }
}