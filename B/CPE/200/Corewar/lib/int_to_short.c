/*
** EPITECH PROJECT, 2023
** int_to_short.c
** File description:
** int_to_short.c
*/

short int_to_short(int value)
{
    unsigned short mask = 0;
    unsigned short result = 0;

    mask = 0xFFFF;
    result = value &mask;
    if (result & (1 << 15)) {
        result = ~result + 1;
        result = -result;
    }
    return result;
}
