#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdlib.h>

typedef struct NodeStruct {
    size_t height;
    struct NodeStruct *parent;
    struct NodeStruct *left;
    struct NodeStruct *right;
} Node;

typedef struct AVLTreeStruct {
    Node *root;
} AVLTree;

#define NODE_LEFT(N)    ((N)->left)
#define NODE_RIGHT(N)   ((N)->right)
#define NODE_PARENT(N)  ((N)->parent)
#define NODE_ROOT(N)         ((((N)->parent) == NULL) ? 1 : 0)

Node *AVLTREE_create_node(Node *parent, Node *left, Node *right);

/**
 * Rebalances the subtree rooted at the given node and returns the new
 * root of the subtree.
 * @param node The root of the subtree that needs to be restructured
 * @return The new root of the subtree
 */
Node *AVLTREE_restructure(Node *node);

AVLTree *AVLTREE_create_tree();

#endif