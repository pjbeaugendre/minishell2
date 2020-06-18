/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** redirect_exec
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

char *get_need_file(char **arr, char **arr2, char *str)
{
    if (arr[1] == NULL) {
        my_free_array(arr);
        my_pstrerr("Missing name for redirect.\n");
        return (NULL);
    } else {
        arr2 = my_str_to_word_array(arr[1], " ");
        str = my_strdup(arr2[0]);
        my_free_array(arr);
        my_free_array(arr2);
        return (str);
    }
}

char *get_need_redir(int p, char *line)
{
    char **arr = my_str_to_word_array(line, "><");
    char **arr2 = NULL;
    char *str = NULL;

    if (p == 0) {
        str = my_strdup(arr[0]);
        my_free_array(arr);
        return (str);
    }
    if (p == 1) {
        return (get_need_file(arr, arr2, str));
    }
    return (NULL);
}

int get_fd(info_t *inf, char *file, int nb_chev, char l_r)
{
    if (l_r == 'r') {
        inf->w_dup = 1;
        if (nb_chev == 1)
            inf->fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
        else if (nb_chev == 2)
            inf->fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0666);
    } else if (l_r == 'l') {
        inf->w_dup = 0;
        if (nb_chev == 1)
            inf->fd = open(file, O_RDONLY, 0666);
    }
    if (inf->fd == -1)
        return (1);
    else
        return (0);
    return (0);
}

int error_fd(info_t *inf, char *file, int nb_chev, char l_r)
{
    if (get_fd(inf, file, nb_chev, l_r)) {
        inf->return_val = 1;
        my_pstrerr(file);
        my_pstrerr(": No such file or directory.\n");
        return (1);
    }
    return (0);
}

void redirect_do(info_t *inf, char *line, char **arr, char *str)
{
    int nb_chev = getnb_chev(str);
    char l_r = str[1];
    char *cmd = get_need_redir(0, line);
    char *file = get_need_redir(1, line);

    if (file == NULL) {
        free(cmd);
        inf->return_val = 1;
        return;
    }
    if (error_fd(inf, file, nb_chev, l_r) == 1) {
        free(cmd);
        free(file);
        return;
    }
    free(file);
    make_algo(inf, arr, cmd, "\0");
    free(cmd);
}