/*
** EPITECH PROJECT, 2022
** test_my_strncmp.c
** File description:
** Test my str n cmp
*/

#include <criterion/criterion.h>
Test (my_strncmp, find_characters)
{
	char str[6] = "Hello";
	char find[6] = "Hello";
	int n = 3;
	int nb = 0;
	
    my_strncmp(s1, s2, n);
    cr_assert_str_eq(nb, 0);
}
