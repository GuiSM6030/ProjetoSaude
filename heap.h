// heap.h
#ifndef HEAP_H
#define HEAP_H

#include "paciente.h"

//estrutura do heap: vetor de ponteiro pros registros, qtd atual e capacidade total
typedef struct {
    Registro** dados;
    int qtde;
    int capacidade;
} Heap;

// tira o mais velho da fila (prioridade maior)
Registro* desenfileirar_heap(Heap* heap);

// inicia o heap com tamanho max
void inicializar_heap(Heap* heap, int capacidade);

// bota um paciente na fila
void enfileirar_heap(Heap* heap, Registro* paciente);

// libera a memoria do heap
void liberar_heap(Heap* heap);

// mostra geral da fila por ordem de prioridade
void mostrar_heap(Heap* heap);

#endif