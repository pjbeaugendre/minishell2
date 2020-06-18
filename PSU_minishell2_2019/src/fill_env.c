/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** fill_env
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"
#include "functions.h"

void new_env(char **envp, info_t *inf)
{
    char **new = NULL;
    int size = 0;
    int j = 0;
    int i = 0;

    for (j = 0; envp[j] != NULL; j++)
    j++;
    new = my_malloc(sizeof(char *) * (j + 1));
    for (j = 0; envp[j] != NULL; j++) {
        size = my_strlen(envp[j]) + 1;
        new[j] = my_malloc(sizeof(char) * size);
        for (i = 0; envp[j][i] != '\0'; i++)
            new[j][i] = envp[j][i];
        new[j][i] = '\0';
    }
    new[j] = NULL;
    inf->env = new;
}