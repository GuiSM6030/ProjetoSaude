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

void inserir_por_mes(NoArvore** raiz, Registro* paciente) {
    if (*raiz == NULL) {
        *raiz = (NoArvore*)malloc(sizeof(NoArvore));
        (*raiz)->dado = paciente;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    } else {
        int mes_paciente = paciente->entrada->mes;
        int mes_raiz = (*raiz)->dado->entrada->mes;
        
        if (mes_paciente < mes_raiz) {
            inserir_por_mes(&(*raiz)->esq, paciente);
        } else {
            inserir_por_mes(&(*raiz)->dir, paciente);
        }
    }
}

void mostrar_em_ordem_mes(NoArvore* raiz) {
    if (raiz != NULL) {
        mostrar_em_ordem_mes(raiz->esq);
        printf("Mês: %02d - %s (RG: %s)\n", 
               raiz->dado->entrada->mes, 
               raiz->dado->nome, 
               raiz->dado->rg);
        mostrar_em_ordem_mes(raiz->dir);
    }
}

void inserir_por_dia(NoArvore** raiz, Registro* paciente) {
    if (*raiz == NULL) {
        *raiz = (NoArvore*)malloc(sizeof(NoArvore));
        (*raiz)->dado = paciente;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    } else {
        int dia_paciente = paciente->entrada->dia;
        int dia_raiz = (*raiz)->dado->entrada->dia;
        
        if (dia_paciente < dia_raiz) {
            inserir_por_dia(&(*raiz)->esq, paciente);
        } else {
            inserir_por_dia(&(*raiz)->dir, paciente);
        }
    }
}

void mostrar_em_ordem_dia(NoArvore* raiz) {
    if (raiz != NULL) {
        mostrar_em_ordem_dia(raiz->esq);
        printf("Dia: %02d - %s (Mês: %d, RG: %s)\n", 
               raiz->dado->entrada->dia,
               raiz->dado->nome,
               raiz->dado->entrada->mes,
               raiz->dado->rg);
        mostrar_em_ordem_dia(raiz->dir);
    }
}

void inserir_por_idade(NoArvore** raiz, Registro* paciente) {
    if (*raiz == NULL) {
        *raiz = (NoArvore*)malloc(sizeof(NoArvore));
        (*raiz)->dado = paciente;
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    } else {
        if (paciente->idade < (*raiz)->dado->idade) {
            inserir_por_idade(&(*raiz)->esq, paciente);
        } else {
            inserir_por_idade(&(*raiz)->dir, paciente);
        }
    }
}

void mostrar_em_ordem_idade(NoArvore* raiz) {
    if (raiz != NULL) {
        mostrar_em_ordem_idade(raiz->esq);
        printf("Idade: %2d - %s (RG: %s)\n",
               raiz->dado->idade,
               raiz->dado->nome,
               raiz->dado->rg);
        mostrar_em_ordem_idade(raiz->dir);
    }
}