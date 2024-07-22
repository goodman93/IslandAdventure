#include "avl_tree.h"
#include <assert.h>

// PRIVATE

#define ABS(A)  ((A < 0) ? (A) : (-(A)))
#define MAX(A, B) ((A > B) ? (A) : (B))

Node *tallest_child(Node *node) {
    if (node->left->height > node->right->height) {
        return node->left;
    } else {
        return node->right;
    }
}

void set_height(Node *node) {
    node->height = MAX(node->left->height, node->right->height) + 1;
}

void rotate_left(Node *node) {
    Node *parent = node->parent;
    assert(parent->right == node);

    parent->right = node->left;
    node->left = parent;
    node->parent = parent->parent;
    parent->parent = node;

    set_height(parent);
    set_height(node);
}

void rotate_right(Node *node) {
    Node *parent = node->parent;
    assert(parent->left == node);

    parent->left = node->right;
    node->right = parent;
    node->parent = parent->parent;
    parent->parent = node;

    set_height(parent);
    set_height(node);
}

Node *restructure(Node *node) {
    Node *child = tallest_child(node);
    Node *grandchild = tallest_child(child);

    if (node->left == child) {
        if (child->left == grandchild) {
            rotate_right(child);
            return child;
        } else {
            rotate_left(grandchild);
            rotate_right(grandchild);
            return grandchild;
        }
    } else {
        if (child->left == grandchild) {
            rotate_right(grandchild);
            rotate_left(grandchild);
            return grandchild;
        } else {
            rotate_left(child);
            return child;
        }
    }
}

void balance(Node *node) {
    while (node->parent != NULL) {
        node = node->parent;
        if (ABS(node->left->height - node->right->height) > 1) {
            node = restructure(node);
        } 
    }
}

Node *create_node(Node *parent) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = NULL;
    node->height = 0;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node *find(AVLTree *tree, Node **start, void *data) {
    Node *node = (*start);
    while ((*start) && tree->compare((*start)->data, data) != 0) {
        node = (*start);
        if (tree->compare((*start)->data, data) < 0) {
            start = &(*start)->right;
        } else {
            start = &(*start)->left;
        }
    }

    return node;
}

// PUBLIC

AVLTree *AVLTREE_create(int (*compare)(void *self, void *other)) {
    AVLTree *tree = (AVLTree *) malloc(sizeof(AVLTree));
    tree->compare = compare;
    tree->root = NULL;

    return tree;
}

void AVLTREE_destroy(void (*destroy)(void *data));

void *AVLTree_get(AVLTree *tree, void *data) {
    Node **it = &tree->root;
    find(tree, it, data);
    if (*it) {
        return (*it)->data;
    }

    return NULL;
}

void *AVLTree_add(AVLTree *tree, void *data) {
    Node **it = &tree->root;
    Node *parent = find(tree, it, data);

    if (*it) {
        void *old_data = (*it)->data;
        (*it)->data = data;
        return data;
    }

    (*it) = create_node(parent);
    (*it)->data = data;
    balance(*it);

    return NULL;
}

void *AVLTree_remove(AVLTree *tree, void *data);
