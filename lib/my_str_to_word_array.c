/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** my_str_to_word_array.c
*/

#include "minishell.h"

char *my_dup(char const *src)
{
    char *dup;
    int len = my_strlen(src);

    dup = malloc(sizeof(char) * (len + 1));
    for (int i = 0; src[i] != '\0'; i = i + 1)
        dup[i] = src[i];
    dup[len] = '\0';
    return dup;
}

void check_str(char **array, char *temp, int *a, int *k)
{
    if (*a != 0) {
        temp[*a] = '\0';
        *a = 0;
        array[*k] = my_dup(temp);
        *k += 1;
    }
}

char **my_str_to_word_array(char *str)
{
    char **array = malloc(sizeof(char *) * (my_strlen(str) + 1));
    char temp[512];
    int i = 0;
    int a = 0;
    int k = 0;
    for (; str[i] != '\0'; i += 1) {
        if (str[i] != ' ' && str[i] != '\t') {
            temp[a] = str[i];
            a += 1;
        } else {
            check_str(array, temp, &a, &k);
        }
    }
    check_str(array, temp, &a, &k);
    array[k] = NULL;
    return (array);
}

char **my_str_to_word_array2(char *str, char sep)
{
    char **array = malloc(sizeof(char *) * (my_strlen(str) + 1));
    char temp[512];
    int i = 0;
    int a = 0;
    int k = 0;
    for (; str[i] != '\0'; i += 1) {
        if (str[i] != sep) {
            temp[a] = str[i];
            a += 1;
        } else {
            check_str(array, temp, &a, &k);
        }
    }
    check_str(array, temp, &a, &k);
    array[k] = NULL;
    return (array);
}