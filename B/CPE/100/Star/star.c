/*
** EPITECH PROJECT, 2022
** star.c
** File description:
** Star
*/

void put_top(size)
{
    int s_1 = 3 * size - 1;
    int s_1_i = -1;

    for (int a = 0 ; a < size ; a++) {
        for (int b = 0 ; b < s_1 ; b++) my_putchar(' ');
        my_putchar('*');
        s_1 = s_1 - 1;
        for (int c = 0 ; c < s_1_i ; c++ ) my_putchar(' ');
        if (a != 0)
            my_putchar('*');
        my_putchar('\n');
        s_1_i = s_1_i + 2;
    }
    put_middle_top(size, s_1, s_1_i);
}

void put_middle_top(int size, int s_1, int s_1_i)
{
    int s_2 = 1;
    int s_2_i = 7 + 6 * (size - 2);

    for (int a = 0; a < s_1 + 2; a++) my_putchar('*');
    for (int a = 0; a < s_1_i - 2; a ++) my_putchar(' ');
    for (int a = 0; a < s_1 + 2; a++) my_putchar('*');
    my_putchar('\n');
    for (int a = 0; a < size; a ++) {
        for (int b = 0 ; b < s_2 ; b++) my_putchar(' ');
        my_putchar('*');
        s_2 = s_2 + 1;
        for (int c = 0; c < s_2_i; c++) my_putchar(' ');
        my_putchar('*');
        my_putchar('\n');
        s_2_i = s_2_i - 2;
    }
    put_middle_bottom(size, s_1_i, s_1, s_2_i);
}

void put_middle_bottom(int size, int s_1_i, int s_1, int s_2_i)
{
    s_2_i = s_2_i + 4;
    int s_2 = size - 1;

    for (int a = 0; a < size - 1; a ++) {
        for (int b = 0 ; b < s_2 ; b++) my_putchar(' ');
        my_putchar('*');
        s_2 = s_2 - 1;
        for (int c = 0; c < s_2_i; c++) my_putchar(' ');
        my_putchar('*');
        my_putchar('\n');
        s_2_i = s_2_i + 2;
    }
    for (int a = 0 ; a < s_1 + 2 ; a++) my_putchar('*');
    for (int a = 0 ; a < s_1_i - 2 ; a++) my_putchar(' ');
    for (int a = 0 ; a < s_1 + 2 ; a++) my_putchar('*');
    my_putchar('\n');
    put_bottom(size, s_1_i, s_2, s_2_i);
}

void put_bottom(int size, int s_1_i, int s_2, int s_2_i)
{
    int s_1 = 4 + 2 * (size - 2);
    s_1_i = s_1_i - 2;

    for (int a = 0 ; a < size ; a++) {
        for (int b = 0 ; b < s_1 ; b++) my_putchar(' ');
        my_putchar('*');
        s_1 = s_1 + 1;
        for (int c = 0 ; c < s_1_i ; c++ ) my_putchar(' ');
        if (a != size - 1)
            my_putchar('*');
        my_putchar('\n');
        s_1_i = s_1_i - 2;
    }
}

void star(unsigned int size)
{
    if (size == 0) {
        return;
    }
    if (size == 1) {
        write(1, "   *\n", 5);
        write(1, "*** ***\n", 8);
        write(1, " *   *\n", 7);
        write(1, "*** ***\n", 8);
        write(1, "   *\n", 5);
    }
    if (size > 1) {
        put_top(size);
    }
}
