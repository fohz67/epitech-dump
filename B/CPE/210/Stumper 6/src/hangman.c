/*
** EPITECH PROJECT, 2023
** hangman.c
** File description:
** main loop
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hangman.h"

static char *create_hide_word(const char *word)
{
    char *hide_word = NULL;
    int index = 0;

    hide_word = malloc(sizeof(char) * (my_strlen(word) + 1));
    if (hide_word == NULL) {
        return NULL;
    }
    while (word[index] != '\0') {
        hide_word[index] = '*';
        index++;
    }
    hide_word[index] = '\0';
    return (hide_word);
}

static void print_word(const char *word, int tries)
{
    printf("%s\nTries: %i\n\n", word, tries);
}

static bool update_hide_word(const char *word, char *hide_word, char letter)
{
    bool is_letter = false;

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == letter) {
            hide_word[i] = word[i];
            is_letter = true;
        }
    }
    if (is_letter == false) {
        printf("%c: is not in this word\n", letter);
    }
    return is_letter;
}

static bool is_win(const char *word, char *hide_word)
{
    if (strcmp(word, hide_word) == 0) {
        printf("Congratulations!\n");
        free(hide_word);
        return true;
    } else {
        return false;
    }
}

int hangman(const char *word, int tries)
{
    char letter = 'a';
    char *hide_word = NULL;

    hide_word = create_hide_word(word);
    if (hide_word == NULL)
        return 84;
    print_word(hide_word, tries);
    while (tries > 0) {
        letter = read_user();
        if (letter == -1)
            return 84;
        if (update_hide_word(word, hide_word, letter) == false)
            tries--;
        print_word(hide_word, tries);
        if (is_win(word, hide_word))
            return 0;
    }
    printf("You lost!\n");
    free(hide_word);
    return 0;
}
