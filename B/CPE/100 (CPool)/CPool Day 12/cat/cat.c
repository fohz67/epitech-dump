/*
** EPITECH PROJECT, 2022
** my_cat.c
** File description:
** My cat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

void my_putchar(char);
int my_putstr(char const *);

int check_error(char *str, int fd)
{
    if (errno == 0 && fd == -1) {
        my_putstr("Error with open\n");
        return 84;
    }
    if (errno != 0 || fd == -70001) {
        my_putstr("cat: ");
        my_putstr(str);
    }
    if (errno == ENOENT || fd == -70002) {
        my_putstr(": No such file or directory\n");
        return 1;
    }
    if (errno == EISDIR || fd == -70003) {
        my_putstr(": Is a directory\n");
        return 1;
    }
    return 0;
}

void infinite(char *buffer)
{
    read(0, buffer, 30000);
    my_putstr(buffer);
    for (int b = 0; buffer[b] != '\0'; b++)
        buffer[b] = 0;
}

int cat(int ac, char **av)
{
    char buffer[30000];

    if (ac == 1)
        infinite(buffer);
    for (int a = 1; a < ac; a++) {
        int fd = open(av[a], O_RDONLY);
        int error = check_error(av[a], fd);
        if (error != 0)
            return error;
        read(fd, buffer, 30000);
        error = check_error(av[a], fd);
        if (error != 0)
            return error;
        my_putstr(buffer);
        for (int b = 0; buffer[b] != '\0'; b++)
            buffer[b] = 0;
    }
    return 0;
}
