//
// Created by vitor on 29/05/22.
//

#ifndef SINGLELINKEDLIST_SINGLE_LINKED_LIST_H
#define SINGLELINKEDLIST_SINGLE_LINKED_LIST_H

typedef struct _slnode_ {
    void *data;
    struct _slnode_ *next;
} SingleListNode;

typedef struct _sllist_ {
    SingleListNode *first;
} SingleLinkedList;

SingleLinkedList *sllCreate();

int sllDestroy (SingleLinkedList *list);

void sllGetFirst(SingleLinkedList *list);

int sllInsertFirst(SingleLinkedList *list, void *data);

int sllInsertAtLast(SingleLinkedList *list, void *data);

void *sllRemoveFirst(SingleLinkedList *list);

void *sllQuery(SingleLinkedList *list, void *key, int (*cmp)(void *, void *));

#endif //SINGLELINKEDLIST_SINGLE_LINKED_LIST_H
