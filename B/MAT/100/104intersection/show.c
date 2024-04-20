/*
** EPITECH PROJECT, 2022
** show.c
** File description:
** show.c
*/

#include "./include/my.h"

void show_args(const char **av)
{
    printf("Line passing through the point ");
    printf("(%s, %s, %s) ",  av[2], av[3], av[4]);
    printf("and parallel to the vector ");
    printf("(%s, %s, %s)\n",  av[5], av[6], av[7]);
}

void show_type(const char **av, struct utils *utils, struct cal *cal)
{
    if (av[1][0] == '1') {
        printf("Sphere of radius %s\n", av[8]);
        show_args(av);
        inter_sphere(utils, cal);
    }
    if (av[1][0] == '2') {
        printf("Cylinder of radius %s\n", av[8]);
        show_args(av);
        inter_cylinder(utils, cal);
    }
    if (av[1][0] == '3') {
        printf("Cone with a %s degree angle\n", av[8]);
        show_args(av);
        inter_cone(utils, cal);
    }
}
