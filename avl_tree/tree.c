#include "tree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
 * Returns the Node pointer to the taller child of the given Node. Returns
 * the left child if heights are equal.
 */
#define TALLER_CHILD(N)         ((HEIGHT((N)->left) < HEIGHT((N)->right)) \
                                    ? (N)->right : (N)->left)

/**
 * Updates the height of the given node to be 1 greater than the height of
 * its tallest child.
 */
#define UPDATE_HEIGHT(N)        ((N)->height = TALLER_CHILD(N) + 1)

typedef struct NodeStruct {
    int height;
    struct NodeStruct *parent;
    struct NodeStruct *left;
    struct NodeStruct *right;

    void *data;
} Node;

typedef struct TreeStruct {
    int (*compare)(void *this, void *other);
    Node *root;
} Tree;

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

Node *create_node(Node *parent) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    node->data = NULL;

    return node;
}

Node *trinode_restructure(Node *node) {

}

int test_node(Node *node, int height, Node *parent, Node *left, Node *right, void *data) {
    if (node->height != height || node->parent != parent || node->left != left 
        || node->right != right || strcmp((char *)node->data, (char *)data) != 0) {
            return 0;
    }
    return 1;
}

int main() {
    Node *n1 = create_node(NULL);
    Node *n2 = create_node(n1);
    n1->left = n2;
    Node *n3 = create_node(n2);
    n2->left = n3;
    
    n1->data = "carrot";
    n2->data = "banana";
    n3->data = "apple";

    assert(test_node(n1, 3, NULL, n2, NULL, "carrot"));
    assert(test_node(n2, 2, n1, n3, NULL, "banana"));
    assert(test_node(n3, 1, n2, NULL, NULL, "apple"));

    rotate_right(n3, n2);
    assert(test_node(n1, 3, NULL, n3, NULL, "carrot"));
    assert(test_node(n2, 2, n3, NULL, NULL, "banana"));
    assert(test_node(n3, 1, n1, NULL, n2, "apple"));
}