#include "generic_collection.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct book {
    int id;
    char name[30];
    float stars;
} Book;

int cmpBookInt(void *element, void *key) {
    int *id = (int *) key;
    Book *book = (Book *) element;

    if (book->id == *id) return TRUE;
    else return FALSE;
}

int cmpBookString(void *element, void **key) {
    char *id = (char *) key;
    Book *book = (Book *) element;

    if (!strcmp(id, book->name)) return TRUE;
    else return FALSE;
}

int cmpBookFloat(void *element, void *key) {
    float *id = (float *) key;
    Book *book = (Book *) element;

    if (book->stars == *id) return TRUE;
    else return FALSE;
}

int getOperation() {
    printf("Digite uma opcao: \n");
    printf("1. Criar uma colecao\n");
    printf("2. Inserir na colecao\n");
    printf("3. Listar a colecao\n");
    printf("4. Procurar item pelo id (int): \n");
    printf("5. Procurar item pelo nome (string): \n");
    printf("6. Procurar item pela quantidade de estrelas (float): \n");
    printf("7. Remover item pelo id (int): \n");
    printf("8. Remover item pelo nome (string): \n");
    printf("9. Remover item pela quantidade de estrelas (float): \n");
    printf("10. Esvaziar a colecao\n");
    printf("11. Destruir a colecao\n");
    printf("0. Sair\n\n");

    int operation;
    scanf("%d", &operation);
    return operation;
}

int readInt(char *message) {
    int input;
    printf("%s\n\n", message);
    scanf("%d", &input);
    return input;
}

char *readString(char *message) {
    char input[30];
    char *p_input = input;

    printf("%s\n\n", message);
    scanf("%s", input);
    return p_input;
}

float readFloat(char *message) {
    float input;
    printf("%s\n\n", message);
    scanf("%f", &input);
    return input;
}

void bookToString(Book *book) {
    printf("    Livro %d: \n", book->id);
    printf("        Titulo: %s\n", book->name);
    printf("        Estrelas: %.1f\n\n", book->stars);
}

int main() {
    int exit = 0;

    while (!exit) {
        int operation = getOperation();

        int inputInt;
        char *inputString;
        float inputFloat;

        char inputStringVector[30];

        Book **books;

        Book *book;
        GenericCollection *genericCollection;

        switch (operation) {
            case 1:
                inputInt = readInt("Digite o tamanho da colecao: ");
                if (genericCollection = genericCollectionCreate(inputInt))
                    printf("Colecao criada!\n\n");
                else
                    printf("Erro ao criar a colecao!\n\n");
                break;
            case 2:
                book = (Book *) malloc(sizeof(Book));

                if (book == NULL) {
                    printf("Erro ao criar livro!\n\n");
                    break;
                }

                inputInt = readInt("Digite o codigo do livro: ");
                book->id = inputInt;
                inputString = readString("Digite o nome do livro: ");
                strcpy(book->name, inputString);
                inputFloat = readFloat("Digite a quantidade de estrelas do livro: ");
                book->stars = inputFloat;

                if (genericCollection != NULL && genericCollectionInsert(genericCollection, book))
                    printf("Livro inserido com sucesso!\n\n");
                else
                    printf("Erro ao inserir livro!\n\n");
                break;
            case 3:
                books = (Book **) genericCollectionFindAll(genericCollection);
                if (books != NULL) {
                    for (int i = 0; i < genericCollectionCurrentSize(genericCollection); i++) {
                        printf("[%d/%d]:\n", i + 1, genericCollectionSize(genericCollection));
                        bookToString(books[i]);
                    }
                    break;
                } else {
                    printf("Colecao vazia.\n\n");
                    break;
                }
            case 4:
                inputInt = readInt("Digite o id do livro");

                book = (Book *) genericCollectionFind(genericCollection, &inputInt, cmpBookInt);
                if (book) {
                    bookToString(book);
                    break;
                } else {
                    printf("Livro não econtrado.\n\n");
                    break;
                }
            case 5:
                printf("%s\n\n", "Digite o titulo do livro");
                scanf("%s", inputStringVector);

                book = (Book *) genericCollectionFind(genericCollection, inputStringVector, cmpBookString);
                if (book != NULL) {
                    bookToString(book);
                    break;
                } else {
                    printf("Livro nao econtrado.\n\n");
                    break;
                }
            case 6:
                inputFloat = readFloat("Digite a quantidade de estrelas do livro");

                book = (Book *) genericCollectionFind(genericCollection, &inputFloat, cmpBookFloat);
                if (book != NULL) {
                    bookToString(book);
                    break;
                } else {
                    printf("Livro nao econtrado.\n\n");
                    break;
                }
            case 7:
                inputInt = readInt("Digite o id do livro");

                book = genericCollectionRemove(genericCollection, &inputInt, cmpBookInt);
                if (book != NULL) {
                    printf("Livro removido.\n\n");
                    break;
                } else {
                    printf("Livro nao econtrado.\n\n");
                    break;
                }
            case 8:
                printf("%s\n\n", "Digite o titulo do livro");
                scanf("%s", inputStringVector);

                book = genericCollectionRemove(genericCollection, inputStringVector, cmpBookString);
                if (book != NULL) {
                    printf("Livro removido.\n\n");
                    break;
                } else {
                    printf("Livro não econtrado.\n\n");
                    break;
                }
            case 9:
                inputFloat = readFloat("Digite a quantidade de estrelas do livro");

                book = genericCollectionRemove(genericCollection, &inputFloat, cmpBookFloat);
                if (book != NULL) {
                    printf("Livro removido.\n\n");
                    break;
                } else {
                    printf("Livro nao econtrado.\n\n");
                    break;
                }
            case 10:
                if (genericCollectionEmpty(genericCollection)) {
                    printf("Colecao esvaziada.\n\n");
                    break;
                } else {
                    printf("Erro ao esvaziar colecao.\n\n");
                    break;
                }
            case 11:
                if (genericCollectionDestroy(genericCollection)) {
                    printf("Colecao destruida.\n\n");
                    break;
                } else {
                    printf("Erro ao destruir colecao.\n\n");
                    break;
                }
            case 0:
                exit = 1;
                break;
        }
    }

    return 0;
}