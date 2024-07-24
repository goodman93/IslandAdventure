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

typedef struct AVLTreeStruct {
    int (*compare)(void *self, void *other);
    Node *root;
} AVLTree;

AVLTree *AVLTREE_create(int (*compare)(void *self, void *other));
void AVLTREE_destroy(AVLTree *tree, void (*destroy)(void *data));
void *AVLTree_get(AVLTree *tree, void *data);
void *AVLTree_add(AVLTree *tree, void *data);
void *AVLTree_remove(AVLTree *tree, void *data);

#endif