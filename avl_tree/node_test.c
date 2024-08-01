#include "node.h"
#include <assert.h>
#include <stdlib.h>

void test_rotations() {
    Node *n1 = create_node(NULL);
    Node *n2 = create_node(n1);
    Node *n3 = create_node(n1);
    Node *n4 = create_node(n2);
    Node *n5 = create_node(n2);
    Node *n6 = create_node(n3);
    Node *n7 = create_node(n3);

    n1->height = 2;
    n2->height = 1;
    n3->height = 1;

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    rotate_right(n4, n2);

    assert(n1->left == n4);
    assert(n1->right == n3);
    assert(n4->left == NULL);
    assert(n4->right == n2);
    assert(n2->left == NULL);
    assert(n2->right == n5);
    assert(n2->parent == n4);
    assert(n4->parent == n1);

    assert(n5->height == 0);
    assert(n2->height == 1);
    assert(n4->height == 2);

    rotate_left(n7, n3);

    assert(n1->right == n7);
    assert(n1->left == n4);
    assert(n7->left == n3);
    assert(n7->right == NULL);
    assert(n3->left == n6);
    assert(n3->right == NULL);
    assert(n3->parent = n7);
    assert(n7->parent == n1);

    assert(n6->height == 0);
    assert(n3->height == 1);
    assert(n7->height == 2);
}

int main() {
    test_rotations();
}