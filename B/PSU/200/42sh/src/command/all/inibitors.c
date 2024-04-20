/*
** EPITECH PROJECT, 2023
** inibitors.c
** File description:
** inibitors.c
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

int my_inibitors(int result, char **envcp, char **cmd)
{
    size_t size = 0;
    char *buffer = NULL;

    if (my_strlen(cmd[0]) == 1) {
        write(1, "? ", 2);
        getline(&buffer, &size, stdin);
        result = controller_separators(envcp, NULL, buffer, result);
    }
    if (my_strlen(cmd[0]) > 1) {
        buffer = my_word_array_to_str(cmd);
        result = controller_separators(envcp, NULL, &buffer[1], result);
    }
    return result;
}
