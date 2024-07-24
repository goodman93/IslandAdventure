#include "avl_tree.h"
#include <assert.h>
#include <stdbool.h>

// PRIVATE

#define LEFT_HEIGHT(N)      (((N)->left) ? (N)->left->height : -1)
#define RIGHT_HEIGHT(N)     (((N)->right) ? (N)->right->height : -1)
#define MAX(A, B)           (((A) > (B)) ? (A) : (B))
#define MIN(A, B)           (((A) < (B)) ? (A) : (B))

Node *create_node(Node *parent) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->height = 0;
    node->data = NULL;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node *taller_child(Node *node) {
    size_t lh = 0;
    size_t rh = 0;
    if (node->left) {
        lh = node->left->height;
    }
    if (node->right) {
        rh = node->right->height;
    }

    return rh > lh ? node->right : node->left;
}

void rotate_left(Node *child, Node *parent) {
    
}

void rotate_right(Node *child, Node *parent) {

}

Node *restructure(Node *node) {
    Node *child = taller_child(node);
    Node *grandchild = taller_child(child);

    if (node->left == child) {
        if (child->left == grandchild) {

        } else {

        }
    } else {
        if (child->left == grandchild) {

        } else {

        }
    }
}

void rebalance(Node *node) {
    while (node) {
        if (MAX(LEFT_HEIGHT(node), RIGHT_HEIGHT(node)) - MIN(LEFT_HEIGHT(node), RIGHT_HEIGHT(node)) > 1) {
            node = restructure(node);
        } else {
            node = node->parent;
        }
    }
}

Node **find(AVLTree *tree, void *data, bool make) {
    Node **it = &tree->root;
    Node *parent = NULL;
    while ((*it) && tree->compare((*it)->data, data) != 0) {
        parent = (*it);
        if (tree->compare((*it)->data, data) < 0) {
            it = &((*it)->right);
        } else {
            it = &((*it)->left);
        }
    }

    if (make && (*it) == NULL) {
        *it = create_node(parent);
    }

    return it;
}

// PUBLIC

AVLTree *AVLTREE_create(int (*compare)(void *self, void *other)) {
    AVLTree *tree = (AVLTree *) malloc(sizeof(AVLTree));
    tree->compare = compare;
    tree->root = NULL;

    return tree;
}

void AVLTREE_destroy(AVLTree *tree, void (*destroy)(void *data));

void *AVLTree_get(AVLTree *tree, void *data);

void *AVLTree_add(AVLTree *tree, void *data) {
    Node **address = find(tree, data, true);
    void *old_data = (*address)->data;
    (*address)->data = data;

    if (!old_data) {
        rebalance((*address)->parent);
    }

    return old_data;
}

void *AVLTree_remove(AVLTree *tree, void *data);
