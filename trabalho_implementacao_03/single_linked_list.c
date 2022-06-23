//
// Created by vitor on 29/05/22.
//

#include <stdlib.h>
#include <stdio.h>
#include "stdlib.h"

#define TRUE 1
#define FALSE 0

typedef struct _slnode_ {
    void *data;
    struct _slnode_ *next;
} SingleListNode;

typedef struct _sllist_ {
    SingleListNode *first;
} SingleLinkedList;

SingleLinkedList *sllCreate() {
    SingleLinkedList *list = malloc(sizeof(SingleLinkedList));

    if (list == NULL) return NULL;

    list->first = NULL;
    return list;
}

int sllDestroy(SingleLinkedList *list)
{
    if (list == NULL) return FALSE;
    if (list->first != NULL) return FALSE;

    free(list->first);
    free(list);
    return TRUE;
}

int sllEmpty(SingleLinkedList *list)
{
    if (list == NULL) return FALSE;
    if (list->first == NULL) return FALSE;

    SingleListNode *previous = list->first;
    SingleListNode *node = previous->next;

    while (node != NULL) {
        free(previous);
        previous = node;
        node = previous->next;
    }
    free(node);
    list->first = NULL;

    return TRUE;
}


int sllInsertFirst(SingleLinkedList *list, void *data) {
    if (list == NULL) return FALSE;

    SingleListNode *node = (SingleListNode *) malloc(sizeof(SingleListNode));

    if (node == NULL) return FALSE;

    node->data = data;
    node->next = list->first;
    list->first = node;
    return TRUE;
}

void *sllRemoveFirst(SingleLinkedList *list) {
    if (list == NULL) return NULL;
    if (list->first == NULL) return NULL;

    SingleListNode *first = list->first;
    void *data = first->data;

    list->first = first->next;
    free(first);
    return data;
}

void *sllRemoveByKey(SingleLinkedList *list, void *key, int (*cmp)(void *, void *)) {
    if (list == NULL) return NULL;
    if (list->first == NULL) return NULL;

    SingleListNode *node = list->first;
    SingleListNode *previous = NULL;

    int status = cmp(node->data, key);

    if (status) {
        void *data = node->data;
        list->first = node->next;
        free(node);
        return data;
    }

    while (!status && node->next != NULL) {
        previous = node;
        node = node->next;
        status = cmp(node->data, key);
    }

    if (status) {
        void *data = node->data;

        previous->next = node->next;
        free(node);

        return data;
    } else {
        return NULL;
    }
}


void *sllGetFirst(SingleLinkedList *list) {
    if (list == NULL) return NULL;
    if (list->first == NULL) return NULL;

    SingleListNode *first = list->first;
    return first->data;
}

void *sllGetFirstNode(SingleLinkedList *list) {
    if (list == NULL) return NULL;
    if (list->first == NULL) return NULL;

    SingleListNode *first = list->first;
    return first;
}

int sllInsertAtLast(SingleLinkedList *list, void *data) {
    if (list == NULL) return FALSE;

    SingleListNode *node = (SingleListNode *) malloc(sizeof(SingleListNode));

    if (node == NULL) return FALSE;

    node->data = data;
    node->next = NULL;

    if (list->first == NULL) {
        list->first = node;
    } else {
        SingleListNode *last = list->first;

        while (last->next != NULL) {
            last = last->next;
        }

        last->next = node;
    }

    return TRUE;
}

void *sllQuery(SingleLinkedList *list, void *key, int (*cmp)(void *, void *)) {
    if (list == NULL) return NULL;
    if (list->first == NULL) return NULL;

    SingleListNode *node = list->first;

    int status = cmp(node->data, key);
    while (!status && node->next != NULL) {
        node = node->next;
        status = cmp(node->data, key);
    }

    if (status) {
        return node->data;
    } else {
        return NULL;
    }
}