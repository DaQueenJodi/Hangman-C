#include "game.h"
#include "string.h"
#include "util.h"

Context context_new(string word) {
        Context c;
        c.lives = 5;
        c.running = false;
        c.real_word = word;
        c.hidden_word = gen_hidden_word(word);
        return c;
}
