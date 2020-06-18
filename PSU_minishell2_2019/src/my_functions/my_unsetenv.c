/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_unsetenv
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

void my_unsetenv_do(info_t *inf, char *arg)
{
    int j = 0;
    int x = 0;
    int t = 0;
    char **new_arr = NULL;

    for (; inf->env[j] != NULL; j++);
    new_arr = my_malloc(sizeof(char *) * j);
    for (j = 0; inf->env[j] != NULL; j++, x++) {
        t = my_strlen(arg);
        if (my_strncmp(inf->env[j], arg, t) == 0 && (inf->env[j][t] == '='))
            j++;
        new_arr[x] = my_strdup(inf->env[j]);
        free(inf->env[j]);
    }
    new_arr[x] = NULL;
    inf->env = new_arr;
}

int my_unsetenv(info_t *inf, char **arg)
{
    if (arg[1] == NULL) {
        my_pstrerr("unsetenv: Too few arguments.\n");
        return (1);
    }
    if (arg[2] == NULL) {
        my_unsetenv_do(inf, arg[1]);
    } else {
        for (int i = 1; arg[i] != NULL; i++)
            my_unsetenv_do(inf, arg[i]);
    }
    return (0);
}