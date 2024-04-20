/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "transfer.h"

int count(const char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] == '*') {
            nb++;
        }
        i++;
    }
    return nb + 1;
}

char **strwa(const char *src)
{
    int count = 1;
    for (int i = 0; src[i] != '\0'; i++) if (src[i] == '*') count++;
    char **result = (char **) malloc(sizeof(char *) * count);
    int current = 0, start = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == '*') {
            int len = i - start;
            result[current] = (char *) malloc(sizeof(char) * (len + 1));
            strncpy(result[current], src + start, len);
            result[current][len] = '\0';
            current++;
            start = i + 1;
        }
    }
    int len = strlen(src) - start;
    result[current] = (char *) malloc(sizeof(char) * (len + 1));
    strncpy(result[current], src + start, len);
    result[current][len] = '\0';
    return result;
}

transfer *struct2(transfer *tr, const char *arg1, const char *arg2)
{
    tr->str_a = strwa(arg1);
    tr->str_b = strwa(arg2);
    tr->max_a = count(arg1);
    tr->max_b = count(arg2);
    tr->tab_a = malloc(tr->max_a * sizeof(int));
    tr->tab_b = malloc(tr->max_b * sizeof(int));
    for (int i = 0; i < tr->max_a; i++) {
        tr->tab_a[i] = atoi(tr->str_a[i]);
    }
    for (int i = 0; i < tr->max_b; i++) {
        tr->tab_b[i] = atoi(tr->str_b[i]);
    }
    return tr;
}

transfer *struct1(transfer *tr, const char **av)
{
    tr = malloc(sizeof(transfer));
    tr->str_a = strwa(av[1]);
    tr->str_b = strwa(av[2]);
    tr->max_a = count(av[1]);
    tr->max_b = count(av[2]);
    tr->tab_a = calloc(tr->max_a, sizeof(int));
    tr->tab_b = calloc(tr->max_b, sizeof(int));
    for (int i = 0; i < tr->max_a; i++) {
        tr->tab_a[i] = atoi(tr->str_a[i]);
    }
    for (int i = 0; i < tr->max_b; i++) {
        tr->tab_b[i] = atoi(tr->str_b[i]);
    }
    return tr;
}
