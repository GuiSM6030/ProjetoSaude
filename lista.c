// lista.c
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializar_lista(Lista* lista) {
    lista->inicio = NULL;
    lista->qtde = 0;
}

void cadastrar_paciente(Lista* lista) {
    printf("\n--- CADASTRO DE PACIENTE ---\n");
    
    char nome[100];
    int idade;
    char rg[20];
    int dia, mes, ano;
    
    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    
    printf("Idade: ");
    scanf("%d", &idade);
    
    printf("RG: ");
    scanf("%s", rg);
    
    printf("Data de entrada (dia mes ano): ");
    scanf("%d %d %d", &dia, &mes, &ano);
    
    Data* entrada = criar_data(dia, mes, ano);
    Registro* novo_paciente = criar_registro(nome, idade, rg, entrada);
    
    // Insere no início da lista
    Elista* novo_elemento = (Elista*)malloc(sizeof(Elista));
    novo_elemento->dados = novo_paciente;
    novo_elemento->proximo = lista->inicio;
    lista->inicio = novo_elemento;
    lista->qtde++;
    
    printf("\nPaciente cadastrado com sucesso!\n");
}

void liberar_lista(Lista* lista) {
    Elista* atual = lista->inicio;
    while (atual != NULL) {
        Elista* temp = atual;
        atual = atual->proximo;
        liberar_registro(temp->dados);
        free(temp);
    }
    lista->inicio = NULL;
    lista->qtde = 0;
}