/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** put number of characters
*/

#include "minishell.h"

int my_strlen(char const *str)
{
    int n = 0;
    for (; str[n] != '\0'; n = n + 1);
    return (n);
}
