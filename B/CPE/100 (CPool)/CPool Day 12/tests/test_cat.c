/*
** EPITECH PROJECT, 2022
** test_cat.c
** File description:
** Test cat
*/

#include <criterion/criterion.h>
#include <stdio.h>

int cat(int, char *);
int check_error(char *, int);

Test(cat, Test1)
{
    char *str = "Hello";
    int fd = -1;
	
    cr_assert_eq(84, check_error(str, fd));
}

Test(cat, Test2)
{
    char *str = "Enchantée";
    int fd = 10;
	
    cr_assert_eq(0, check_error(str, fd));
}

Test(cat, Test3)
{
    char *str = "Bonjour";
    int fd = -70001;
	
    cr_assert_eq(0, check_error(str, fd));
}

Test(cat, Test4)
{
    char *str = "Aurevoir";
    int fd = -70002;
	
    cr_assert_eq(1, check_error(str, fd));
}

Test(cat, Test5)
{
    char *str = "Salut";
    int fd = -70003;
	
    cr_assert_eq(1, check_error(str, fd));
}

Test(cat, Test6)
{
    cr_assert_eq(84, cat(55, "a"));
}
