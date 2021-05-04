/*
** EPITECH PROJECT, 2020
** B-CPE-110-MPL-1-1-bsbsq-william1.piloz
** File description:
** my_putstr.c
*/

#include "minishell.h"

int my_putstr(char const *str)
{
    int i = 0;
    int n = 0;
    for (n = 0; str[n]; n = n + 1);
    for (i = 0; i < n; i = i + 1) {
        my_putchar(str[i]);
    }
    return (0);
}