/*
** EPITECH PROJECT, 2022
** mini_putnbr.c
** File description:
** Mini putnbr
*/

int mini_putchar(char c);

int mini_putnbr(int nb)
{
    int a = 1;
    int count = 0;

    if (nb < 0) {
        mini_putchar('-');
        nb = nb * -1;
        count = count + 1;
    }
    while (nb / a > 9)
        a = a * 10;
    while (a >= 1) {
        mini_putchar((nb / a) % 10 + 48);
        a = a / 10;
        count = count + 1;
    }
    return count;
}
