#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "../avl_tree/avl_tree.h"

/**
 * This hash table will use an avl tree as the secondary structure to 
 * resolve hashing collisions.
 */
typedef struct TableStruct {
    /** Array to hold avl trees of data elements */
    Tree (*table)[];
    /** Comparison function to pass to avl trees */
    int (*compare)(void *self, void *other);
} HashTable;

void *TABLE_add(HashTable *table, void *data);

#endif