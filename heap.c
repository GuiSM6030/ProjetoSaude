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

void descer_heap(Heap* heap, int indice) {
    int esq = 2 * indice + 1;
    int dir = 2 * indice + 2;
    int maior = indice;

    if (esq < heap->qtde && heap->dados[esq]->idade > heap->dados[maior]->idade) {
        maior = esq;
    }
    if (dir < heap->qtde && heap->dados[dir]->idade > heap->dados[maior]->idade) {
        maior = dir;
    }

    if (maior != indice) {
        Registro* temp = heap->dados[indice];
        heap->dados[indice] = heap->dados[maior];
        heap->dados[maior] = temp;
        descer_heap(heap, maior);
    }
}

Registro* desenfileirar_heap(Heap* heap) {
    if (heap->qtde == 0) return NULL;

    Registro* paciente = heap->dados[0];
    heap->dados[0] = heap->dados[heap->qtde - 1];
    heap->qtde--;
    descer_heap(heap, 0);

    return paciente;
}

void mostrar_heap(Heap* heap) {
    if (heap->qtde == 0) {
        printf("\n--- FILA PRIORITÁRIA VAZIA ---\n");
        return;
    }

    printf("\n--- FILA PRIORITÁRIA (Ordenada por Idade) ---\n");
    for (int i = 0; i < heap->qtde; i++) {
        printf("[%d] %s (Idade: %d, RG: %s)\n", 
               i+1,
               heap->dados[i]->nome,
               heap->dados[i]->idade,
               heap->dados[i]->rg);
    }
}