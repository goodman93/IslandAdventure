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
 * Iteratively checks the balance of each node all the way up to the root 
 * node, restructuring wherever there are height imbalances.
 * @param node First node to balance
 */
void balance(Node *node);
Node *restructure(Node *node);
Node *rotate_left(Node *a, Node *b);
Node *rotate_right(Node *a, Node *b);

#endif