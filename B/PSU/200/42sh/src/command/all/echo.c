/*
** EPITECH PROJECT, 2023
** echo.c
** File description:
** echo.c
*/

#include <string.h>
#include <stdio.h>
#include "my.h"

static const char *flags[] = {"-e", "-n", "-E", NULL};

static int contain_flags(char **echo)
{
    for (int i = 0; flags[i] != NULL; i++) {
        if (strcmp(echo[1], flags[i]) == 0) {
            return i;
        }
    }
    return -1;
}

static void my_echo_parse(char **echo, int result, int i, int flag)
{
    for (; echo[i] != NULL; i++) {
        if (strcmp(echo[i], "$?") == 0) {
            my_putnbr(result);
        } else {
            my_putstr(echo[i]);
        }
        if (echo[i + 1] != NULL) {
            my_putstr(" ");
        }
    }
    if (flag == -1 || strcmp(flags[flag], "-n") != 0) {
        my_putstr("\n");
    }
}

static int echo_env(char **echo, char **envcp, int result, int flag)
{
    char *temp = NULL;
    char *retrieved = NULL;
    int i = 1;

    if ((flag = contain_flags(echo)) != -1)
        i++;
    if (echo[1][0] == '$' && echo[1][1] != '?' && echo[1][2] != '\0') {
        temp = my_stridup(echo[1], 1);
        my_strcat(temp, "=");
        retrieved = retrieve_data_env(envcp, temp, my_strlen(temp));
        if (retrieved == NULL) {
            my_putstr(&echo[1][1]);
            my_putstr(": Undefined variable.\n");
            return 1;
        }
        my_putstr(retrieved);
        my_putchar('\n');
    } else
        my_echo_parse(echo, result, i, flag);
    return 0;
}

int my_echo(char **echo, int result, char **envcp)
{
    int flag = 0;

    if (echo[1] == NULL) {
        my_putstr("\n");
        return 0;
    }
    if (echo_env(echo, envcp, result, flag) == 1)
        return 1;
    return 0;
}
