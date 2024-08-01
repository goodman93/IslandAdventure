#ifndef NODE_H
#define NODE_H

typedef struct AVLNodeStruct {
    int height;
    struct AVLNodeStruct *parent;
    struct AVLNodeStruct *left;
    struct AVLNodeStruct *right;

    void *data;
} AVLNode;

/**
 * Creates a new dynamically allocated Node and returns its pointer. 
 * The Node's parent is set to the given Node pointer and the height is
 * set to 0. All other fields are initialized to NULL.
 * @param parent Parent of the Node being created (or NULL)
 * @return Pointer to the new Node
 */
AVLNode *create_node(AVLNode *parent);

/**
 * Iteratively checks the balance of each node all the way up to the root 
 * node, restructuring wherever there are height imbalances.
 * @param node First node to balance
 */
void balance(AVLNode *node);

#endif