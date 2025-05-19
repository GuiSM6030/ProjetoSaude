#ifndef PACIENTE_H
#define PACIENTE_H

//estrutura pra data com dia mes ano
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

//estrutura pra registro do paciente com nome idade rg e data de entrada
typedef struct {
    char nome[100];
    int idade;
    char rg[20];
    Data* entrada;
} Registro;

// criado pra manipular dados dos pacientes

// cria data com dia mes ano passados
Data* criar_data(int dia, int mes, int ano);

// cria registro do paciente com nome idade rg e data
Registro* criar_registro(char nome[], int idade, char rg[], Data* entrada);

// libera memoria do registro e da data
void liberar_registro(Registro* registro);

#endif
