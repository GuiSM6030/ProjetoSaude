#ifndef LISTA_H
#define LISTA_H

#include "paciente.h"

typedef struct Elista {
    Registro *dados;
    struct Elista *proximo;
} Elista;

typedef struct {
    Elista *inicio;
    int qtde;
} Lista;

// inicializa lista vazia
void inicializar_lista(Lista *lista);

// cadastra paciente novo
void cadastrar_paciente(Lista *lista);

// libera memoria da lista
void liberar_lista(Lista *lista);

// mostra todos os pacientes
void mostrar_lista_completa(Lista *lista);

// atualiza dados do paciente pelo rg
void atualizar_paciente(Lista *lista);

// remove paciente pelo rg
void remover_paciente(Lista* lista);

// salva lista num arquivo texto
void salvar_lista_arquivo(Lista* lista, const char* nome_arquivo);

// carrega lista de arquivo texto
void carregar_lista_arquivo(Lista* lista, const char* nome_arquivo);

// consulta paciente pelo rg
Registro *consultar_paciente(Lista *lista, char rg[]);

#endif
