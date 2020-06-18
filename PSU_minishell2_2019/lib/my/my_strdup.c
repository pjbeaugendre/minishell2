/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *str)
{
    int i = 0;
    int size = my_strlen(str);
    char *new = malloc(sizeof(char) * (size + 1));

    if (new == NULL)
        exit (84);
    for (; str[i] != '\0'; i++)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}