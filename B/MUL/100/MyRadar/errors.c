/*
** EPITECH PROJECT, 2022
** errors.c
** File description:
** errors.c
*/

#include "./include/my.h"

int params_errors(int ac, const char *path, struct utils *utils)
{
    if (ac < 2) {
        write(1, NOT_ENOUGH, my_strlen(NOT_ENOUGH));
        return ERROR;
    }
    if (ac > 2) {
        write(1, TOO_MANY, my_strlen(TOO_MANY));
        return ERROR;
    }
    if (file_content(path, utils) == 84) {
        return ERROR;
    }
    return SUCCESS;
}

int file_errors(char *buffer)
{
    int index = 0;

    if (buffer[0] == ENDSTR || (buffer[0] != PLANE && buffer[0] != TOWER)) {
        return ERROR;
    }

    while (buffer[index] != ENDSTR) {
        if ((buffer[index] == PLANE || buffer[index] == TOWER) &&
        buffer[index + 1] != SPACE) {
            return ERROR;
        }
        if (buffer[index] != PLANE && buffer[index] != TOWER &&
        buffer[index] != ENDLINE && buffer[index] != SPACE &&
        (buffer[index] < '0' || buffer[index] > '9')) {
            return ERROR;
        }
        index = index + 1;
    }
    return SUCCESS;
}

int struct_matrix_errors(struct utils *utils)
{
    int index = 0;

    while (my_strcmp(utils->tab[index], END) != SUCCESS) {
        if (utils->tab[index][0] == TOWER &&
        utils->tab[index + 4][0] != PLANE &&
        utils->tab[index + 4][0] != TOWER &&
        my_strcmp(utils->tab[index + 4], END) != SUCCESS) {
            write(1, INVALID, my_strlen(INVALID));
            return ERROR;
        }
        if (utils->tab[index][0] == PLANE &&
        utils->tab[index + 7][0] != PLANE &&
        utils->tab[index + 7][0] != TOWER &&
        my_strcmp(utils->tab[index + 7], END) != SUCCESS) {
            write(1, INVALID, my_strlen(INVALID));
            return ERROR;
        }
        index = index + 1;
    }
    return SUCCESS;
}
