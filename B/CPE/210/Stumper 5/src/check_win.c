/*
** EPITECH PROJECT, 2023
** check_win.c
** File description:
** check_win
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool check_win(int round, int len, char *user_word, const char *word)
{
    if (strcmp(user_word, word) == 0) {
        printf("\n\nYou won!\n");
        return true;
    }
    if (round > len) {
        printf("\n\nYou lost!\n");
        return true;
    }
    return false;
}
