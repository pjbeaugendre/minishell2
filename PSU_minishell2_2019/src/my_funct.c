/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_funct
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "struct.h"
#include "functions.h"

int my_functions(char **arg, info_t *inf, char **arr, char *l_free)
{
    if (my_strcmp(arg[0], "exit") == 0) {
        inf->return_val = my_exit(arg, inf, arr, l_free);
        return (1);
    } else if (my_strcmp(arg[0], "cd") == 0) {
        inf->return_val = cd(arg, inf);
        return (1);
    }
    if (my_strcmp(arg[0], "env") == 0) {
        inf->return_val = env(inf);
        return (1);
    } else if (my_strcmp(arg[0], "setenv") == 0) {
        inf->return_val = my_setenv(arg, inf);
        return (1);
    }
    if (my_strcmp(arg[0], "unsetenv") == 0) {
        inf->return_val = my_unsetenv(inf, arg);
        return (1);
    }
    return (0);
}

int exec_dir(char *line, char **arg, info_t *inf)
{
    char **arr = my_str_to_word_array(line, "/");
    struct stat n;

    if (arr[1] == NULL) {
        my_free_array(arr);
        return (0);
    }
    if (stat(arr[0], &n) != 1 && S_ISDIR(n.st_mode)) {
        if (access(arr[1], F_OK && X_OK)) {
            my_exec(line, arg, inf);
            my_free_array(arr);
            return (1);
        }
    }
    my_free_array(arr);
    return (0);
}

int new_loop(info_t *inf, char **arg, char **arr, char *l_free)
{
    char *str = NULL;

    if (my_functions(arg, inf, arr, l_free)) {
        return (1);
    } else if ((arg[0][0] == '/' && access((arg[0] + 1), F_OK)) ||
    (arg[0][0] == '.' && arg[0][1] == '/' && access(str, F_OK))) {
        my_exec(arg[0], arg, inf);
        return (1);
    }
    if (exec_dir(arg[0], arg, inf) == 1)
        return (1);
    if (inf->check_path == 1 && next_loop(inf, arg))
        return (1);
    return (0);
}

void make_algo(info_t *inf, char **arr, char *line, char *l_free)
{
    char **arg = NULL;

    arg = my_str_to_word_array(line, " ");
    if (new_loop(inf, arg, arr, l_free)) {
    } else {
        my_putstr(arg[0]);
        my_pstrerr(": Command not found.\n");
        inf->return_val = 1;
    }
    my_free_array(arg);
}

int w_functions(info_t *inf, char *line)
{
    char **arr = my_str_to_word_array(line, ";");
    int i = 0;
    int c = 0;

    while (arr[i]) {
        inf->need_dup = 0;
        c = check_redirect(arr[i]);
        if (c == 1) {
            inf->need_dup = 1;
            choose_do(inf, arr[i], arr, c);
            i++;
        } else {
            make_algo(inf, arr, arr[i], line);
            i++;
        }
    }
    my_free_array(arr);
    return (0);
}