// heap.c
#include "heap.h"
#include <stdlib.h>

void inicializar_heap(Heap* heap, int capacidade) {
    heap->dados = (Registro**)malloc(capacidade * sizeof(Registro*));
    heap->qtde = 0;
    heap->capacidade = capacidade;
}

void subir_heap(Heap* heap, int indice) {
    if (indice == 0) return;
    
    int pai = (indice - 1) / 2;
    if (heap->dados[pai]->idade < heap->dados[indice]->idade) {
        Registro* temp = heap->dados[pai];
        heap->dados[pai] = heap->dados[indice];
        heap->dados[indice] = temp;
        subir_heap(heap, pai);
    }
}

void enfileirar_heap(Heap* heap, Registro* paciente) {
    if (heap->qtde == heap->capacidade) return;
    
    heap->dados[heap->qtde] = paciente;
    subir_heap(heap, heap->qtde);
    heap->qtde++;
}

void liberar_heap(Heap* heap) {
    free(heap->dados);
}