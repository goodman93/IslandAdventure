#include "list.h"

// PRIVATE

Node *create_node() {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = NULL;
    node->next = NULL;

    return node;
}

// PUBLIC

List *LIST_create() {
    List *list = (List *) malloc(sizeof(List));
    list->size = 0;
    list->head = create_node();
    list->tail = create_node();

    list->head->next = list->tail;

    return list;
}

void LIST_destroy(List *list, void (*destroy)(void *data));

void LIST_add(List *list, void *data) {
    Node *node = create_node();
    node->data = data;

    list->tail->next = node;
    list->tail = node;
    list->size++;
}

void LIST_process(List *list, void (*action)(void *data)) {
    Node *it = list->head;
    while (it) {
        action(it->data);
        it = it->next;
    }
}