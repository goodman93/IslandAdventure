#include "avl_tree.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int compare(void *self, void *other) {
    return strcmp((char *)self, (char *)other);
}

void test1(AVLTree *t) {
    AVLTree_add(t, "apple");
    
    Node *root = t->root;
    assert(root != NULL);
    assert(t->compare(root->data, "apple") == 0);
    assert(root->height == 0);
    assert(root->left == NULL);
    assert(root->right == NULL);
    assert(root->parent == NULL);

    AVLTree_add(t, "banana");

    Node *n1 = root->right;
    assert(t->compare(root->data, "apple") == 0);
    assert(root->height == 1);
    assert(root->left == NULL);
    assert(root->right == n1);
    assert(root->parent == NULL);

    assert(t->compare(n1->data, "banana") == 0);
    assert(n1->height == 0);
    assert(n1->left == NULL);
    assert(n1->right == NULL);
    assert(n1->parent == root);
}

int main() {
    AVLTree *t1 = AVLTREE_create(compare);
    assert(t1->root == NULL);

    test1(t1);
}