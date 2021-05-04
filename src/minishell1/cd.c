/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-william1.piloz
** File description:
** cd.c
*/

#include "minishell.h"

void my_cd3(list_cd *cd, char **env)
{
    my_strcat(cd->tmp, "OLDPWD=");
    my_strcat(cd->tmp, cd->pwd + 4);
    my_strcat(cd->tmp, "\0");
    env[cd->ind] = cd->tmp;
    env[cd->inp] = cd->tmp2;
}

void more(list_cd *cd, const char *path)
{
    if (path[0] == '/') {
        chdir(path);
        my_strcat(cd->tmp2, "PWD=");
        my_strcat(cd->tmp2, path);
    } else {
        my_strcat(cd->array, cd->pwd + 4);
        my_strcat(cd->array, "/");
        my_strcat(cd->array, path);
        chdir(cd->array);
        my_strcat(cd->tmp2, "PWD=");
        my_strcat(cd->tmp2, cd->array);
    }
}

void my_cd2(const char *path, list_cd *cd, char **env)
{
    if (my_strlen(path) == 0) {
        chdir(cd->home+5);
        my_strcat(cd->tmp2, "PWD=");
        my_strcat(cd->tmp2, cd->home + 5);
    } else if (my_strncmp(path, "-", my_strlen(path)) == 0) {
        chdir(cd->oldpwd+7);
        my_strcat(cd->tmp2, "PWD=");
        my_strcat(cd->tmp2, cd->oldpwd + 7);
    } else
        more(cd, path);
    my_cd3(cd, env);
}

void cd_1(list_cd *cd, char **env, const char *path)
{
    for (int i = 0; env[i] != NULL; i += 1) {
        if (my_strncmp(env[i], "PWD", 3) == 0) {
            cd->pwd = env[i];
            cd->inp = i;
        }
        if (my_strncmp(env[i], "HOME", 4) == 0)
            cd->home = env[i];
        if (my_strncmp(env[i], "OLDPWD", 6) == 0) {
            cd->oldpwd = env[i];
            cd->ind = i;
        }
    }
    my_cd2(path, cd, env);
}

void my_cd(const char *path, char **env)
{
    list_cd cd = {0};
    if (my_strlen(path) != 0 && chdir(path) == -1 &&
    my_strncmp(path, "-", 1) != 0) {
        my_putstr(path);
        my_putstr(": ");
        my_putstr(strerror(errno));
        my_putstr(".\n");
        return;
    }
    cd.pwd = malloc(sizeof(char) * 1024);
    cd.oldpwd = malloc(sizeof(char) * 1024);
    cd.home = malloc(sizeof(char) * 1024);
    cd.array = malloc(sizeof(char) * 1024);
    cd.tmp = malloc(sizeof(char) * 1024);
    cd.tmp2 = malloc(sizeof(char) * 1024);
    cd_1(&cd, env, path);
}