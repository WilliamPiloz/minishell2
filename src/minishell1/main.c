/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-william1.piloz
** File description:
** main.c
*/

#include "minishell.h"

int com2(char *buff, list_t **list, char **env)
{
    if (my_strncmp("exit", buff, 4) == 0 && my_strlen(buff) == 4)
        exit(0);
    if (my_strncmp("pwd", buff, 3) == 0 && my_strlen(buff) == 3) {
        my_pwd();
        return (0);
    }
    if (my_strncmp("cd", buff, 2) == 0) {
        my_cd(buff + 3, env);
        return (0);
    }
    if (my_strncmp("env", buff, 3) == 0 && my_strlen(buff) == 3) {
        print_list(list);
        return (0);
    }
    return (1);
}

int select_setenv(char **com, list_t **list, int i)
{
    if (i >= 3) {
        my_setenv_value(com[1], com[2], list);
        return (0);
    }
    if (i == 2) {
        my_setenv(com[1], list);
        return (0);
    }
    return (0);
}

int my_env(char **com, list_t **list)
{
    int i = 0;

    for (i = 0; com[i] != NULL; i += 1);
    if (my_strncmp("setenv", com[0], 6) == 0 && i == 1) {
        print_list(list);
        return (0);
    }
    if (my_strncmp("setenv", com[0], 6) == 0 && my_strlen(com[0]) == 6)
        return (select_setenv(com, list, i));
    if (my_strncmp("unsetenv", com[0], 8) == 0 && i == 1) {
        my_putstr("unsetenv: Too few arguments.\n");
        return (0);
    }
    if (my_strncmp("unsetenv", com[0], 8) == 0 && my_strlen(com[0]) == 8) {
        my_unsetenv(com[1], list);
        return (0);
    }
    return (1);
}

int commande(char **path, char *buff, list_t **list, char **env)
{
    char **com;

    if (com2(buff, list, env) == 0)
        return (0);
    com = my_str_to_word_array(buff);
    if (my_env(com, list) == 0)
        return (0);
    find_path(path, com[0], com);
    return (0);
}