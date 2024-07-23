#include "avl_tree.h"
#include <assert.h>

#define HEIGHT(N)           ((N) ? (N)->height : -1)
#define MAX(A, B)           (((A) > (B)) ? (A) : (B))
#define MIN(A, B)           (((A) < (B)) ? (A) : (B))
#define TALLER_CHILD(N)     ((HEIGHT((N)->left)) > (HEIGHT((N)->right)) ? (N)->left : (N)->right)

void rotate_left(Node *node) {
    Node *parent = NODE_PARENT(node);
    assert(NODE_RIGHT(parent) == node);

    NODE_PARENT(node) = NODE_PARENT(parent);
    NODE_PARENT(parent) = node;
    NODE_RIGHT(parent) = NODE_LEFT(node);
    NODE_LEFT(node) = parent;

    parent->height = HEIGHT(TALLER_CHILD(parent)) + 1;
    node->height = HEIGHT(TALLER_CHILD(node)) + 1;
}

void rotate_right(Node *node) {
    Node *parent = NODE_PARENT(node);
    assert(NODE_LEFT(parent) == node);

    NODE_PARENT(node) = NODE_PARENT(parent);
    NODE_PARENT(parent) = node;
    NODE_LEFT(parent) = NODE_RIGHT(node);
    NODE_RIGHT(node) = parent;

    parent->height = TALLER_CHILD(parent)->height + 1;
    node->height = TALLER_CHILD(node)->height + 1;
}

Node *restructure(Node *node) {
    Node *child = TALLER_CHILD(node);
    Node *grandchild = TALLER_CHILD(child);

    if (NODE_LEFT(node) == child) {
        if (NODE_LEFT(child) == grandchild) {
            rotate_right(child);
            return child;
        } else {
            rotate_left(grandchild);
            rotate_right(grandchild);
            return grandchild;
        }
    } else {
        if (NODE_LEFT(child) == grandchild) {
            rotate_right(grandchild);
            rotate_left(grandchild);
            return grandchild;
        } else {
            rotate_left(child);
            return child;
        }
    }
}

Node *AVLTREE_create_node(Node *parent, Node *left, Node *right) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->height = 0;
    node->parent = parent;
    node->left = left;
    node->right = right;

    return node;
}

AVLTree *AVLTREE_create_tree() {
    AVLTree *tree = (AVLTree *) malloc(sizeof(AVLTree));
    tree->root = NULL;

    return tree;
}

void rebalance(Node *node) {
    while (!NODE_ROOT(node)) {
        if (MAX(HEIGHT(node->left), HEIGHT(node->right)) - MIN(HEIGHT(node->left), HEIGHT(node->right)) > 1) {
            restructure(node);
        }
        node = NODE_PARENT(node);
    }
}