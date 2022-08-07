#pragma once
#include <stdbool.h>
#include "string.h"

typedef struct {
        unsigned int lives;
        string real_word;
        string hidden_word;
        bool running;
} Context;

Context context_new(string word);