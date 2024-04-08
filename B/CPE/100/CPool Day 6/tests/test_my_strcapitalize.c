/*
** EPITECH PROJECT, 2022
** test_my_strcapitalize.c
** File description:
** Test my str capitalize
*/

#include <criterion/criterion.h>
Test (my_strcapitalize, find_characters)
{
	char str[20] = "aaA8a+++mMM---nnN";
	
    my_strcapitalize(str);
    cr_assert_str_eq(str, "Aaa8a+++Mmm---Nnn");
}
