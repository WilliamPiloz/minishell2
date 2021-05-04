/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-minishell2-william1.piloz
** File description:
** main.c
*/

#include "minishell.h"

int parth(char *buff, char **path, list_t *list, char **env)
{
    if (parth_redirect_double(buff, path, list, env) == 1)
        return (1);
    if (parth_redirect(buff, path, list, env) == 1)
        return (1);
    if (parth_pip(buff, path, list, env) == 1)
        return (1);
    return (0);
}

void parth_first(char *buff, char **path, list_t *list, char **env)
{
    char **str;
    str = my_str_to_word_array2(buff, ';');
    for (int i = 0; str[i] != NULL; i += 1) {
        str[i] = remove_space(str[i]);
        if (parth_redirect_double(str[i], path, list, env) == 1)
            return;
        if (parth_redirect(str[i], path, list, env) == 1)
            return;
        if (parth_pip(str[i], path, list, env) == 1)
            return;
        commande(path, str[i], &list, env);
    }
}

int pathing(char **path, char *buff, list_t *list, char **env)
{
    int a = 0;
    for (int i = 0; buff[i] != '\0'; i += 1)
        if (buff[i] == ';')
            a += 1;
    if (a != 0) {
        parth_first(buff, path, list, env);
        return (1);
    } else {
        if (parth(buff, path, list, env) == 1)
            return (1);
    }
    return (0);
}

void game_loop(list_t *list, size_t len, char **path, char **env)
{
    char *buff = malloc(sizeof(char) * 40);

    while (getline(&buff, &len, stdin) != -1) {
        if (my_strlen(buff) - 1 == 0) {
            if (isatty(STDIN_FILENO) == 1)
                my_putstr("$> ");
            continue;
        }
        buff[my_strlen(buff) - 1] = '\0';
        if (pathing(path, buff, list, env) == 0) {
            commande(path, buff, &list, env);
            if (isatty(STDIN_FILENO) == 1)
                my_putstr("$> ");
        }
    }
    free(buff);
}

int main(int ac, char **av, char **env)
{
    list_t *list = NULL;
    size_t len = 0;
    (void) ac;
    (void) av;
    for (int i = 0; env[i] != NULL; i += 1)
        list_push_back(&list, env[i]);
    char **path = get_path(list);
    if (isatty(STDIN_FILENO) == 1)
        my_putstr("$> ");
    signal(SIGINT, SIG_IGN);
    game_loop(list, len, path, env);
    list_destroy(&list);
    free(path);
    return (0);
}