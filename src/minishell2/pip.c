/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-minishell2-william1.piloz
** File description:
** pip.c
*/

#include "minishell.h"

void simple_pip(char **tab, char **path, list_t *list, char **env)
{
    tab[0] = remove_space(tab[0]);
    tab[1] = remove_space(tab[1]);
    int pipeA[2];
    pipe(pipeA);
    if (fork() == 0) { dup2(pipeA[1], 1);
        close(pipeA[0]);
        close(pipeA[1]);
        commande(path, tab[0], &list, env);
        if (isatty(STDIN_FILENO) == 1)
            my_putstr("$> ");
        exit(0);
    }
    if (fork() == 0) { dup2(pipeA[0], 0);
        close(pipeA[0]);
        close(pipeA[1]);
        commande(path, tab[1], &list, env);
        if (isatty(STDIN_FILENO) == 1)
            my_putstr("$> ");
        exit(0);
    }
}

void double_pip(char **tab, char **path, list_t *list, char **env)
{
}

void pip(char **tab, char **path, list_t *list, char **env)
{
    int i = 0;
    for (; tab[i] != NULL; i += 1);

    if (i == 2)
        simple_pip(tab, path, list, env);
    else
        double_pip(tab, path, list, env);
}