#pragma once
#include <stdbool.h>
#include "string.h"

typedef struct {
        string real_word;
        string hidden_word;
        bool running;
} Context;

Context context_new(string word);