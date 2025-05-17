#ifndef FILA_H
#define FILA_H

#include "paciente.h"
typedef struct EFila
{
    Registro *dados;
    struct EFila *proximo;
} EFila;

typedef struct
{
    EFila *head;
    EFila *tail;
    int qtde;
} Fila;

void inicializar_fila(Fila *fila);
void enfileirar(Fila *fila, Registro *paciente);
Registro *desenfileirar(Fila *fila);
void mostrar_fila(Fila *fila);

#endif