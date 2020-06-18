/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** utils
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

int check_error(int ac)
{
    if (ac != 1)
        return (1);
    return (0);
}

int check_use_path(info_t *inf)
{
    for (int j = 0; inf->env[j] != NULL; j++) {
        if (my_strncmp(inf->env[j], "PATH=", 5) == 0
        && inf->env[j][5] != '\0') {
            inf->check_path = 1;
            return (0);
        }
    }
    inf->check_path = 0;
    return (0);
}

void free_myshell(info_t *inf)
{
    my_free_array(inf->path);
    my_free_array(inf->env);
    free(inf);
}

void my_getpath(info_t *inf)
{
    int j = 0;

    for (; inf->env[j] != NULL; j++) {
        if (inf->env[j][0] == 'P' && inf->env[j][1] == 'A'
        && inf->env[j][2] == 'T' && inf->env[j][3] == 'H'
        && inf->env[j][4] == '=') {
            inf->path = my_str_to_word_array(inf->env[j], "=:");
        }
    }
}

int empty_line(char *line)
{
    int i = 0;

    for (; line[i] != '\n'; i++) {
        if (line[i] != '\t' && line[i] != ' ' && line[i] != ';')
            return (0);
    }
    return (1);
}