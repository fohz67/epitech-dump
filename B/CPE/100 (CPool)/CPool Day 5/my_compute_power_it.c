/*
** EPITECH PROJECT, 2022
** my_compute_power_it.c
** File description:
** My compute power it
*/

int my_compute_power_it(int nb, int p)
{
    int result = 1;
    int a = 0;

    if (p == 0)
        return 1;
    if (p == 1)
        return nb;
    if (p < 0)
        return 0;
    while (a < p) {
        result = result * nb;
        a = a + 1;
    }
    return result;
}
