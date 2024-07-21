#include "string.h"
#include <stdlib.h>
#include <string.h>

// PRIVATE

#define INIT_CAPACITY 10
#define RESIZE_FACTOR 2

void resize(String *s) {
    s->capacity *= RESIZE_FACTOR;
    s->text = (char *) realloc(s->text, s->capacity * sizeof(char));
}

// PUBLIC


String *STRING_create() {
    String *string = (String *) malloc(sizeof(String));
    string->text = (char *) malloc(sizeof(char) * INIT_CAPACITY);
    string->text[0] = '\0';
    string->capacity = INIT_CAPACITY;
    string->length = 0;

    return string;
}

void STRING_destroy(String *s) {
    free(s->text);
    free(s);
}

void STRING_push(String *s, char ch) {
    if (s->capacity - s->length - 1 < 1) {
        resize(s);
    }

    s->text[s->length++] = ch;
    s->text[s->length] = '\0';
}

void STRING_append(String *s, char *append) {
    size_t size = strlen(append);

    for (size_t i = 0; i < size; i++) {
        STRING_push(s, append[i]);
    }
}
