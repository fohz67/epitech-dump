/*
** EPITECH PROJECT, 2022
** test_cat.c
** File description:
** Test cat
*/

#include <criterion/criterion.h>
#include <stdio.h>

int grep(int, char *);
int check_error(char *, int);

Test(grep, Test1)
{
    char *str = "Hello";
    int fd = -1;
	
    cr_assert_eq(0, check_error(str, fd));
}

Test(grep, Test2)
{
    char *str = "Enchantée";
    int fd = 10;
	
    cr_assert_eq(0, check_error(str, fd));
}

Test(grep, Test3)
{
    char *str = "Bonjour";
    int fd = 100420;
	
    cr_assert_eq(0, check_error(str, fd));
}

Test(grep, Test4)
{
    char *str = "Aurevoir";
    int fd = 100421;
	
    cr_assert_eq(2, check_error(str, fd));
}

Test(grep, Test5)
{
    char *str = "Salut";
    int fd = 100422;
	
    cr_assert_eq(2, check_error(str, fd));
}
