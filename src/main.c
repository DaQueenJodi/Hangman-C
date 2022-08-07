#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "game.h"
#include <unistd.h>
#include </usr/include/string.h>

#define WORD "xnoe is a pogger"


// forward declarations because GCC is too retarded to read
void get_guess(string *s);
void fill_board(string *guess, Context *context);
bool check_completion(Context* context);

int main()
{
        string word = string_from(WORD);
        Context context = context_new(word);

        while (true)
        {
                if (!context.lives) { // out of lives
                        printf("You died :pensive:");
                        exit(0);
                }
                printf("you have %d lives left!\n", context.lives);
                printf("the hidden word is: %s \n", context.hidden_word.buffer);
                 if (check_completion(&context)) {
                        printf("Congratz! you won!");
                        exit(0);
                }
                printf("enter your guess: ");
                fflush(stdout);
                string guess_string = string_new();
                get_guess(&guess_string);
                printf("you guessed: %s \n", guess_string.buffer);
                fill_board(&guess_string, &context);
        }
}

void get_guess(string *s)
{ // returns true if it's multiple characters and false if it's only 1
        char c;
        while (true)
        {
                read(0, &c, 1); // read one byte at a time. it's slow but we aren't expecting a lot of input
                if (c == '\n')
                { // exit loop on newline
                        break;
                }
                string_push(s, c); // append character to string
        }
}

void fill_board(string *guess, Context *context)
{
        bool correct = false;

        string *board = &(context->hidden_word);
        string *real = &(context->real_word);

        string unchanged = string_clone(board);
        // if the guess is more than 1 character
        for (unsigned int i = 0; i < board->index; i++)
        {
                if (board->index - i < guess->index)
                { // if the guess doesnt fit in the remaining buffer, it cant possibly be correct
                        memcpy(board->buffer, unchanged.buffer, unchanged.capacity);
                        correct = false;
                        break;
                }
                if (real->buffer[i] == guess->buffer[0])
                { // search until you find a match on the first letter then....
                        for (unsigned int j = 0; j < guess->index; j++)
                        { // loop over the remaining buffer to see if the guess perfectly fits it
                                char c = guess->buffer[j];
                                if (real->buffer[i + j] == c)
                                {       correct = true;
                                        board->buffer[i + j] = guess->buffer[j];
                                }
                                else
                                {
                                        correct = false;
                                       // printf("compared: %d vs %c \n", real->buffer[i+j],  c);
                                        memcpy(board->buffer, unchanged.buffer, board->capacity); // reset board
                                        break;
                                       
                                }
                        }
                }
        }
        if (correct) {
                printf("Correct guess!\n");
        }
        else {
                printf("Incorrect!\n");
                context->lives--;
        }
}




bool check_completion(Context *context) {
        string real = context->real_word;
        string hidden = context->hidden_word;

        for (unsigned int i = 0; i < real.index; i++) {
                if (hidden.buffer[i] != real.buffer[i]) {
                        return false;
                }
        }
        return true;
}