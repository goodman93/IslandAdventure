#ifndef MAP_H
#define MAP_H

#include "../hash_table/hash_table.h"

typedef struct KVPairStruct {
    void *key;
    void *value;
} KVPair;

typedef struct MapStruct {
    HashTable table;
} Map;

/**
 * Creates and returns a pointer to a new Map.
 * @param compare Function to compare Key values in the KVMap. The function
 * should assume that the pointer is the same type as key.
 * @return Pointer to the new Map
 */
Map *MAP_create(int (*compare)(void *self, void *other));

void *MAP_put(Map *map, void *key, void *value);
void *MAP_remove(Map *map, void *key, void *value);

#endif