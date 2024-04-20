/*
** EPITECH PROJECT, 2022
** test_my_revstr.c
** File description:
** Test my rev str
*/

#include <criterion/criterion.h>
Test (my_revstr, reverse_five_characters)
{    
	char str[6] = "Hello";
	
    my_revstr(str);
    cr_assert_str_eq(str, "olleH");
}
