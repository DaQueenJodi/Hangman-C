#include <stdbool.h>

typedef struct {
        const char* real_word;
        char* hidden_word;
        bool running;
} Context;

Context context_new(const char* word);