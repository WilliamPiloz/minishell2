/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-william1.piloz
** File description:
** path.c
*/

#include "minishell.h"

void find_path(char **path, char *command, char **com)
{
    char *array = malloc(sizeof(char) * 80);
    if (access(command, F_OK) == 0) {
        my_excev(command, com);
        free(array);
        return;
    }
    for (int i = 0; path[i] != NULL; i++) {
        my_strcat(array, path[i]);
        my_strcat(array, "/");
        my_strcat(array, command);
        if (access(array, F_OK) == 0) {
            my_excev(array, com);
            return;
        }
        array[0] = '\0';
    }
    my_putstr(command);
    my_putstr(": Command not found.\n");
    free(array);
    return;
}

char **get_path(list_t *list)
{
    list_t *tmp = list;
    char **path;
    while (tmp->array != NULL) {
        if (my_strncmp("PATH", tmp->array, 4) == 0)
            break;
        tmp = tmp->next;
    }
    path = my_str_to_word_array2(tmp->array, ':');
    return (path);
}
