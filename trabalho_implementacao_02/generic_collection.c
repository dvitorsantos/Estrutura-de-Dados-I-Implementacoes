//
// Created by vitor on 17/05/22.
//

#include "generic_collection.h"
#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct generic_collection {
    int size;
    int current_size;
    void **elements;
} GenericCollection;

GenericCollection *genericCollectionCreate(int size) {
    if (size < 1) return NULL;

    GenericCollection *genericCollection = (GenericCollection *) malloc(sizeof(GenericCollection) * size);

    genericCollection->elements = (void **) malloc(sizeof(void *) * size);

    if (genericCollection->elements == NULL) {
        free(genericCollection);
        return NULL;
    }

    genericCollection->size = size;
    genericCollection->current_size = 0;

    return genericCollection;
}

int genericCollectionInsert(GenericCollection *genericCollection, void *element) {
    if (genericCollection == NULL
        || genericCollection->current_size == genericCollection->size
        || element == NULL)
        return FALSE;

    genericCollection->elements[genericCollection->current_size] = element;
    genericCollection->current_size++;
    return TRUE;
}

int genericCollectionDestroy(GenericCollection *genericCollection) {
    if (genericCollection == NULL || genericCollection->current_size > 0) return FALSE;

    free(genericCollection->elements);
    free(genericCollection);

    return TRUE;
}

int genericCollectionCurrentSize(GenericCollection *genericCollection) {
    if (genericCollection == NULL) return FALSE;

    return genericCollection->current_size;
}

int genericCollectionSize(GenericCollection *genericCollection) {
    if (genericCollection == NULL) return FALSE;

    return genericCollection->size;
}

void *genericCollectionFindAll(GenericCollection *genericCollection) {
    if (genericCollection == NULL || genericCollection->current_size == 0) return NULL;

    return genericCollection->elements;
}

void *genericCollectionFind(GenericCollection *genericCollection, void *key, int(*cmp)(void *, void *)) {
    if (genericCollection == NULL) return NULL;

    for (int i = 0; i < genericCollection->current_size; i++) {
        if (cmp(genericCollection->elements[i], key)) {
            void *data = genericCollection->elements[i];
            return data;
        }
    }

    return NULL;
}

int genericCollectionRemove(GenericCollection *genericCollection, void *key, int(*cmp)(void *, void *)) {
    if (genericCollection == NULL) return FALSE;

    for (int i = 0; i < genericCollection->current_size; i++) {
        if (cmp(genericCollection->elements[i], key)) {
            genericCollection->elements[i] = NULL;

            for (int j = i; j < genericCollection->current_size; j++) {
                genericCollection->elements[j] = genericCollection->elements[j + 1];
            }

            genericCollection->current_size--;

            return TRUE;
        }
    }

    return FALSE;
}

int genericCollectionEmpty(GenericCollection *genericCollection) {
    if (genericCollection == NULL) return FALSE;

    genericCollection->current_size = 0;

    return TRUE;
}