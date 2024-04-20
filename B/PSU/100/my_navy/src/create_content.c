/*
** EPITECH PROJECT, 2022
** create_content.c
** File description:
** create_content.c
*/

#include "../include/my.h"

char *free_buf(char *buffer)
{
    free(buffer);
    return NULL;
}

int file_check(const char *path, char *buffer, int size)
{
    int fd = 0;

    if ((fd = open(path, O_RDONLY)) == -1) {
        return 84;
    }
    if (read(fd, buffer, size) == -1) {
        return 84;
    }
    if (close(fd) == -1) {
        return 84;
    }
    return 0;
}

char *file_content(int ac, const char **av)
{
    char *buffer = NULL;
    char *path = NULL;

    if (ac == 2) {
        path = my_strdup(av[1]);
    }
    if (ac == 3) {
        path = my_strdup(av[2]);
    }
    if ((buffer = malloc(sizeof(char) * (32 + 1))) == NULL) {
        return NULL;
    }
    if (file_check(path, buffer, 33) == 84) {
        return free_buf(buffer);
    }
    buffer[32] = '\0';
    return buffer;
}

char *file_content_map(void)
{
    char *buffer = NULL;

    if ((buffer = malloc(sizeof(char) * (180 + 1))) == NULL) {
        return NULL;
    }
    if (file_check("./src/map.txt", buffer, 180) == 84) {
        return free_buf(buffer);
    }
    buffer[180] = '\0';
    return buffer;
}

int file_maps(int ac, const char **av)
{
    char *map_buffer = NULL;

    if ((my_game.buffer = file_content(ac, av)) == NULL) {
        return 84;
    }
    if ((map_buffer = file_content_map()) == NULL) {
        return 84;
    }
    if ((my_game.my_map = my_str_to_word_array(map_buffer)) == NULL) {
        return 84;
    }
    if ((my_game.enemy_map = my_str_to_word_array(map_buffer)) == NULL) {
        return 84;
    }
    free(map_buffer);
    return 0;
}
