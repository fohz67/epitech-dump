/*
** EPITECH PROJECT, 2022
** rush2.c
** File description:
** Rush 2
*/

static int check_alpha_len(char** av)
{
    int a = 0, b = 0;

    while (av[1][b] != '\0') {
        if (
            av[1][b] >= 'a' &&
            av[1][b] <= 'z' ||
            av[1][b] >= 'A' &&
            av[1][b] <= 'Z') {
            a = a + 1;
        }
        b = b + 1;
    }
    return a;
}

static void display_result(char** av, int position, int count)
{
    char alpha = av[position][0];
    int sentence_length = check_alpha_len(av);
    float pourcent = (float) count / (float) sentence_length * 100;
    int pourcent_int = (count * 100 / sentence_length * 100) / 100;
    float diff = pourcent - (float) pourcent_int;
    int get_two_dec = diff * 100;

    my_putchar(alpha);
    my_putchar(':');
    my_putchar(count + '0');
    my_putstr(" (");
    my_put_nbr(pourcent_int);
    my_putchar('.');
    if (get_two_dec == 0)
        my_putstr("00");
    else
        my_put_nbr(get_two_dec);
    my_putstr("%)\n");
}

static int check_for_alpha(char** av, int position)
{
    char alpha = av[position][0];

    if (alpha >= 'a' && alpha <= 'z')
        return 1;
    if (alpha >= 'A' && alpha <= 'Z')
        return 2;
    return 0;
}

static void check_for_letter(char** av, int position)
{
    int a = 0, b = 0;
    char alpha_uncased = av[position][0];
    char alpha_cased = alpha_uncased;

    if (check_for_alpha(av, position) == 1)
        alpha_cased = alpha_uncased - 32;
    if (check_for_alpha(av, position) == 2)
        alpha_cased = alpha_uncased + 32;
    while (av[1][a] != '\0') {
        if (alpha_uncased == av[1][a] || alpha_cased == av[1][a])
            b = b + 1;
        a = a + 1;
    }
    display_result(av, position, b);
}

int main(int ac, char **av)
{
    int position = 2;

    if (ac < 2) {
        my_putstr("Aucune phrase ni lettre n'a été rensignée\n");
        return 0;
    }
    if (ac < 3) {
        my_putstr("Tu dois rensigner au minimum une lettre\n");
        return 0;
    }
    while (position < ac) {
        if (check_for_alpha(av, position) > 0)
            check_for_letter(av, position);
        position = position + 1;
    }
}
