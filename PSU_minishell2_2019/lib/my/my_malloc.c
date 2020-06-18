/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** my_malloc
*/

#include <stddef.h>
#include <stdlib.h>

void *my_malloc(size_t size)
{
    void *last = NULL;

    if (size == 0)
        return (0);
    last = malloc(size);
    if (last == NULL)
        exit(84);
    return (last);
}