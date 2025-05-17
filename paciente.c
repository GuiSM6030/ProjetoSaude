// paciente.c
#include "paciente.h"
#include <stdlib.h>

Data* criar_data(int dia, int mes, int ano) {
    Data* nova_data = (Data*)malloc(sizeof(Data));
    nova_data->dia = dia;
    nova_data->mes = mes;
    nova_data->ano = ano;
    return nova_data;
}

Registro* criar_registro(char nome[], int idade, char rg[], Data* entrada) {
    Registro* novo_registro = (Registro*)malloc(sizeof(Registro));
    strcpy(novo_registro->nome, nome);
    novo_registro->idade = idade;
    strcpy(novo_registro->rg, rg);
    novo_registro->entrada = entrada;
    return novo_registro;
}

void liberar_registro(Registro* registro) {
    if (registro != NULL) {
        free(registro->entrada);
        free(registro);
    }
}