#include "avl_tree.h"
#include <assert.h>
#include <string.h>

int compare(void *s, void *o) {
    return strcmp((char *)s, (char *)o);
}

void test_add(Tree *t) {
    Node *root = t->root;

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

    AVL_add(t, "almond");
    Node *n3 = n1->left;

    assert(t->compare(root->data, "banana") == 0);
    assert(root->height == 3);
    assert(root->left == n1);
    assert(root->right == n2);
    assert(root->parent == NULL);

    assert(t->compare(n1->data, "apple") == 0);
    assert(n1->height == 2);
    assert(n1->left == n3);
    assert(n1->right != NULL);
    assert(n1->parent == root);

    assert(t->compare(n2->data, "carrot") == 0);
    assert(n2->height == 1);
    assert(n2->left != NULL);
    assert(n2->right != NULL);
    assert(n2->parent == root);

    assert(t->compare(n3->data, "almond") == 0);
    assert(n3->height == 1);
    assert(n3->left != NULL);
    assert(n3->right != NULL);
    assert(n3->parent == n1);

    AVL_add(t, "apricot");
    Node *n4 = n1->right;

    assert(t->compare(root->data, "banana") == 0);
    assert(root->height == 3);
    assert(root->left == n1);
    assert(root->right == n2);
    assert(root->parent == NULL);

    assert(t->compare(n1->data, "apple") == 0);
    assert(n1->height == 2);
    assert(n1->left == n3);
    assert(n1->right == n4);
    assert(n1->parent == root);

    assert(t->compare(n2->data, "carrot") == 0);
    assert(n2->height == 1);
    assert(n2->left != NULL);
    assert(n2->right != NULL);
    assert(n2->parent == root);

    assert(t->compare(n3->data, "almond") == 0);
    assert(n3->height == 1);
    assert(n3->left != NULL);
    assert(n3->right != NULL);
    assert(n3->parent == n1);

    assert(t->compare(n4->data, "apricot") == 0);
    assert(n4->height == 1);
    assert(n4->left != NULL);
    assert(n4->right != NULL);
    assert(n4->parent == n1);

    AVL_add(t, "aqua");
    root = t->root;
    n1 = root->left;
    n2 = root->right;
    n3 = n1->left;
    n4 = n2->left;
    Node *n5 = n2->right;

    assert(t->compare(root->data, "apricot") == 0);
    assert(root->height == 3);
    assert(root->left == n1);
    assert(root->right == n2);
    assert(root->parent == NULL);

    assert(t->compare(n1->data, "apple") == 0);
    assert(n1->height == 2);
    assert(n1->left == n3);
    assert(n1->right != NULL);
    assert(n1->parent == root);

    assert(t->compare(n2->data, "banana") == 0);
    assert(n2->height == 2);
    assert(n2->left == n4);
    assert(n2->right == n5);
    assert(n2->parent == root);

    assert(t->compare(n3->data, "almond") == 0);
    assert(n3->height == 1);
    assert(n3->left != NULL);
    assert(n3->right != NULL);
    assert(n3->parent == n1);

    assert(t->compare(n4->data, "aqua") == 0);
    assert(n4->height == 1);
    assert(n4->left != NULL);
    assert(n4->right != NULL);
    assert(n4->parent == n2);

    assert(t->compare(n5->data, "carrot") == 0);
    assert(n5->height == 1);
    assert(n5->left != NULL);
    assert(n5->right != NULL);
    assert(n5->parent == n2);
}

int main() {
    Tree *t = AVL_create(compare);
    Node *root = t->root;
    assert(root->data == NULL);
    assert(root->height == 0);
    assert(root->left == NULL);
    assert(root->right == NULL);
    assert(root->parent == NULL);

    test_add(t);
}