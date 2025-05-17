// paciente.h
#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[100];
    int idade;
    char rg[20];
    Data* entrada;
} Registro;

//criado pra manipular os dados dos pacientes
Data* criar_data(int dia, int mes, int ano);
Registro* criar_registro(char nome[], int idade, char rg[], Data* entrada);
void liberar_registro(Registro* registro);

#endif