/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-minishell2-william1.piloz
** File description:
** dobleredirectright.c
*/

#include "minishell.h"

int create_filed(char *str)
{
    int fd;
    str = remove_space(str);
    fd = open(str, O_CREAT | O_APPEND | O_WRONLY, 0666);
    if (fd == -1)
        return (84);
    return (fd);
}

int errord(char **tab)
{
    int i;

    for (i = 0; tab[i] != NULL; i += 1);
    if (i < 2) {
        my_putstr(strerror(errno));
        my_putstr("\n");
        return (1);
    }
    return (0);
}

void redirect_double(char **tab, char **path, list_t *list, char **env)
{
    if (errord(tab) == 1)
        return;
    int fd = create_filed(tab[1]);
    pid_t pid = fork();
    int wstatus;

    if (pid == 0) {
        dup2(fd, 1);
        commande(path, tab[0], &list, env);
        close(fd);
        exit(0);
    } else {
        waitpid(pid, &wstatus, 0);
    }
    dup2(dup(1), 1);
    close(fd);
}