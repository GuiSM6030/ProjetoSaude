#ifndef PILHA_H
#define PILHA_H

#include "paciente.h"

typedef enum {
    ENFILEIRAR,
    DESENFILEIRAR
} TipoOperacao;

typedef struct {
    TipoOperacao tipo;
    Registro* paciente;
} Operacao;

typedef struct NoPilha {
    Operacao op;
    struct NoPilha* anterior;
} NoPilha;

typedef struct {
    NoPilha* topo;
    int tamanho;
} PilhaOperacoes;

void inicializar_pilha(PilhaOperacoes* p);
void registrar_operacao(PilhaOperacoes* p, TipoOperacao tipo, Registro* paciente);
Operacao* desfazer_operacao(PilhaOperacoes* p);
void mostrar_log(PilhaOperacoes* p);

#endif