/*
** EPITECH PROJECT, 2022
** my_sort_int_array.c
** File description:
** My sort int array
*/

void my_swap_for_in_array(int *a, int *b)
{
    if (*a > *b) {
        int a_bis = *a;
        int b_bis = *b;

        *a = b_bis;
        *b = a_bis;
    }
}

void my_sort_in_array(int *array, int *size)
{
    int a = 0;
    int b = 0;
    int size_int = *size;

    while (a < size_int) {
        a = a + 1;
        while (b < size_int - a - 1) {
            b = b + 1;
            my_swap_for_in_array(&a, &b);
        }
    }
}
