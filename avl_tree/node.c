#include "node.h"
#include <stdlib.h>
#include <assert.h>

/**
 * Returns the absolute value of the given value.
 */
#define ABS(A)                  ((A) < 0 ? -(A) : (A))

/**
 * Returns true if the given node is the left child of its parent.
 * Check that parent is non null before passing.
 */
#define IS_LEFT_CHILD(N)        (((N)->parent->left == (N)) ? 1 : 0)

/**
 * Returns the height of the given node. Null nodes return -1.
 */
#define HEIGHT(N)               ((N) ? (N)->height : -1)

/**
 * Returns the difference in heights of the two child nodes of the 
 * given node.
 */
#define HEIGHT_DIFF(N)          (ABS(HEIGHT((N)->left) - HEIGHT((N)->right)))

/**
 * Returns the Node pointer to the taller child of the given Node. Returns
 * the left child if heights are equal.
 */
#define TALLER_CHILD(N)         ((HEIGHT((N)->left) < HEIGHT((N)->right)) \
                                    ? (N)->right : (N)->left)

/**
 * Updates the height of the given node to be 1 greater than the height of
 * its tallest child.
 */
#define UPDATE_HEIGHT(N)        ((N)->height = HEIGHT(TALLER_CHILD(N)) + 1)

Node *rotate_left(Node *a, Node *b) {
    assert(b->right == a);
    if (b->parent) {
        if (IS_LEFT_CHILD(b)) {
            b->parent->left = a;
        } else {
            b->parent->right = a;
        }
    }

    a->parent = b->parent;
    b->parent = a;
    b->right = a->left;
    if (a->left) {
        a->left->parent = b;
    }
    a->left = b;

    UPDATE_HEIGHT(b);
    UPDATE_HEIGHT(a);

    return a;
}

Node *rotate_right(Node *a, Node *b) {
    assert(b->left == a);
    if (b->parent) {
        if (IS_LEFT_CHILD(b)) {
            b->parent->left = a;
        } else {
            b->parent->right = a;
        }
    }

    a->parent = b->parent;
    b->parent = a;
    b->left = a->right;
    if (a->right) {
        a->right->parent = b;
    }
    a->right = b;

    UPDATE_HEIGHT(b);
    UPDATE_HEIGHT(a);

    return a;
}

Node *create_node(Node *parent) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    node->data = NULL;
    node->height = 0;

    return node;
}

Node *trinode_restructure(Node *node) {

}

void balance(Node *node) {
    do {
        UPDATE_HEIGHT(node);
        if 
    }
}
