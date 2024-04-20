/*
** EPITECH PROJECT, 2022
** count_island.c
** File description:
** Count island
*/

static void replace_x(char **world, int a, int b, int counter)
{
    world[a][b] = counter + '0';
    if (a > 0 && world[a - 1][b] == 'X')
        replace_x(world, a - 1, b, counter);
    if (world[a + 1] && world[a + 1][b] == 'X')
        replace_x(world, a + 1, b, counter);
    if (b > 0 && world[a][b - 1] == 'X')
        replace_x(world, a, b - 1, counter);
    if (world[a][b + 1] && world[a][b + 1] == 'X')
        replace_x(world, a, b + 1, counter);
}

static void check_x(char** world, int a, int b, int *counter)
{
    int d = *counter;

    if (world[a][b] == 'X') {
        *counter = d + 1;
        replace_x(world, a, b, d);
    }
}

int count_island(char** world)
{
    int counter = 0;

    for (int a = 0; world[a]; a++)
        for (int b = 0; world[a][b] && world[a][b] != '\n'; b++)
            check_x(world, a, b, &counter);
    return counter;
}
