#pragma once

typedef struct {
        char* buffer; // start of the buffer
        int index; // index of last addded item
        int capacity;
} string;


void string_push(string* s, char c);
char string_pop(string* s);
string string_new();
string string_from(char* characters);