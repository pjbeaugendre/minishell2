/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *s1, char *s2)
{
    int j = 0;
    int x = 0;
    int size1 = my_strlen(s1);
    int size2 = my_strlen(s2);
    char *res = malloc(sizeof(char) * (size1 + size2 + 1));

    if (res == NULL)
        exit(84);
    for (; s1[j] != '\0'; j++)
        res[j] = s1[j];
    for (; s2[x] != '\0'; j++, x++)
        res[j] = s2[x];
    res[j] = '\0';
    return (res);
}