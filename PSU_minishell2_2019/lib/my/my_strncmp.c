/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_strncpy
*/

int my_strncmp(char *str1, char *str2, int n)
{
    int j = 0;

    for (; j < n && str1[j] != '\0' && str2[j] != '\0'; j++) {
        if (str1[j] != str2[j])
            return (1);
    }
    return (0);
}