/*
** EPITECH PROJECT, 2022
** grep_sub.c
** File description:
** Grep
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

void my_putchar(char);
int my_putstr(char const *);
int my_strlen(char const *);

int replace(char **av,  char *buffer, int index, int index_av)
{
    if (my_strlen(av[1]) == index_av) {
        for (int x = index_av; x > 0; x--) {
            my_putstr("\033[1m\033[31m");
            my_putchar(buffer[index - x]);
        }
        return 1;
    }
    return 0;
}

void occurences(int ac, char **av, char *buffer, int a)
{
    int index = 0;
    int index_av = 0;

    while (index < my_strlen(buffer)) {
        while (buffer[index] == av[1][index_av]) {
            index_av = index_av + 1;
            index = index + 1;
            replace(av, buffer, index, index_av);
        }
        index_av = 0;
        index = index + 1;
        my_putstr("\033[0m");
        my_putchar(buffer[index - 1]);
    }
    if (a < ac - 1)
            my_putchar('\n');
}

int replace_sub(char **av,  char *buffer, int index, int index_av)
{
    if (my_strlen(av[1]) == index_av) {
        return 1;
    }
    return 0;
}

int grep_sub(int ac, char **av, char *buffer, int a)
{
    int index = 0;
    int index_av = 0;
    int occurence = 0;

    while (index < my_strlen(buffer)) {
        while (buffer[index] == av[1][index_av]) {
            index_av = index_av + 1;
            index = index + 1;
            occurence = occurence + replace_sub(av, buffer, index, index_av);
        }
        index_av = 0;
        index = index + 1;
    }
    return occurence;
}
