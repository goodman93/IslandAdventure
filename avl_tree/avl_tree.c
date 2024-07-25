#include "avl_tree.h"

// PRIVATE

Node *taller_child(Node *node) {
    size_t h1 = node->left->height;
    size_t h2 = node->right->height;
    return (h1 > h2) ? node->left : node->right;
}

size_t height_diff(Node *node) {
    size_t h1 = node->left->height;
    size_t h2 = node->right->height;
    return (h1 > h2) ? (h1 - h2) : (h2 - h1);
}

void rotate_left(Node *node) {
    Node *p = node->parent;

    node->parent = p->parent;
    p->parent = node;
    p->right = node->left;
    node->left = p;
    p->right->parent = p;
    node->left->parent = node;
}

void rotate_right(Node *node) {
    Node *p = node->parent;

    node->parent = p->parent;
    p->parent = node;
    p->left = node->right;
    node->right = p;
    p->left->parent = p;
    node->right->parent = node;
}

Node *restructure(Node *node) {
    Node *z = node;
    Node *y = taller_child(z);
    Node *x = taller_child(y);

    if (z->left == y) {
        if (y->left == x) {
            rotate_right(y);
            return y;
        } else {
            rotate_left(x);
            rotate_right(x);
            return x;
        }
    } else {
        if (y->left == x) {
            rotate_right(x);
            rotate_left(x);
            return x;
        } else {
            rotate_left(y);
            return y;
        }
    }
}

void balance(Node *node) {
    node->height = node->left->height + node->right->height + 1;
    if (height_diff(node) > 1) {
        node = restructure(node);
    }
    if (node->parent) {
        balance(node->parent);
    }
}

Node *find(Tree *t, void *data) {
    Node *it = t->root;
    while (it->data && t->compare(it->data, data)) {
        if (t->compare(it->data, data) < 0) {
            it = it->right;
        } else {
            it = it->left;
        }
    }

    return it;
}

Node *create_node(Node *parent) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->height = 0;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    node->data = NULL;

    return node;
}

// PUBLIC

Tree *AVL_create(int (*compare)(void *self, void *other)) {
    Tree *t = (Tree *) malloc(sizeof(Tree));
    t->compare = compare;
    t->root = create_node(NULL);

    return t;
}

void *AVL_add(Tree *t, void *data) {
    Node *node = find(t, data);
    void *old_data = node->data;
    node->data = data;

    if (!old_data) {
        node->left = create_node(node);
        node->right = create_node(node);
        balance(node);
    }

    return old_data;
}

void *AVL_remove(Tree *t, void *data);

void *AVL_get(Tree *t, void *data);
