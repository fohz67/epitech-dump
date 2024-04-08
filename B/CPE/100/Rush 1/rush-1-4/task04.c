/*
** EPITECH PROJECT, 2022
** rush-1-4.c
** File description:
** Rush 1-4
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
    if (a == 1 && b == 1 || a == 1 && b == y) {
        my_putchar('A');
        return;
    }
    if (a == x && b == 1 || a == x && b == y) {
        my_putchar('C');
        return;
    }
    if (a == 1 || a == x || b == 1 || b == y) {
        my_putchar('B');
        return;
    }
    if (a > 1 && b > 1 && a < x && b < y) {
        my_putchar(' ');
        return;
    }
}

void rush(int x, int y)
{
    if (x < 1 || y < 1) {
        write(2, "Invalid size\n", 13);
    }
    if (x == 1) {
        for (int a = 0 ; a < y ; a++) {
            my_putchar('B');
            my_putchar('\n');
        }
    }
    if (x > 1 && y == 1) {
        for (int a = 0 ; a < x ; a++) {
            my_putchar('B');
            }
        my_putchar('\n');
    }
    if (x > 1 && y > 1) {
        put_all(x, y);
    }
}
