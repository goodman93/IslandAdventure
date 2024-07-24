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
    if (!(node->left) && !(node->right)) {
        return NULL;
    } else if (node->left && !(node->right)) {
        return node->left;
    } else if (!(node->left) && node->right) {
        return node->right;
    } else {
        return (node->right > node->left) ? (node->right) : (node->left);
    } 
}

size_t height_diff(Node *node) {
    if (node->left) {
        if (node->right) {
            return node->left->height - node->right->height;
        } else {
            return node->left->height + 1;
        }
    } else if (node->right) {
        return node->right->height + 1;
    } else {
        return 0;
    }
}

void update_height(Node *node) {
    Node *taller = taller_child(node);
    if (taller) {
        node->height = taller->height + 1;
    } else {
        node->height = 0;
    }
}

void rotate_left(Node *child, Node *parent) {
    if (parent->parent) {
        if (parent->parent->left == parent) {
            parent->parent->left = child;
        } else {
            parent->parent->right = child;
        }
    }

    child->parent = parent->parent;
    parent->parent = child;

    parent->right = child->left;
    child->left = parent;

    parent->right->parent = parent;
    child->left->parent = child;

    update_height(parent);
    update_height(child);
}

void rotate_right(Node *child, Node *parent) {
    if (parent->parent) {
        if (parent->parent->left == parent) {
            parent->parent->left = child;
        } else {
            parent->parent->right = child;
        }
    }

    child->parent = parent->parent;
    parent->parent = child;

    parent->left = child->right;
    child->right = parent;

    parent->left->parent = parent;
    child->right->parent = child;

    update_height(parent);
    update_height(child);
}

Node *restructure(Node *node) {
    Node *child = taller_child(node);
    Node *grandchild = taller_child(child);

    if (node->left == child) {
        if (child->left == grandchild) {
            rotate_right(child, node);
            return child;
        } else {
            rotate_left(grandchild, child);
            rotate_right(grandchild, node);
            return grandchild;
        }
    } else {
        if (child->left == grandchild) {
            rotate_right(grandchild, child);
            rotate_left(grandchild, node);
            return grandchild;
        } else {
            rotate_left(child, node);
            return child;
        }
    }
}

void rebalance(Node *node) {
    while (node) {
        update_height(node);
        if (height_diff(node) > 1) {
            node = restructure(node);
        }
        node = node->parent;
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
