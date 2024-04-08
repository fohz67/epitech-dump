/*
** EPITECH PROJECT, 2022
** my_show_word_array.c
** File description:
** My show word array
*/

int my_show_word_array(char * const *tab)
{
    for (int a = 0; tab[a] != '\0'; a++) {
        my_putstr(tab[a]);
        my_putchar('\n');
    }
}
