#ifndef LOCATION_H
#define LOCATION_H

#include "../util/avl_tree/avl_tree.h"

/*

The game world will be represented as an adjacency-map graph using a 
hash table. Each location will have an avl tree (to maintain sorted order) 
of game objects and another of game characters. These two types 
(objects and characters) will be the root of an inheritance heirarchy with 
types representing more specific game objects and characters that have
particular effects in the game. Comparison functions will be written 
to take objects at the top level and then cast based on the enumerations
defined below.

Sorted order is important so that when messages are printed to the user,
game information is arranged into sensible categories.

*/

typedef enum { FOOD,
               RESOURCE,
               TERRAIN  } ObjectCategory;

typedef enum { STRANGER,
               FRIEND,
               IMP      } CharacterCategory;

typedef struct LocationStruct {
    /** Integer id for hashing */
    size_t id;
    /** GameObjects at this Location */
    Tree *objects;
    /** GameCharacters at this Location */
    Tree *characters;
} Location;

typedef struct GameObjectStruct {
    ObjectCategory category;
} GameObject;

typedef struct GameCharacterStruct {
    CharacterCategory category;
} GameCharacter;

#endif