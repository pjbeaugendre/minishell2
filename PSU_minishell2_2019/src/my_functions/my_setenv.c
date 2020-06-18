/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_setenv
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

int two_arg(char **arg, info_t *inf)
{
    if (check_line(arg[1], inf) == 1) {
        change_line_value_to_null(arg[1], inf);
        return (1);
    } else {
        new_env_line(arg[1], inf);
        return (1);
    }
    return (0);
}

int three_arg(char **arg, info_t *inf)
{
    if (check_line(arg[1], inf) == 1) {
        change_line_value(arg, inf);
        return (1);
    } else {
        new_env_line_w_value(arg, inf);
        return (1);
    }
    return (0);
}

int my_setenv(char **arg, info_t *inf)
{
    if (arg[1] == NULL) {
        env(inf);
        return (0);
    } else if (check_setenv_err(arg) == 1)
        return (1);
    if (arg[2] == NULL) {
        if (two_arg(arg, inf) == 1)
            return (0);
    }
    if (arg[3] == NULL) {
        if (three_arg(arg, inf) == 1)
            return (0);
    } else {
        my_pstrerr("setenv: Too many arguments.\n");
        return (1);
    }
    return (0);
}