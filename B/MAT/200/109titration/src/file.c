/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** file.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int check(titration *titra)
{
    for (int i = 0; i != titra->nb; i++) {
        if (titra->tabx[i] == 0 || titra->taby[i] == 0) {
            return 84;
        }
    }
    return 0;
}

static int count_lines(char *file)
{
    int nb_lines = 0;
    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == '\n' || file[i] == ';') {
            nb_lines++;
        }
    }
    return nb_lines;
}

static void get_values(char *file, titration *titra)
{
    int nb_lines = count_lines(file);
    char **split = my_split(file, nb_lines);

    int nb_points = nb_lines / 2;
    titra->nb = nb_points;
    titra->tabx = malloc(sizeof(double) * nb_points);
    titra->taby = malloc(sizeof(double) * nb_points);
    for (int i = 0, j = 0, k = 0; split[i] != NULL; i++) {
        if (i % 2 == 0) {
            titra->tabx[j] = atof(split[i]);
            j++;
        } else {
            titra->taby[k] = atof(split[i]);
            k++;
        }
    }
    for (int i = 0; split[i] != NULL; i++)
        free(split[i]);
    free(split);
}

static void fill_derivatives(titration *titra)
{
    titra->dev = malloc(sizeof(double) * titra->nb);
    titra->sec = malloc(sizeof(double) * titra->nb);
    for (int i = 0; i != titra->nb; i++) {
        titra->dev[i] = 0;
        titra->sec[i] = 0;
    }
}

int open_file(const char **av, titration *titra)
{
    struct stat st;
    char *buffer = NULL;

    int fd = open(av[1], O_RDONLY);
    if (fd == -1) return 84;
    if (fstat(fd, &st) == -1) return 84;
    buffer = malloc(sizeof(char) * st.st_size + 1);
    if (!buffer) return 84;
    ssize_t read_size = read(fd, buffer, st.st_size);
    if (read_size == -1) {
        free(buffer);
        return 84;
    }
    buffer[st.st_size] = '\0';
    get_values(buffer, titra);
    free(buffer);
    close(fd);
    titra->eq_p = 0;
    fill_derivatives(titra);
    return 0;
}
