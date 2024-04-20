/*
** EPITECH PROJECT, 2022
** my_grep.c
** File description:
** My grep
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

void my_putchar(char);
int my_putstr(char const *);
int my_strlen(char const *);
int grep_sub(int, char **, char *, int);

int check_error(char *str, int fd)
{
    if (errno == 0 && fd == -1) {
        my_putstr("Error with open\n");
        return 84;
    }
    if (errno != 0 || fd == 100420) {
        my_putstr("grep: ");
        my_putstr(str);
    }
    if (errno == ENOENT || fd == 100421) {
        my_putstr(": No such file or directory\n");
        return 2;
    }
    if (errno == EISDIR || fd == 100422) {
        my_putstr(": Is a directory\n");
        return 2;
    }
    return 0;
}

void display(char **av, int a)
{
    my_putstr("\033[35m");
    my_putstr(av[a]);
    my_putstr("\033[36m");
    my_putchar(':');
    my_putstr("\033[0m");

}

int search(int ac, char **av, char *buffer)
{
    for (int a = 2; a < ac; a++) {
        int fd = open(av[a], O_RDONLY);
        int error = check_error(av[a], fd);
        if (error != 0)
            return error;
        read(fd, buffer, 30000);
        error = check_error(av[a], fd);
        if (error != 0)
            return error;
        if (ac > 3)
            display(av, a);
        if (grep_sub(ac, av, buffer, a) == 0)
            return 1;
        else
            occurences(ac, av, buffer, a);
        for (int b = 0; buffer[b] != '\0'; b++)
            buffer[b] = 0;
    }
    return 0;
}

void infinite(char *buffer)
{
    read(0, buffer, 30000);
    my_putstr("\033[1m\033[31m");
    my_putstr(buffer);
    for (int b = 0; buffer[b] != '\0'; b++)
        buffer[b] = 0;
    my_putstr("\033[0m");
}

int grep(int ac, char **av)
{
    char buffer[30000];

    if (ac == 1) {
        my_putstr("Usage: grep [OPTION]... PATTERNS [FILE]...");
        my_putstr("\nTry 'grep --help' for more informations.\n");
        return 2;
    }
    if (av[1] < 2) {
        my_putstr("grep: ");
        my_putstr(av[1]);
        my_putstr(": The read of size 1 is forbidden...\n");
        return 84;
    }
    if (ac == 2)
        infinite(buffer);
    if (ac > 2)
        return search(ac, av, buffer);
}
