/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-william1.piloz
** File description:
** minishell.h
*/

#ifndef __MINISHELL__
#define __MINISHELL__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct list_t {
    char *array;
    struct list_t *next;
}list_t;

typedef struct list_cd {
    int ind;
    int inp;
    char *pwd;
    char *oldpwd;
    char *home;
    char *array;
    char *tmp;
    char *tmp2;
}list_cd;

char **my_str_to_word_array(char *str);
char **my_str_to_word_array2(char *str, char sep);
void list_push_back(list_t **list, char *value);
void list_destroy(list_t **list);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
void my_putchar(char c);
int my_putstr(char const *str);
int my_atoi(char *str);
void print_list(list_t **list);
void free_at(list_t **list, int index);
char *remove_space(char *str);

void my_cd(const char *path, char **env);
void my_pwd(void);
void my_excev(char *path, char **buff);
void find_path(char **path, char *command, char **com);
char **get_path(list_t *list);
void my_setenv(char *name, list_t **list);
void my_setenv_value(char *name, char *value, list_t **list);
void my_unsetenv(char *name, list_t **list);
int commande(char **path, char *buff, list_t **list, char **env);
void redirect(char **tab, char **path, list_t *list, char **env);
void redirect_double(char **tab, char **path, list_t *list, char **env);
int parth_redirect_double(char *str, char **path, list_t *list, char **env);
int parth_redirect(char *str, char **path, list_t *list, char **env);
int parth_pip(char *str, char **path, list_t *list, char **env);
void pip(char **tab, char **path, list_t *list, char **env);

#endif