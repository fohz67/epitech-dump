/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** modif_itoa.c
*/

#include <stdlib.h>

int calcul_i(int *score)
{
    int i = 0;

    if (*score < 0) {
        i += 1;
        *score *= -1;
    }
    if (*score > 0 && *score <= 9)
        i += 1;
    if (*score > 9 && *score <= 99)
        i += 2;
    if (*score > 99 && *score <= 999)
        i += 3;
    if (*score > 999 && *score <= 9999)
        i += 4;
    if (*score > 9999)
        i += 5;
    return i;
}

char *malloc_itoa(char *str)
{
    if (str == NULL) {
        if ((str = malloc(7)) == NULL)
            return NULL;
    } else {
        free(str);
        if ((str = malloc(7)) == NULL)
            return NULL;
    }
    return str;
}

char* modif_itoa(int score, char* str)
{
    int i = 0;

    if ((str = malloc_itoa(str)) == NULL)
        return NULL;
    if (score == 0) {
        str[1] = '\0';
        str[0] = '0';
        return str;
    }
    if (score < 0)
        str[0] = '-';
    i = calcul_i(&score);
    str[i] = '\0';
    for (; score > 0 && i > 0; i -= 1) {
        str[i - 1] = score % 10 + '0';
        score /= 10;
    }
    return str;
}
