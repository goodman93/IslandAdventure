#include "avl_tree.h"
#include <assert.h>
#include <string.h>

int compare(void *s, void *o) {
    return strcmp((char *)s, (char *)o);
}

int main() {
    Tree *t = AVL_create(compare);
    Node *root = t->root;
    assert(root->data == NULL);
    assert(root->height == 0);
    assert(root->left == NULL);
    assert(root->right == NULL);
    assert(root->parent == NULL);

    AVL_add(t, "apple");
    assert(t->compare(root->data, "apple") == 0);
    assert(root->height == 1);
    assert(root->left != NULL);
    assert(root->right != NULL);
    assert(root->parent == NULL);

    AVL_add(t, "banana");
    Node *n1 = root->right;
    assert(t->compare(root->data, "apple") == 0);
    assert(root->height == 2);
    assert(root->left != NULL);
    assert(root->right == n1);
    assert(root->parent == NULL);

    assert(t->compare(n1->data, "banana") == 0);
    assert(n1->height == 1);
    assert(n1->left != NULL);
    assert(n1->right != NULL);
    assert(n1->parent == root);

    AVL_add(t, "carrot");
    root = t->root;
    n1 = root->left;
    Node *n2 = root->right;

    assert(t->compare(root->data, "banana") == 0);
    assert(root->height == 2);
    assert(root->left == n1);
    assert(root->right == n2);
    assert(root->parent == NULL);

    assert(t->compare(n1->data, "apple") == 0);
    assert(n1->height == 1);
    assert(n1->left != NULL);
    assert(n1->right != NULL);
    assert(n1->parent == root);

    assert(t->compare(n2->data, "carrot") == 0);
    assert(n2->height == 1);
    assert(n2->left != NULL);
    assert(n2->right != NULL);
    assert(n2->parent == root);
}