/*
** EPITECH PROJECT, 2022
** my_compute_factorial_it.c
** File description:
** My compute factorial iterative
*/

int my_compute_factorial_it(int nb)
{
    int result = 1;
    int a = 0;

    if (nb == 0)
        return 1;
    if (nb == 1)
        return nb;
    if (nb < 0)
        return 0;
    if (nb >= 13)
        return 0;
    while (a < nb) {
        result = result * (nb - a);
        a = a + 1;
    }
    return result;
}
