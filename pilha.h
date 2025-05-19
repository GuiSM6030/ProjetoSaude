#ifndef PILHA_H
#define PILHA_H

#include "paciente.h"

// tipos de operacao que podem ser registradas na pilha
typedef enum {
    ENFILEIRAR,
    DESENFILEIRAR
} TipoOperacao;

// estrutura pra guardar operacao feita (tipo e paciente relacionado)
typedef struct {
    TipoOperacao tipo;
    Registro* paciente;
} Operacao;

// no da pilha que guarda a operacao e aponta pro anterior
typedef struct NoPilha {
    Operacao op;
    struct NoPilha* anterior;
} NoPilha;

// pilha em si com ponteiro pro topo e tamanho atual
typedef struct {
    NoPilha* topo;
    int tamanho;
} PilhaOperacoes;

// inicializa pilha zerando topo e tamanho
void inicializar_pilha(PilhaOperacoes* p);

// registra operacao nova empilhando no topo
void registrar_operacao(PilhaOperacoes* p, TipoOperacao tipo, Registro* paciente);

// remove e retorna ultima operacao (do topo)
Operacao* desfazer_operacao(PilhaOperacoes* p);

// mostra todas as operacoes da pilha (do topo pra baixo)
void mostrar_log(PilhaOperacoes* p);

#endif
