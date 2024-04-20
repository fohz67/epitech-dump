/*
** EPITECH PROJECT, 2022
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "../include/my.h"

void replacer(char *sdef1, char *sdef2, char *checker)
{
    if (checker[0] == 'y') {
        sdef1[0] = sdef1[0] - 32;
    }
    if (checker[1] == 'y') {
        sdef2[0] = sdef2[0] - 32;
    }
    checker[0] = ENDSTR;
}

int returner(char *sdef1, char *sdef2)
{
    int diff = 0;
    int count = 0;

    while (*sdef1 && *sdef1 == *sdef2) {
        sdef1++;
        sdef2++;
        count++;
    }

    diff = *sdef1 - *sdef2;

    while (count-- > 0) {
        sdef1--;
        sdef2--;
    }
    return diff;
}

void upper(char *sdef1, char *sdef2, char *checker)
{
    if (sdef1[0] >= 65 && sdef1[0] <= 90) {
        sdef1[0] = sdef1[0] + 32;
        checker[0] = 'y';
    }
    if (sdef2[0] >= 65 && sdef2[0] <= 90) {
        sdef2[0] = sdef2[0] + 32;
        checker[1] = 'y';
    }
}

int my_strcmp(const char *s1, const char *s2)
{
    char *sdef1 = my_strdup(s1);
    char *sdef2 = my_strdup(s2);
    char checker[2] = "nn";

    int diff = 0;

    upper(sdef1, sdef2, checker);
    diff = returner(sdef1, sdef2);
    replacer(sdef1, sdef2, checker);

    return diff;
}
