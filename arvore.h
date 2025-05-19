#ifndef ARVORE_H
#define ARVORE_H

#include "paciente.h"

// struct do no da arvore
typedef struct NoArvore {
    Registro* dado;
    struct NoArvore* esq;
    struct NoArvore* dir;
} NoArvore;

// funcoes pra inserir e mostrar por ano
void inserir_por_ano(NoArvore** raiz, Registro* paciente);
void mostrar_em_ordem_ano(NoArvore* raiz);

// libera geral a memoria da arvore
void liberar_arvore(NoArvore* raiz);

// funcoes pra inserir e mostrar por mes
void inserir_por_mes(NoArvore** raiz, Registro* paciente);
void mostrar_em_ordem_mes(NoArvore* raiz);

// funcoes pra inserir e mostrar por dia
void inserir_por_dia(NoArvore** raiz, Registro* paciente);
void mostrar_em_ordem_dia(NoArvore* raiz);

// funcoes pra inserir e mostrar por idade
void inserir_por_idade(NoArvore** raiz, Registro* paciente);
void mostrar_em_ordem_idade(NoArvore* raiz);

#endif
