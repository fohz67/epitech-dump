/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "my.h"

int is_last_word(const char *str, int index)
{
    int result = 0;

    while (str[index] != '\0') {
        if (str[index] != ' ' && str[index] != '\t') {
            result = 1;
        }
        index = index + 1;
    }
    return result;
}

void clean_str(const char *str)
{
    int index = 0;
    int length = 0;
    int state = 0;
    int is_last = 0;

    length = my_strlen(str);

    while (index < length) {
        char c = str[index];
        is_last = is_last_word(str, index);
        if (c != ' ' && c != '\t') {
            my_putchar(str[index]);
            state = 1;
        }
        if (state == 1 && is_last == 1 && (c == ' ' || c == '\t')) {
            my_putchar(' ');
            state = 0;
        }
        index = index + 1;
    }
}

int main(int ac, const char **av)
{
    if (ac > 2) {
        return 84;
    }
    if (ac == 1) {
        my_putchar('\n');
        return 0;
    }
    clean_str(av[1]);
    my_putchar('\n');
    return 0;
}
