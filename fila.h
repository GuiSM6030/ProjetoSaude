#ifndef FILA_H
#define FILA_H

#include "paciente.h"

// no da fila
typedef struct EFila
{
    Registro *dados;       // info do paciente
    struct EFila *proximo; // aponta pro proximo da fila
} EFila;

// estrutura da fila
typedef struct
{
    EFila *head; // comeco da fila
    EFila *tail; // fim da fila
    int qtde;    // qtd de elementos
} Fila;

// funcoes da fila
void inicializar_fila(Fila *fila);        // bota fila no estado inicial
void enfileirar(Fila *fila, Registro *paciente); // bota paciente no fim
Registro *desenfileirar(Fila *fila);      // tira paciente do comeco
void mostrar_fila(Fila *fila);            // printa geral da fila

#endif
