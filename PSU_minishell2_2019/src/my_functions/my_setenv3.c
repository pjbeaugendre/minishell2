/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_setenv3
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

int change_line_value(char **arg, info_t *inf)
{
    char *res = NULL;

    res = my_strcat(arg[1], "=");
    res = my_strcat(res, arg[2]);
    inf->env[inf->setval] = my_strdup(res);
    return (0);
}

char **my_realloc_arr(info_t *inf, char *str)
{
    int size = 0;
    int j = 0;
    char **new_arr = NULL;

    for (; inf->env[size] != NULL; size++);
    size++;
    new_arr = my_malloc(sizeof(char *) * (size + 1));
    for (; inf->env[j] != NULL; j++) {
        new_arr[j] = my_strdup(inf->env[j]);
        free(inf->env[j]);
    }
    for (; j < size; j++)
        new_arr[j] = str;
    new_arr[j] = NULL;
    free(inf->env);
    return (new_arr);
}

int new_env_line_w_value(char **arg, info_t *inf)
{
    char *str = NULL;

    str = my_strcat(arg[1], "=");
    str = my_strcat(str, arg[2]);
    inf->env = my_realloc_arr(inf, str);
    return (0);
}