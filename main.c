// main.c
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void mostrar_menu() {
    printf("\n-- ATENDIMENTO DE SAÚDE --\n");
    printf("\n---- Hospital da FEI ----\n");
    printf("1. Cadastrar paciente\n");
    printf("2. Atendimento\n");
    printf("3. Atendimento prioritário\n");
    printf("4. Pesquisa\n");
    printf("5. Desfazer\n");
    printf("6. Carregar / Salvar\n");
    printf("7. Sobre\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Lista lista_pacientes;
    inicializar_lista(&lista_pacientes);

    int opcao;
    do {
        mostrar_menu();
        scanf("%d", &opcao);
        
        while (getchar() != '\n'); // Limpar buffer

        switch (opcao) {
            case 1:
                cadastrar_paciente(&lista_pacientes);
                break;
            case 2:
                printf("Atendimento (a ser implementado)\n");
                break;
            case 3:
                printf("Atendimento prioritário (a ser implementado)\n");
                break;
            case 4:
                printf("Pesquisa (a ser implementado)\n");
                break;
            case 5:
                printf("Desfazer (a ser implementado)\n");
                break;
            case 6:
                printf("Carregar / Salvar (a ser implementado)\n");
                break;
            case 7:
                printf("Sobre (a ser implementado)\n");
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção não existe, escolha uma de 0 a 7\n");
        }
    } while (opcao != 0);

    liberar_lista(&lista_pacientes);
    return 0;
}