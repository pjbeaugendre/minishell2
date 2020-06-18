/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_exit
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"
#include "functions.h"

int check_num(char *arg)
{
    if (arg[0] < '0' || arg[0] > '9') {
        my_pstrerr("exit: Expression Syntax.\n");
        return (1);
    }
    for (int i = 0; arg[i] != '\0'; i++) {
        if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '\n') {
            my_pstrerr("exit: Badly formed number.\n");
            return (1);
        }
    }
    return (0);
}

void my_exit_leave(char **arg, info_t *inf, char **arr, char *l_free)
{
    int temp = 0;

    if (check_num(arg[1]) == 0) {
        temp = my_getnbr(arg[1]);
        my_putstr("exit\n");
        free_myshell(inf);
        my_free_array(arg);
        my_free_array(arr);
        if (l_free[0] != '\0')
            free(l_free);
        exit(temp);
    }
}

int my_exit(char **arg, info_t *inf, char **arr, char *l_free)
{
    if (arg[1] == NULL) {
        my_putstr("exit\n");
        my_free_array(arg);
        my_free_array(arr);
        free_myshell(inf);
        if (l_free[0] != '\0')
            free(l_free);
        exit(0);
    } else if (arg[1] != NULL && arg[2] == NULL) {
        my_exit_leave(arg, inf, arr, l_free);
    } else {
        my_pstrerr("exit: Expression Syntax.\n");
        return (1);
    }
    return (0);
}