/*
** EPITECH PROJECT, 2022
** test_my_strstr.c
** File description:
** Test my str str
*/

#include <criterion/criterion.h>
Test (my_strstr, find_characters)
{
	char str[] = "Hello";
	char find_out[] = "ll";
	
    my_strstr(str, find_out);
    cr_assert_str_eq("llo", "llo");
}
