/*
** EPITECH PROJECT, 2023
** load_map.c
** File description:
** load_map
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "ginger.h"

int get_line_len(char const *str)
{
    int len = 0;

    while (str[len] != '\0' && str[len] != '\n')
        len++;
    return (len);
}

int get_nbr_line(char const *str)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            nbr++;
    }
    return (nbr);
}

int load_file_ex(char **map, const char *filepath)
{
    FILE *file;
    char *line_buff = NULL;
    size_t line_buff_size = 0;
    int line_count = 0;
    ssize_t line_size;

    file = fopen(filepath, "r");
    line_size = getline(&line_buff, &line_buff_size, file);
    while (line_size >= 0) {
        map[line_count] = strcpy(map[line_count], line_buff);
        line_count += 1;
        line_size = getline(&line_buff, &line_buff_size, file);
        map[line_count - 1][get_line_len(line_buff) - 1] = '\0';
    }
    map[line_count] = NULL;
    free(line_buff);
    return (0);
}

char **load_map(const char *filepath, const char *buf)
{
    char **map = NULL;

    map = malloc(sizeof(char *) * get_nbr_line(buf));
    for (int i = 0; i != get_nbr_line(buf); i++)
        map[i] = malloc(sizeof(char) * get_line_len(buf) + 1);
    load_file_ex(map, filepath);
    return (map);
}
