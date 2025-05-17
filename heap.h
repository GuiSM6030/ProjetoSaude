// heap.h
#ifndef HEAP_H
#define HEAP_H

#include "paciente.h"

typedef struct {
    Registro** dados;
    int qtde;
    int capacidade;
} Heap;

Registro* desenfileirar_heap(Heap* heap);

void inicializar_heap(Heap* heap, int capacidade);
void enfileirar_heap(Heap* heap, Registro* paciente);
void liberar_heap(Heap* heap);

#endif