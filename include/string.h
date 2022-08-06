typedef struct {
        char* head; // last added item
        char* buffer; // start of the buffer
        int size;
        int capacity;
} String;


void string_append(String* s, char c);
char string_pop(String* s);
String string_new(String* s);
String string_from(char* characters);