#ifndef ARVORE_H
#define ARVORE_H

#include "paciente.h"

typedef struct NoArvore {
    Registro* dado;
    struct NoArvore* esq;
    struct NoArvore* dir;
} NoArvore;

void inserir_por_ano(NoArvore** raiz, Registro* paciente);
void mostrar_em_ordem_ano(NoArvore* raiz);
void liberar_arvore(NoArvore* raiz);

void inserir_por_mes(NoArvore** raiz, Registro* paciente);
void mostrar_em_ordem_mes(NoArvore* raiz);

void inserir_por_dia(NoArvore** raiz, Registro* paciente);
void mostrar_em_ordem_dia(NoArvore* raiz);

void inserir_por_idade(NoArvore** raiz, Registro* paciente);
void mostrar_em_ordem_idade(NoArvore* raiz);

#endif