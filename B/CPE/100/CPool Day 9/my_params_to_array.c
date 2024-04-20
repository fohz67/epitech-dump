/*
** EPITECH PROJECT, 2022
** my_params_to_array.c
** File description:
** My params to array
*/

struct info_param *my_params_to_array(int ac, char **av)
{
    struct info_param **tab = malloc(sizeof(struct info_param*) + 1);
    int a = 0;

    while (a < av) {
        tab[a] = malloc(sizeof(struct info_param) + 1);
        tab[a]->lenght = my_strlen(av[a]);
        tab[a]->str = av[a];
        tab[a]->copy = str_cpy(av[a]);
        tab[a]->word_array = my_str_to_word_array(av[k]);
        a = a + 1;
    }
    tab[a] = 0;
    return tab;
}
