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

/**
 * Rotate node a 'over' node b to the left. Node a must be the
 * right child of node b, and both nodes must be non null.
 * @param a Node to rotate up the tree
 * @param b Parent of a
 * @return Node a, now the root of the subtree
 */
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

/**
 * Rotate node a 'over' node b to the right. Node a must be the
 * left child of node b, and both nodes must be non null.
 * @param a Node to rotate up the tree
 * @param b Parent of a
 * @return Node a, now the root of the subtree
 */
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

/**
 * Balances the subtree rooted at the given node by calling 
 * left and right rotations. Returns the new root of the subtree.
 * @param node Root of the subtree to restructure
 * @return Pointer to the root of the subtree after restructure
 */
Node *restructure(Node *node) {
    Node *z = node;
    Node *y = TALLER_CHILD(z);
    Node *x = TALLER_CHILD(y);

    if (IS_LEFT_CHILD(y)) {
        if (IS_LEFT_CHILD(x)) {
            return rotate_right(y, z);
        } else {
            return rotate_right(rotate_left(x, y), z);
        }
    } else {
        if (IS_LEFT_CHILD(x)) {
            return rotate_left(rotate_right(x, y), z);
        } else {
            return rotate_left(y, z);
        }
    }
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

void balance(Node *node) {
    while (node->parent) {
        UPDATE_HEIGHT(node);
        if (HEIGHT_DIFF(node) > 1) {
            node = restructure(node);
        } else {
            node = node->parent;
        }
    }

    assert(node->parent == NULL);
    UPDATE_HEIGHT(node);
    if (HEIGHT_DIFF(node) > 1) {
        restructure(node);
    }
}
