/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-william1.piloz
** File description:
** my_unsetenv.c
*/

#include "minishell.h"

void my_unsetenv(char *name, list_t **list)
{
    list_t *tmp = (*list);
    int i = 0;
    while (tmp != NULL) {
        i += 1;
        if (my_strncmp(tmp->array, name, my_strlen(name)) == 0) {
            free_at(list, i);
            break;
        }
        tmp = tmp->next;
    }
}