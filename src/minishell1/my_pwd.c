/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-william1.piloz
** File description:
** my_pwd.c
*/

#include "minishell.h"

void my_pwd(void)
{
    char pwd[1024];
    getcwd(pwd, sizeof(pwd));
    my_putstr(pwd);
    my_putchar('\n');
}