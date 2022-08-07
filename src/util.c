#include "string.h"
#include "util.h"

string gen_hidden_word(string word) {
        string hidden_word = string_new();
        for (unsigned int i = 0; i < word.index; i++) {
                if (word.buffer[i] == ' ') { // if space:
                        string_push(&hidden_word, ' '); // insert a space
                }
                else {
                        string_push(&hidden_word, '_'); // add underscore to represent a hidden character
                }

        }
        return hidden_word;
}