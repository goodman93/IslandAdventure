#include "string.h"
#include <assert.h>
#include <string.h>

void test1(String *s) {
    STRING_push(s, 'a');
    assert(s->length == 1);
    assert(s->capacity == 10);
    assert(s->text[1] == '\0');

    STRING_push(s, 'b');
    assert(s->length == 2);
    assert(s->capacity == 10);
    assert(s->text[2] == '\0');
    
    STRING_push(s, 'c');
    assert(s->length == 3);
    assert(s->capacity == 10);
    assert(s->text[3] == '\0');

    STRING_push(s, 'd');
    assert(s->length == 4);
    assert(s->capacity == 10);
    assert(s->text[4] == '\0');

    STRING_push(s, 'e');
    assert(s->length == 5);
    assert(s->capacity == 10);
    assert(s->text[5] == '\0');

    STRING_push(s, 'f');
    assert(s->length == 6);
    assert(s->capacity == 10);
    assert(s->text[6] == '\0');
    
    STRING_push(s, 'g');
    assert(s->length == 7);
    assert(s->capacity == 10);
    assert(s->text[7] == '\0');

    STRING_push(s, 'h');
    assert(s->length == 8);
    assert(s->capacity == 10);
    assert(s->text[8] == '\0');

    STRING_push(s, 'i');
    assert(s->length == 9);
    assert(s->capacity == 10);
    assert(s->text[9] == '\0');

    STRING_push(s, 'j');
    assert(s->length == 10);
    assert(s->capacity == 20);
    assert(s->text[10] == '\0');

    STRING_push(s, 'k');
    assert(s->length == 11);
    assert(s->capacity == 20);
    assert(s->text[11] == '\0');
    
    assert(s->text[0] == 'a');
    assert(s->text[1] == 'b');
    assert(s->text[2] == 'c');
    assert(s->text[3] == 'd');
    assert(s->text[4] == 'e');
    assert(s->text[5] == 'f');
    assert(s->text[6] == 'g');
    assert(s->text[7] == 'h');
    assert(s->text[8] == 'i');
    assert(s->text[9] == 'j');
    assert(s->text[10] == 'k');
}

void test2(String *s) {
    STRING_append(s, "lmnopqrstuvwxyz");

    assert(s->text[0] == 'a');
    assert(s->text[1] == 'b');
    assert(s->text[2] == 'c');
    assert(s->text[3] == 'd');
    assert(s->text[4] == 'e');
    assert(s->text[5] == 'f');
    assert(s->text[6] == 'g');
    assert(s->text[7] == 'h');
    assert(s->text[8] == 'i');
    assert(s->text[9] == 'j');
    assert(s->text[10] == 'k');
    assert(s->text[11] == 'l');
    assert(s->text[12] == 'm');
    assert(s->text[13] == 'n');
    assert(s->text[14] == 'o');
    assert(s->text[15] == 'p');
    assert(s->text[16] == 'q');
    assert(s->text[17] == 'r');
    assert(s->text[18] == 's');
    assert(s->text[19] == 't');
    assert(s->text[20] == 'u');
    assert(s->text[21] == 'v');
    assert(s->text[22] == 'w');
    assert(s->text[23] == 'x');
    assert(s->text[24] == 'y');
    assert(s->text[25] == 'z');
    assert(s->text[26] == '\0');
    assert(s->capacity == 40);
    assert(s->length = 26);
}

int main() {
    String *s1 = STRING_create();
    assert(strlen(s1->text) == 0);
    assert(s1->length == 0);
    assert(s1->capacity == 10);
    printf("Initialization Successful\n");

    test1(s1);
    printf("Test 1 Successful\n");

    test2(s1);
    printf("Test 2 Successful\n");

    STRING_destroy(s1);
}