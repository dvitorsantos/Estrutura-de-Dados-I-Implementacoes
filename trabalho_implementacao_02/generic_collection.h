//
// Created by vitor on 17/05/22.
//

#ifndef GENERIC_COLLECTION_H_INCLUDED
#define GENERIC_COLLECTION_H_INCLUDED

typedef struct generic_collection GenericCollection;

GenericCollection *genericCollectionCreate(int size);

int genericCollectionDestroy(GenericCollection *genericCollection);

int genericCollectionInsert(GenericCollection *genericCollection, void *element);

int genericCollectionCurrentSize(GenericCollection *genericCollection);

int genericCollectionSize(GenericCollection *genericCollection);

void *genericCollectionFindAll(GenericCollection *genericCollection);

void *genericCollectionFind(GenericCollection *genericCollection, void *key, int(*cmp)(void *, void *));

int *genericCollectionRemove(GenericCollection *genericCollection, void *key, int(*cmp)(void *, void *));

int genericCollectionEmpty(GenericCollection *genericCollection);

#endif //GENERIC_COLLECTION_H_INCLUDED