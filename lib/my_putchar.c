/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-william1.piloz
** File description:
** my_putchar.c
*/

#include "minishell.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}