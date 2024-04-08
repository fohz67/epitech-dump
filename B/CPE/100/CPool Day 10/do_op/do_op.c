/*
** EPITECH PROJECT, 2022
** do_op.c
** File description:
** Do op
*/

static void calculate(char **av)
{
    if (av[2][0] == '+')
        my_put_nbr(get_number(av[1]) + get_number(av[3]));
    if (av[2][0] == '-')
        my_put_nbr(get_number(av[1]) - get_number(av[3]));
    if (av[2][0] == '*')
        my_put_nbr(get_number(av[1]) * get_number(av[3]));
    if (av[2][0] == '/')
        my_put_nbr(get_number(av[1]) / get_number(av[3]));
    if (av[2][0] == '%')
        my_put_nbr(get_number(av[1]) % get_number(av[3]));
    my_putchar('\n');
}

int get_number(char *str)
{
    int result = 0;
    int negative = 1;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == '-')
            negative = negative * (-1);
        if ((str[a] >= '0' && str[a] <= '9') &&
            (str[a + 1] < '0' || str[a + 1] > '9'))
            return (result * 10 + (str[a] - 48) * negative);
        if (str[a] >= '0' && str[a] <= '9' &&
            (str[a + 1] >= '0' || str[a + 1] <= '9'))
            result = result * 10 + (str[a] - 48);
        if ((str[a] < '0' || str[a] > '9') && a > 1)
            return (result * negative);
    }
    return (result * negative);
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (84);
    if (av[2][0] != '+' &&
        av[2][0] != '-' &&
        av[2][0] != '*' &&
        av[2][0] != '/' &&
        av[2][0] != '%') {
        my_putstr("0\n");
        return 84;
    }
    if (av[2][0] == '/' && get_number(av[3]) == 0) {
        my_putstr("Stop: division by zero\n");
        return 84;
    }
    if (av[2][0] == '%' && get_number(av[3]) == 0) {
        my_putstr("Stop: modulo by zero\n");
        return 84;
    }
    calculate(av);
    return (0);
}
