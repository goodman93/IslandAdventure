#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdlib.h>

typedef struct NodeStruct {
    size_t height;
    struct NodeStruct *parent;
    struct NodeStruct *left;
    struct NodeStruct *right;

    void *data;
} Node;

typedef struct TreeStruct {
    Node *root;
    int (*compare)(void *self, void *other);
} Tree;

Tree *AVL_create(int (*compare)(void *self, void *other));
void *AVL_add(Tree *t, void *data);
void *AVL_remove(Tree *t, void *data);
void *AVL_get(Tree *t, void *data);

#endif