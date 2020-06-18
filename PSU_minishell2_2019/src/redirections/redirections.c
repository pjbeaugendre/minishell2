/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** redirections
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

int check_cmd(info_t *inf, char *line)
{
    int x = 0;

    for (int i = 0; line[i]; i++) {
        if (line[i] == '>' || line[i] == '<')
            break;
        if (line[i] != ' ')
            x++;
    }
    if (x == 0) {
        my_pstrerr("Invalid null command.\n");
        inf->return_val = 1;
        return (1);
    }
    return (0);
}

int choose_redir(info_t *inf, char *line, char **arr)
{
    for (int i = 0; line[i]; i++) {
        if (line[i] == '>' && line[i + 1] == '>') {
            redirect_do(inf, line, arr, "2r");
            return (1);
        } else if (line[i] == '>') {
            redirect_do(inf, line, arr, "1r");
            return (1);
        }
        if (line[i] == '<' && line[i + 1] == '<') {
            redirect_do(inf, line, arr, "2l");
            return (1);
        } else if (line[i] == '<') {
            redirect_do(inf, line, arr, "1l");
            return (1);
        }
    }
    return (0);
}

void choose_do(info_t *inf, char *line, char **arr, int c)
{
    if (c == 1) {
        if (check_cmd(inf, line))
            return;
        if (choose_redir(inf, line, arr) == 1)
            return;
    }
}