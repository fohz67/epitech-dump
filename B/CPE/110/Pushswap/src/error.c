/*
** EPITECH PROJECT, 2022
** B-CPE-110-TLS-1-1-pushswap-benjamin.gayaud
** File description:
** error.c
*/

#include "../include/my.h"

int error(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < '0' || str[i] > '9') && str[0] != '-') {
            return 84;
        }
        i++;
    }
    return 0;
}
