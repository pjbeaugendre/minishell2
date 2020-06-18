/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** env
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include "my.h"
#include "struct.h"
#include "functions.h"

void display_env(info_t *inf)
{
    int fd = 1;

    if (inf->need_dup > 0)
        fd = inf->fd;
    for (int i = 0; inf->env[i] != NULL; i++) {
        write(fd, inf->env[i], my_strlen(inf->env[i]));
        write(fd, "\n", 1);
    }
    if (inf->need_dup > 0) {
        inf->need_dup = 0;
        close(inf->fd);
    }
}

/*void pipe_dup(info_t *inf)
{
    int in = dup(0);
    int out = dup(1);

    if (inf->w_env_dup == 1) {

    } else if (inf->w_env_dup == 2) {

    }
}*/

int env(info_t *inf)
{
    display_env(inf);
    return (0);
}