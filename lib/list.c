/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-william1.piloz
** File description:
** list.c
*/

#include "minishell.h"

void list_push_back(list_t **list, char *value)
{
    list_t *node = malloc(sizeof(*node));
    list_t *temp;

    node->array = value;
    node->next = NULL;
    if ((*list) == NULL)
        (*list) = node;
    else {
        for (temp = (*list); temp->next != NULL; temp = temp->next);
        temp->next = node;
    }
}

void print_list(list_t **list)
{
    list_t *tmp = (*list);

    while (tmp != NULL) {
        my_putstr(tmp->array);
        my_putchar('\n');
        tmp = tmp->next;
    }
}

void list_destroy(list_t **list)
{
    list_t *node = (*list);

    if (node == NULL)
        return;
    while (node != NULL) {
        node = (*list)->next;
        free(*list);
        (*list) = node;
    }
}

void free_at(list_t **list, int index)
{
    list_t *tmp = (*list);
    list_t *node = (*list);

    if (*list == NULL)
        return;
    for (int i = 0; i != index - 1; i += 1) {
        node = tmp;
        tmp = tmp->next;
    }
    node->next = tmp->next;
    free(tmp);
}