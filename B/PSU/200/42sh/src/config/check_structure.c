/*
** EPITECH PROJECT, 2023
** check_structure.c
** File description:
** check_structure.c
*/

int check_string(char *line)
{
    int count = 0;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == '\"')
            count++;
    return count;
}

int check_syntax(char *line)
{
    int count = 0;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == '=')
            count++;
    return count;
}

int check_alias(char *line)
{
    int count = 0;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == ':')
            count++;
    return count;
}
