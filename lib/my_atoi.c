/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** my_atoi.c
*/

#include "minishell.h"

int my_atoi(char *str)
{
    int i = 0;
    int n = 1;

    if (*str == '-') {
        str++;
        n = (-1);
    }
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            i = i * 10;
            i = i + (*str - '0');
        } else {
            return (i);
        }
        str++;
    }
    i *= n;
    return (i);
}