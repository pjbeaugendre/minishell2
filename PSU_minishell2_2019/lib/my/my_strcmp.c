/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_strcmp
*/

int my_strcmp(char *str1, char *str2)
{
    for (int i = 0; str1[i] != 0 || str2[i] != 0; i++) {
        if (str1[i] != str2[i])
            return (1);
    }
    return (0);
}