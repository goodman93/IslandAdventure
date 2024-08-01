#include "avl_node.h"
#include "tree.h"
#include <stdlib.h>

typedef struct TreeStruct {
    int (*compare)(void *this, void *other);
    AVLNode *root;
} Tree;

/**
 * Searches the given tree for the data element using the tree's compare
 * function. If the given data element does not exist in the tree, it will
 * return the last leaf node that was compared in the search. If the tree
 * is empty it returns NULL.
 * @param tree Tree to search
 * @param data Data element to search for
 * @return The node containing the given data element, the last leaf node 
 * evaluated during the search, or NULL if the tree is empty.
 */
AVLNode *find(Tree *tree, void *data) {
    AVLNode *node = tree->root;
    while (node) {
        if (tree->compare(node->data, data) < 0 && node->right) {
            node = node->right;
        } else if (tree->compare(node->data, data) > 0 && node->left) {
            node = node->left;
        } else {
            return node;
        }
    }

    return NULL;
}

Tree *create_tree(int (*comapre)(void *this, void *other)) {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->compare = comapre;
    tree->root = NULL;
}

void *avl_add(Tree *tree, void *data) {
    AVLNode *node = find(tree, data);
    AVLNode *old_data = NULL;

    if (tree->compare(node->data, data) == 0) {
        old_data = node->data;
        node->data = data;
    } else if (tree->compare(node->data, data) < 0) {
        node->right = create_node(node);
        node->right->data = data;
        balance(node);
    } else {
        node->left = create_node(node);
        node->left->data = data;
        balance(node);
    }

    return old_data;
}