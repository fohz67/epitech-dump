/*
** EPITECH PROJECT, 2022
** 101pong
** File description:
** 101pong
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct coord {
    double x;
    double y;
    double z;
};

int error(int ac, char** av, int i)
{
    if ((av[i][0] < '0' || av[i][0] > '9') && av[i][0] != '-') {
        return 84;
    }
    if (av[7][0] == '-') {
        return 84;
    }
    for (int i = 0; i != ac; i += 1) {
        if (av[7][i] == '.') {
            return 84;
        }
    }
    return 0;
}

int display_rules(void)
{
    printf("USAGE\n");
    printf("%6s%s\n", "./", "101pong x0 y0 z0 x1 y1 z1 n");
    printf("\nDESCRIPTION\n");
    printf("    x0 ball abscissa at time t - 1\n");
    printf("    y0 ball ordinate at time t - 1\n");
    printf("    z0 ball altitude at time t - 1\n");
    printf("    x1 ball abscissa at time t\n");
    printf("    y1 ball ordinate at time t\n");
    printf("    z1 ball altitude at time t\n");
    printf("    n time shift (greater than or equal to zero, integer)\n");
    return 0;
}

int angle(char **av)
{
    float velX = atof(av[4]) - atof(av[1]);
    float velY = atof(av[5]) - atof(av[2]);
    float velZ = atof(av[6]) - atof(av[3]);

    if (velX != 0 && velY != 0 && velZ != 0) {
        float sumScal = pow(velX, 2) + pow(velY, 2) + pow(velZ, 2);
        float prodScal = sqrt(sumScal);
        float finalScal = acos(fabs(velZ) / prodScal);
        float final = 90 - finalScal * 180 / M_PI;

        printf("The incidence angle is:\n%.2f degrees\n", final);
    } else {
        printf("The ball won't reach the paddle.\n");
    }
    return 0;
}

int pong(char **av)
{
    struct coord vector;
    int n = atoi(av[7]);

    printf("The velocity vector of the ball is:\n");
    vector.x = atof(av[4]) - atof(av[1]);
    vector.y = atof(av[5]) - atof(av[2]);
    vector.z = atof(av[6]) - atof(av[3]);
    printf("(%.2f, %.2f, %.2f)\n", vector.x, vector.y, vector.z);
    printf("At time t + %i, ball coordinates will be:\n", n);
    vector.x = (vector.x * n) + atof(av[4]);
    vector.y = (vector.y * n) + atof(av[5]);
    vector.z = (vector.z * n) + atof(av[6]);
    printf("(%.2f, %.2f, %.2f)\n", vector.x, vector.y, vector.z);
    return angle(av);
}

int main(int ac, char **av)
{
    int i = 1;
    int result = 0;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        return display_rules();
    }
    if (ac != 8) {
        return 84;
    }

    while (i < ac) {
        result = error(ac, av, i);
        i++;
        if (result == 84) {
            return 84;
        }
    }
    return pong(av);
}
