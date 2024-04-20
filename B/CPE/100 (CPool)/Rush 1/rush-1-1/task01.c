/*
** EPITECH PROJECT, 2022
** rush-1-1.c
** File description:
** Rush 1-1
*/

void put_all(int x, int y)
{
    int a;
    int b;

    for (b = 1 ; b <= y ; b++) {
        for (a = 1; a <= x ; a++) {
            set_char(a, b, x, y);
        }
        my_putchar('\n');
    }
}

void set_char(int a, int b, int x, int y)
{
    if (a == 1 && b == 1 || a == x && b == y) {
        my_putchar('o');
        return;
    }
    if (a == 1 && b == y || a == x && b == 1) {
        my_putchar('o');
        return;
    }
    if (b == 1 && a > 1 && a < x || b == y && a > 1 && a < x) {
        my_putchar('-');
        return;
    }
    if (a == 1 && b > 1 && b < y || a == x && b > 1 && b < y) {
        my_putchar('|');
        return;
    }
    if (a > 1 && b > 1 && a < x && b < y) {
        my_putchar(' ');
        return;
    }
}

void rush(int x, int y)
{
    if (x < 1 || y < 1)
        write(2, "Invalid size\n", 13);
    if (x >= 1 && y >= 1)
        put_all(x, y);
}
