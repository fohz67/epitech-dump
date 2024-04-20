/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "cipher.h"

void display(int total, int *tab)
{
    printf("Key matrix:\n");
    if (total == 1) {
        printf("%d", tab[0]);
    }
    if (total == 4) {
        printf("%d\t%d\n%d\t%d", tab[0], tab[1], tab[2], tab[3]);
    }
    if (total == 9) {
        printf("%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d", tab[0], tab[1],
        tab[2], tab[3], tab[4], tab[5], tab[6], tab[7], tab[8]);
    }
    if (total == 16) {
        printf("%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d\n%d\t%d\t%d\t%d",
        tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6], tab[7],
        tab[8], tab[9], tab[10], tab[11], tab[12], tab[13], tab[14], tab[15]);
    }
    printf("\n\nEncrypted message:\n");
}

int * matrix(int total, const char **av, int *tab)
{
    int i = 0;
    int end = 0;

    while (i < total) {
        if (av[2][i] != '\0' && end == 0) {
            tab[i] = av[2][i];
        } else {
            end = 1;
            tab[i] = 0;
        }
        i++;
    }
    return tab;
}

int alloc(const char **av)
{
    int total = 0;

    total = strlen(av[2]);

    if (total == 1) {
        return 1;
    }
    if (total <= 4) {
        return 4;
    }
    if (total <= 9) {
        return 9;
    }
    if (total <= 16) {
        return 16;
    }
    return 84;
}

int error(int ac, const char **av)
{
    if (ac != 4) {
        return 84;
    }
    if (av[3][0] != '0' && av[3][0] != '1') {
        return 84;
    }
    if (strlen(av[2]) > 16 || strlen(av[2]) == 0) {
        return 84;
    }
    return 0;
}

int main(int ac, const char **av)
{
    int total = 0;
    int *tab = NULL;

    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        write(1, HELP, strlen(HELP));
        return 0;
    }
    if (error(ac, av) == 84) {
        return 84;
    }

    total = alloc(av);
    tab = malloc(sizeof(int) * total);
    tab = matrix(total, av, tab);

    display(total, tab);
    return 0;
}
