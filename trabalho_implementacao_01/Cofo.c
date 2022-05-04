//
// Vitor Santos
// Pablo Kaua
//

#include "Cofo.h"
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef struct cofo {
    int size;
    int maxItens;
    int *itens;
} Cofo;

int find_cofo(Cofo *cofo, int key) {
    if (cofo == NULL || cofo->size < 1) return FALSE;

    for (int i = 0; i < cofo->size; ++i) {
        if (cofo->itens[i] == key) {
            return cofo->itens[i];
        }
    }

    return FALSE;
}

int insert_cofo(Cofo *cofo, int item) {
        if (cofo == NULL || cofo->size > cofo->maxItens) return FALSE;

        cofo->itens[cofo->size] = item;
        cofo->size++;

        return TRUE;
}

Cofo *create_cofo(int size) {
    if (size < 1) return NULL;

    Cofo *cofo;
    cofo = (Cofo *) malloc(sizeof(Cofo));
    if (cofo == NULL) return NULL;

    cofo->itens = (int *) malloc(sizeof(int) * size);
    if (cofo->itens == NULL) {
        free(cofo);
        return NULL;
    }

    cofo->size = 0;
    cofo->maxItens = size;

    return cofo;
}

int *itens_cofo(Cofo *cofo) {
    if (cofo == NULL) return NULL;

    return cofo->itens;
}

int delete_cofo(Cofo *cofo) {
    if ( cofo == NULL ) return FALSE;

    if (cofo->size == 0) {
        free(cofo->itens);
        free(cofo);
        return TRUE;
    }

    return FALSE;
}

int remove_item_cofo(Cofo *cofo, int key) {
    if (cofo == NULL || cofo->size < 1) return FALSE;

    for (int i = 0; i < cofo->size; i++) {
        if (cofo->itens[i] == key) {
            int data = cofo->itens[i];

            for (int j = i; j < cofo->size; j++) {
                cofo->itens[j] = cofo->itens[j+1];
            }
            cofo->size--;

            return data;
        }
    }

    return FALSE;
}

int get_max_itens(Cofo *cofo) {
    return cofo->maxItens;
}