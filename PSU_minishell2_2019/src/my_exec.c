/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_exec
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include "my.h"
#include "struct.h"
#include "functions.h"

int execution(char **arg, char *str, info_t *inf)
{
    char *cmd = NULL;
    char *cmd_access = my_strcat(str, arg[0]);

    if (access(cmd_access, F_OK && X_OK) == 0) {
        cmd = my_strcat(str, arg[0]);
        my_exec(cmd, arg, inf);
        free(cmd);
        free(cmd_access);
        return (1);
    }
    free(cmd);
    free(cmd_access);
    return (0);
}

int next_loop(info_t *inf, char **arg)
{
    for (int i = 0; inf->path[i] != NULL; i++) {
        char *str = NULL;
        str = my_strcat(inf->path[i], "/");
        if (execution(arg, str, inf)) {
            free(str);
            return (1);
        }
        free(str);
    }
    return (0);
}

void cond_exit(info_t *inf, int gg)
{
    char *str = strsignal(WTERMSIG(gg));

    if (WIFEXITED(gg)) {
        inf->return_val = WEXITSTATUS(gg);
        return;
    }
    if (my_strncmp("Killed", str, 6) && WIFSIGNALED(gg)) {
        if (my_strncmp(strsignal(WTERMSIG(gg)),
        "Floating point exception", 24) == 0) {
            inf->return_val = WTERMSIG(gg) + 128;
            my_pstrerr("Floating exception");
        } else {
            inf->return_val = WTERMSIG(gg) + 128;
            my_pstrerr(str);
        }
        if (WCOREDUMP(gg)) {
            inf->return_val = WTERMSIG(gg) + 128;
            my_pstrerr(" (core dumped)");
        }
        my_pstrerr("\n");
    }
}

void check_dup(info_t *inf)
{
    if (inf->need_dup == 1) {
        dup2(inf->fd, inf->w_dup);
        close(inf->fd);
    } else if (inf->need_dup == 2) {
        close(inf->w_close);
        dup2(inf->fd, inf->w_dup);
        close(inf->fd);
    }
}

int my_exec(char *cmd, char **arg, info_t *inf)
{
    pid_t pid;
    int gg = 0;

    while ((pid = fork()) == 0) {
        check_dup(inf);
        gg = execve(cmd, arg, inf->env);
        my_pstrerr(cmd);
        my_pstrerr(": ");
        my_pstrerr(strerror(errno));
        my_pstrerr(".\n");
        exit(1);
    }
    waitpid(pid, &gg, 0);
    cond_exit(inf, gg);
    return (0);
}