#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

// inicializa pilha zerando topo e tamanho
void inicializar_pilha(PilhaOperacoes* p) {
    p->topo = NULL;
    p->tamanho = 0;
}

// registra operacao (enfileirar/desenfileirar) empilhando no topo
void registrar_operacao(PilhaOperacoes* p, TipoOperacao tipo, Registro* paciente) {
    NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha)); // aloca no da pilha
    novo->op.tipo = tipo;        // seta tipo da operacao
    novo->op.paciente = paciente; // associa paciente
    novo->anterior = p->topo;    // novo aponta pro antigo topo
    p->topo = novo;              // topo atualiza pro novo
    p->tamanho++;                // incrementa tamanho
}

// desfaz ultima operacao retirando do topo e retornando ela
Operacao* desfazer_operacao(PilhaOperacoes* p) {
    if (p->topo == NULL) return NULL; // pilha vazia, nada a desfazer
    
    NoPilha* temp = p->topo;        // guarda no topo
    Operacao* op = &(temp->op);     // pega operacao daquele no
    p->topo = temp->anterior;       // topo atualiza pro anterior
    free(temp);                     // libera no removido
    p->tamanho--;                   // decrementa tamanho
    
    return op;                      // retorna operacao desfeita
}

// mostra historico das operacoes da pilha do topo ate o fim
void mostrar_log(PilhaOperacoes* p) {
    if (p->topo == NULL) {
        printf("\nNenhuma operacao registrada.\n");
        return;
    }
    
    printf("\n--- ULTIMAS OPERACOES ---\n");
    NoPilha* atual = p->topo;
    while (atual != NULL) {
        printf("%s: %s (RG: %s)\n",
               atual->op.tipo == ENFILEIRAR ? "ENFILEIRAR" : "DESENFILEIRAR",
               atual->op.paciente->nome,
               atual->op.paciente->rg);
        atual = atual->anterior; // vai pro proximo no (anterior do atual)
    }
}
