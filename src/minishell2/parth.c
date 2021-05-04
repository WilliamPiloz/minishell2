/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-minishell2-william1.piloz
** File description:
** parth.c
*/

#include "minishell.h"

int parth_pip(char *str, char **path, list_t *list, char **env)
{
    int a = 0;
    char **tab;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '|')
            a += 1;
    }
    if (a != 0) {
        tab = my_str_to_word_array2(str, '|');
        pip(tab, path, list, env);
        return (1);
    }
    return (0);
}

int parth_redirect_double(char *str, char **path, list_t *list, char **env)
{
    int a = 0;
    char **tab;
    for (int i = 1; str[i] != '\0'; i += 1) {
        if (str[i] == '>' && str[i - 1] == '>')
            a += 1;
    }
    if (a != 0) {
        tab = my_str_to_word_array2(str, '>');
        redirect_double(tab, path, list, env);
        return (1);
    }
    return (0);
}

int parth_redirect(char *str, char **path, list_t *list, char **env)
{
    int a = 0;
    int i = 0;
    char **tab;
    for (i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '>')
            a += 1;
    }
    if (a != 0) {
        tab = my_str_to_word_array2(str, '>');
        redirect(tab, path, list, env);
        return (1);
    }
    return (0);
}