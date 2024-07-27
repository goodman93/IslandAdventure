#ifndef LOCATION_H
#define LOCATION_H

#include "../util/avl_tree/avl_tree.h"

/*

The game world will be represented as an adjacency-map graph using a 
hash table. Each location will have an avl tree (to maintain sorted order) 
of game objects and another of game characters. These two types 
(objects and characters) will be the root of an inheritance heirarchy with 
objects representing more specific game objects and characters that have
particular affects in the game. Comparison functions will be written 
to take objects at the top level and then cast based on the enumerations
defined below.

*/

typedef enum { FOOD,
               RESOURCE,
               TERRAIN  } ObjectCategory;

typedef enum {} CharacterCategory;

typedef struct LocationStruct {
    /** Integer id for hashing */
    size_t id;
    Tree *objects;
    Tree *characters;
} Location;

typedef struct GameObjectStruct {
    ObjectCategory category;
} GameObject;

typedef struct GameCharacterStruct {
    CharacterCategory category;
} GameCharacter;

#endif