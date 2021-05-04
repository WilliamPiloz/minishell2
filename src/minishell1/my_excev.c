/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-minishell1-william1.piloz
** File description:
** my_excev.c
*/

#include "minishell.h"

void my_excev(char *path, char **buff)
{
    pid_t pid = fork();
    int wstatus;

    if (pid == 0) {
        execve(path, &buff[0], &buff[1]);
        exit(0);
    } else {
        waitpid(pid, &wstatus, 0);
        if (WIFSIGNALED(wstatus)) {
            if (WTERMSIG(wstatus) == SIGFPE)
                write(2, "Floting exception", 18);
            if (WTERMSIG(wstatus) == SIGSEGV)
                write(2, "Segmentation fault", 19);
            if (WCOREDUMP(wstatus))
                write(2, "(core dumped)\n", 15);
            else
                write(2, "\n", 1);
        }
    }
}