#include <stdio.h>

void mostrar_menu() {
  printf("\n-- ATENDIMENTO DE SAÚDE --\n");
  printf("\n---------- MENU ----------\n");
  printf("1. Cadastrar paciente\n");
  printf("2. Atendimento\n");
  printf("3. Atendimento prioritário\n");
  printf("4. Pesquisa\n");
  printf("5. Desfazer\n");
  printf("6. Carregar / Salvar\n");
  printf("7. Sobre\n");
  printf("Escolha uma opcao: ");
}

int main() {
  int opcao;
  do {
    mostrar_menu();
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Cadastrar \n");
      break;
    case 2:
      printf("Atendimento \n");
      break;
    case 3:
      printf("Atendimento prioritário \n");
      break;
    case 4:
      printf("Pesquisa \n");
      break;
    case 5:
      printf("Desfazer \n");
      break;
    case 6:
      printf("Carregar / Salvar \n");
      break;
    case 7:
      printf("Sobre \n");
      break;
    default:
      printf("opção não existe, escolha uma de 1 a 7\n");
    }
  } while (opcao != 0);
  return 0;
}