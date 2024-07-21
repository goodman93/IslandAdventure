#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>

typedef struct StringStruct {
    /** Total size of the underlying array */
    size_t capacity;
    /** Number of characters in the string (or index of the null terminator) */
    size_t length;
    /** Char array of characters in the string */
    char *text;
} String;

/**
 * Allocates a resizeable TextString on the heap and returns a pointer
 * to it.
 * @return string A pointer to a TextString
 */
String *STRING_create();

/**
 * Deallocates all memory associated with the given String s.
 * @param s String to deallocate
 */
void STRING_destroy(String *s);

/** 
 * Appends the text in the character array 'append' to the end of the 
 * given String s.
 * @param s Pointer to String to append text to
 * @param append char array of text to append to the given String
 */
void STRING_append(String *s, char *append);

/**
 * Appends the char 'ch' to the end of the given String.
 * @param s String to append the char 'ch' to
 * @param ch Character to append to the String s
 */
void STRING_push(String *s, char ch);

#endif