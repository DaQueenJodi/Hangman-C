#pragma once

typedef struct {
        char* buffer; // start of the buffer
        unsigned int index; // index of last addded item
        unsigned int capacity;
} string;


string string_clone(string* s);
void string_push(string* s, char c);
char string_pop(string* s);
string string_new();
string string_from(char* characters);