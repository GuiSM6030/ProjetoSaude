// arvore.c
#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

void inserir_por_ano(NoArvore** raiz, Registro* paciente) {
    if (*raiz == NULL) {
        *raiz = (NoArvore*)malloc(sizeof(NoArvore));
        (*raiz)->dado = paciente;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    } else {
        int ano_paciente = paciente->entrada->ano;
        int ano_raiz = (*raiz)->dado->entrada->ano;
        
        if (ano_paciente < ano_raiz) {
            inserir_por_ano(&(*raiz)->esq, paciente);
        } else {
            inserir_por_ano(&(*raiz)->dir, paciente);
        }
    }
}

void mostrar_em_ordem_ano(NoArvore* raiz) {
    if (raiz != NULL) {
        mostrar_em_ordem_ano(raiz->esq);
        printf("Ano: %d - %s (RG: %s)\n", 
               raiz->dado->entrada->ano, 
               raiz->dado->nome, 
               raiz->dado->rg);
        mostrar_em_ordem_ano(raiz->dir);
    }
}

void liberar_arvore(NoArvore* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esq);
        liberar_arvore(raiz->dir);
        free(raiz);
    }
}