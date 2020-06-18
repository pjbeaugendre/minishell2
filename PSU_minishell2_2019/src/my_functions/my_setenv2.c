/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_setenv2
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "my.h"
#include "struct.h"
#include "functions.h"

int check_setenv_err(char **arg)
{
    if ((arg[1][0] < 'a' || arg[1][0] > 'z') && arg[1][0] != '_'
    && (arg[1][0] < 'A' || arg[1][0] > 'Z')) {
        my_pstrerr("setenv: Variable name must begin with a letter.\n");
        return (1);
    }
    for (int i = 0; arg[1][i] != '\0'; i++) {
        if ((arg[1][i] < '0' || arg[1][i] > '9')
        && (arg[1][i] < 'a' || arg[1][i] > 'z') && arg[1][i] != '_'
        && (arg[1][i] < 'A' || arg[1][i] > 'Z')) {
            my_pstrerr("setenv: Variable name must contain ");
            my_pstrerr("alphanumeric characters.\n");
            return (1);
        }
    }
    return (0);
}

int check_line(char *arg, info_t *inf)
{
    int j = 0;
    int t = 0;
    inf->setval = 0;

    for (; inf->env[j] != NULL; j++) {
        t = my_strlen(arg);
        if (my_strncmp(inf->env[j], arg, t) == 0
        && (inf->env[j][t] == '=')) {
            inf->setval = j;
            return (1);
        }
    }
    return (0);
}

int change_line_value_to_null(char *arg, info_t *inf)
{
    char *res = NULL;

    res = my_strcat(arg, "=");
    res = my_strcat(res, "\0");
    inf->env[inf->setval] = res;
    return (0);
}

int new_env_line(char *arg, info_t *inf)
{
    char *str = NULL;

    str = my_strcat(arg, "=");
    inf->env = my_realloc_arr(inf, str);
    return (0);
}