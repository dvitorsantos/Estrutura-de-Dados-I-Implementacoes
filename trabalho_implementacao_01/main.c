#include <stdio.h>
#include <stdlib.h>
#include "Cofo.h"

#define FALSE 0
#define TRUE 1

int get_max_itens(Cofo *pCofo);

void menu() {
    printf("Digite uma operação do Cofo: \n");
    printf("1 - Criar cofo\n");
    printf("2 - Inserir item no cofo\n");
    printf("3 - Ver itens do cofo\n");
    printf("4 - Procurar item no cofo\n");
    printf("5 - Remover item do cofo\n");
    printf("6 - Deletar cofo\n");
    printf("0 - Sair\n");
}

int main() {
    int exit = 0, opcao = 0;
    int search, search_result, size, item;
    Cofo *cofo;

    while (!exit) {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o tamanho do cofo:\n");
                scanf("%d", &size);
                cofo = create_cofo(size);
                if (cofo != NULL) printf("Cofo criado com sucesso!\n");
                else printf("Erro ao criar o cofo!\n");
                break;
            case 2:
                printf("Digite 0 para parar de inserir itens.\n");
                printf("Digite os itens para inserir no cofo:\n");
                while (!exit) {
                    scanf("%d", &item);
                    if (item == 0) break;
                    if(insert_cofo(cofo, item)) printf("Item inserido com sucesso!\n");
                    else printf("Erro ao inserir item!\n");
                }
                item = -1;
                break;
            case 3:
                printf("Itens do cofo:\n");
                int *itens = itens_cofo(cofo);
                for (int i = 0; i < get_max_itens(cofo); ++i) {
                    printf(" [%d] ", itens[i]);
                }
                printf("\n");
                break;
            case 4:
                printf("Digite o item que deseja procurar:\n");
                scanf("%d", &search);
                search_result = find_cofo(cofo, search);
                if (search_result == FALSE) printf("Item não encontrado.\n");
                else printf("Item encontrado: %d\n", search_result);
                break;
            case 5:
                printf("Digite o item que deseja remover:\n");
                scanf("%d", &search);
                search_result = remove_item_cofo(cofo, search);
                if (search_result == FALSE) printf("Item não encontrado.\n");
                else printf("Item removido: %d\n", search_result);
                break;
            case 6:
                if (delete_cofo(cofo) == FALSE) printf("Erro ao deletar cofo.\n");
                else printf("Cofo deletado.\n");
                break;
            case 0:
                exit = 1;
                break;
        }
    }

    return 0;
}