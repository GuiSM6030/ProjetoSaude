#include "paciente.h"
#include <stdlib.h>

// cria data nova com dia mes ano passados
Data* criar_data(int dia, int mes, int ano) {
    Data* nova_data = (Data*)malloc(sizeof(Data)); // aloca memoria pra data
    nova_data->dia = dia;
    nova_data->mes = mes;
    nova_data->ano = ano;
    return nova_data; // retorna ponteiro da data criada
}

// cria registro de paciente com nome idade rg e data de entrada
Registro* criar_registro(char nome[], int idade, char rg[], Data* entrada) {
    Registro* novo_registro = (Registro*)malloc(sizeof(Registro)); // aloca memoria pro registro
    strcpy(novo_registro->nome, nome); // copia nome pro registro
    novo_registro->idade = idade;      // seta idade
    strcpy(novo_registro->rg, rg);     // copia rg
    novo_registro->entrada = entrada;  // associa data de entrada
    return novo_registro; // retorna ponteiro pro registro criado
}

// libera memoria do registro e da data dentro dele
void liberar_registro(Registro* registro) {
    if (registro != NULL) {
        free(registro->entrada); // libera data
        free(registro);          // libera registro
    }
}
