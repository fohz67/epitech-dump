/*
** EPITECH PROJECT, 2023
** my_strtok.c
** File description:
** my_strtok.c
*/

#include <stdio.h>
#include <string.h>

static int is_delimiter(char c, const char* delim)
{
    while (*delim != '\0') {
        if (c == *delim) {
            return 1;
        }
        delim++;
    }
    return 0;
}

static char* skip_delimiters(char* str, const char* delim)
{
    while (*str != '\0' && is_delimiter(*str, delim)) {
        str++;
    }
    return str;
}

char* my_strtok(char* str, const char* delim)
{
    static char* last_token = NULL;
    char* token_start = NULL;

    if (str != NULL)
        last_token = str;
    if (last_token == NULL)
        return NULL;
    last_token = skip_delimiters(last_token, delim);
    if (*last_token == '\0')
        return NULL;
    token_start = last_token;
    while (*last_token != '\0' && !is_delimiter(*last_token, delim))
        last_token++;
    if (*last_token == '\0') {
        last_token = NULL;
    } else {
        *last_token = '\0';
        last_token++;
    }
    return token_start;
}
