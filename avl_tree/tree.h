#ifndef TREE_H
#define TREE_H

typedef struct TreeStruct Tree;

/**
 * Creates an instance of an AVL Tree and returns a pointer to it.
 * @param compare Function to compare data in the tree for finding 
 * and placing elements. Should return 0 if values are equal, > 0 if 
 * 'this' is greater, and < 0 if 'other' is greater.
 * @return Pointer to new AVL Tree
 */
Tree *create_tree(int (*comapre)(void *this, void *other));

/**
 * Adds the data element to the given tree, returning the data value
 * that had previously been held at that location in the tree, or NULL
 * if none.
 * @param tree Tree to add data element to
 * @param data Data element to add
 * @return Any element that had previously been held at the equivalent
 * location in the tree according to the tree's compare function.
 */
void *avl_add(Tree *tree, void *data);

#endif