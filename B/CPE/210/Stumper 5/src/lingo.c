/*
** EPITECH PROJECT, 2023
** lingo.c
** File description:
** lingo.c
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "lingo.h"

static char *create_hide_word(int len, const char *word)
{
    char *hide_word = NULL;

    hide_word = malloc(sizeof(char) * (len + 1));
    if (hide_word == NULL)
        return NULL;
    for (int i = 0; i < len; i++) {
        hide_word[i] = '*';
    }
    hide_word[0] = word[0];
    hide_word[len] = '\0';
    return hide_word;
}

static void check_letter(char *hide_word, const char *word,
const char letter, int i)
{
    for (int j = 0; word[j] != '\0'; j++) {
        if (letter == word[j] && j != i) {
            hide_word[i] = '?';
            return;
        }
    }
    return;
}

static int print_hide_word(char *user_word, const char *word, int len)
{
    char *hide_word = NULL;

    hide_word = create_hide_word(len, word);
    if (hide_word == NULL) {
        return 84;
    }
    for (int i = 0; i < len; i++) {
        if (user_word[i] == word[i]) {
            hide_word[i] = word[i];
        } else {
            check_letter(hide_word, word, user_word[i], i);
        }
    }
    printf("%s", hide_word);
    free(hide_word);
    return 0;
}

static int check_word(char *user_word, const char *word, int len,
int *verif)
{
    int user_len = 0;

    user_len = my_strlen(user_word);
    if (user_len < len) {
        printf("Word too short. Retry.\n");
        return 1;
    }
    if (user_len > len) {
        printf("Word too long. Retry.\n");
        return 1;
    }
    if (print_hide_word(user_word, word, len) == 84) {
        free(user_word);
        return 84;
    }
    verif[1] += 1;
    return 0;
}

int lingo(const char *word, int len)
{
    int verif[2] = {1, 1};
    int result_check_word = 0;
    char *user_word = NULL;

    while (1) {
        if ((user_word = init_round(verif)) == NULL)
            return 84;
        result_check_word = check_word(user_word, word, len, verif);
        if (result_check_word == 84)
            return 84;
        if (result_check_word == 0)
            verif[0] = 1;
        if (check_win(verif[1], len, user_word, word)) {
            free(user_word);
            return 0;
        }
        free(user_word);
    }
    return 0;
}
