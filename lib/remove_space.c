/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-minishell2-william1.piloz
** File description:
** remove_space.c
*/

#include "minishell.h"

char *remove_space(char *str)
{
    int i = 0;
    int a = 0;
    char *dest = str;
    if (str[0] != ' ')
        return (str);
    for (; str[i] == ' ' && str[i] != '\0'; i++);
    for (; str[i] != '\0'; i++) {
        str[a] = dest[i];
        a++;
    }
    if (i != 0) {
        str[a] = '\0';
        return (str);
    }
    return (str);
}