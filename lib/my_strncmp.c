/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** function that compare n bytes of two strings
*/

#include "minishell.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int size;

    if (n == 0) {
        return (0);
    } else if (n < 0) {
        n = my_strlen(s1) - n;
    }
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && n > 1) {
        i++;
        n--;
    }
    size = s1[i] - s2[i];
    return (size);
}
