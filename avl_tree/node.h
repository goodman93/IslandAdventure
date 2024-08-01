#ifndef NODE_H
#define NODE_H

typedef struct NodeStruct {
    int height;
    struct NodeStruct *parent;
    struct NodeStruct *left;
    struct NodeStruct *right;

    void *data;
} Node;

/**
 * Creates a new dynamically allocated Node and returns its pointer. 
 * The Node's parent is set to the given Node pointer and the height is
 * set to 0. All other fields are initialized to NULL.
 * @param parent Parent of the Node being created (or NULL)
 * @return Pointer to the new Node
 */
Node *create_node(Node *parent);

/**
 * Rotate node a 'over' node b to the left. Node a must be the
 * right child of node b, and both nodes must be non null.
 * @param a Node to rotate up the tree
 * @param b Parent of a
 * @return Node a, now the root of the subtree
 */
Node *rotate_left(Node *a, Node *b);

/**
 * Rotate node a 'over' node b to the right. Node a must be the
 * left child of node b, and both nodes must be non null.
 * @param a Node to rotate up the tree
 * @param b Parent of a
 * @return Node a, now the root of the subtree
 */
Node *rotate_right(Node *a, Node *b);

#endif