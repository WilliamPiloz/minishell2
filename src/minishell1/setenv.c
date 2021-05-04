/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-william1.piloz
** File description:
** setenv.c
*/

#include "minishell.h"

int chec_str(char *name)
{
    for (int i = 0; name[i] != '\0'; i += 1) {
        if (!((name[i] <= 'Z' && name[i] >= 'A') ||
        (name[i] <= 'z' && name[i] >= 'a') ||
        (name[i] <= '9' && name[i] >= '0'))) {
            my_putstr("setenv: Variable name must contain");
            my_putstr(" alphanumeric characters.\n");
            return (1);
        }
    }
    return (0);
}

void my_setenv_value(char *name, char *value, list_t **list)
{
    char *str;

    if (chec_str(name) == 1)
        return;
    str = malloc(sizeof(char) * (my_strlen(name) + my_strlen(value) + 1));
    my_strcat(str, name);
    my_strcat(str, "=");
    my_strcat(str, value);
    list_push_back(list, str);
}

void my_setenv(char *name, list_t **list)
{
    char *str;
    if (chec_str(name) == 1)
        return;
    str = malloc(sizeof(char) * (my_strlen(name)));
    my_strcat(str, name);
    my_strcat(str, "=");
    list_push_back(list, str);
}