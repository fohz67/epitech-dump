/*
** EPITECH PROJECT, 2022
** my_strtok.c
** File description:
** my_strtok.c
*/

#include <stdio.h>
#include <string.h>

static int is_delimiter(char c, char d, const char* delim)
{
    while (*delim != '\0') {
        if (c == *delim && d == *delim) {
            return 1;
        }
        delim++;
    }
    return 0;
}

static char* skip_delimiters(char* str, const char* delim)
{
    int i = 0;

    while (str[i] != '\0' && is_delimiter(str[i], str[i + 1], delim)) {
        i++;
    }
    for (int j = 0; j < i; j++)
        str++;
    return str;
}

char* my_strtok(char* str, const char* delim)
{
    static char* last_token = NULL;
    char* token_start = NULL;
    int i = 0;

    if (str != NULL) last_token = str;
    if (last_token == NULL) return NULL;
    last_token = skip_delimiters(last_token, delim);
    if (*last_token == '\0') return NULL;
    token_start = last_token;
    while (last_token[i] != '\0' && !is_delimiter(last_token[i],
    last_token[i + 1], delim)) i++;
    for (int j = 0; j < i; j++) last_token++;
    i = 0;
    if (last_token[i] == '\0') {
        last_token = NULL;
    } else {
        last_token[i] = '\0';
        last_token++;
    }
    return token_start;
}
