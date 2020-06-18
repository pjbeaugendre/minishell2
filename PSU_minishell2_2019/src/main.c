/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"
#include "functions.h"

void my_shell1(info_t *inf, int temp)
{
    size_t len = 0;
    ssize_t status = 0;

    while (1) {
        char *line = NULL;
        my_prompt();
        check_use_path(inf);
        status = getline(&line, &len, stdin);
        temp = inf->return_val;
        if (status == -1) {
            free_myshell(inf);
            free(line);
            exit(temp);
        }
        for (int i = 0; line[i]; i++)
            line[i] = (line[i] == '\t') ? ' ' : line[i];
        if ((empty_line(line) != 1))
            w_functions(inf, line);
        free(line);
    }
}

int main(int ac, char **av, char **envp)
{
    info_t *inf = malloc(sizeof(info_t) * 1);
    inf->return_val = 0;
    int temp = 0;

    if (inf == NULL)
        return (84);
    if (check_error(ac) == 1)
        return (84);
    (void)(av);
    new_env(envp, inf);
    my_getpath(inf);
    my_shell1(inf, temp);
    return (0);
}