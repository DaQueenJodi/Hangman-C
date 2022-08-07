#include "string.h"
#include </usr/include/string.h>
#include <stdlib.h>
#include <stdio.h>

char string_pop(string* s) {
        if (!s->index) {
                return 0; // nothing to pop!
        }
        char c = s->buffer[--s->index];
        s->buffer[--s->index] = 0;
        return c;
}

void string_push(string* s, char c) {
        s->buffer[s->index++] = c;
        if (s->index== s->capacity) {
                s->buffer = realloc(s->buffer, s->capacity  *= 2);
                memset(&s->buffer[s->index], 0, s->capacity - s->index);
        }
}

string string_from(char* characters) {
        char* t;
        string s = string_new();
        for (t = characters; *t != '\0'; t++) {
                string_push(&s, *t);
        }
        return s;
}

string string_new() {
        string s;
        s.capacity = 128;
        s.buffer = malloc(s.capacity);
        memset(s.buffer, 0, s.capacity);
        s.index = 0;
        return s;
}

