#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct NodeStruct {
    void *data;
    struct NodeStruct *next;
} Node;

typedef struct ListStruct {
    size_t size;
    Node *head;
    Node *tail;
} List;

/**
 * Creates and returns a pointer to a new List
 * @return Pointer to new List
 */
List *LIST_create();

/**
 * Deallocates all memory associated with the List.
 * @param list List to destroy
 * @param destroy function to deallocate data in each list node
 */
void LIST_destroy(List *list, void (*destroy)(void *data));

/**
 * Adds a new data element to the given List.
 * @param list List to add element to
 * @param data Data element to add
 */
void LIST_add(List *list, void *data);

/**
 * Simulates a for-each loop, performing the given 'action' function on each
 * data element of the list.
 * @param list List to loop through
 * @param action Function to perform on each data element of the list
 */
void LIST_process(List *list, void (*action)(void *data));

#endif