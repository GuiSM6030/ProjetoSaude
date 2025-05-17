// lista.h
#ifndef LISTA_H
#define LISTA_H

#include "paciente.h"

typedef struct Elista {
    Registro* dados;
    struct Elista* proximo;
} Elista;

typedef struct {
    Elista* inicio;
    int qtde;
} Lista;

// usado pra listar
void inicializar_lista(Lista* lista);
void cadastrar_paciente(Lista* lista);
void liberar_lista(Lista* lista);
void mostrar_lista_completa(Lista* lista);

Registro* consultar_paciente(Lista* lista, char rg[]);

#endif