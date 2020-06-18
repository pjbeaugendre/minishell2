/*
** EPITECH PROJECT, 2020
** MUL_my_radar_2019
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>

int c_c2(char c, char *div)
{
    for (int i = 0; div[i]; i++)
        if (c == div[i] || c == '\0' || c == '\n')
            return (0);
    return (1);
}

int array_size(char *str, char *div)
{
    int res = 0;

    if (c_c2(str[0], div))
        res++;
    for (int a = 0; str[a] != '\0'; a++) {
        if (!c_c2(str[a], div) && c_c2(str[a + 1], div))
            res++;
    }
    return (res);
}

int word_size(char const *str, int len, char  *div)
{
    int count = 0;

    for (; str[len] != '\0'; len++, count++) {
        if (c_c2(str[len], div) == 0)
            return (count);
    }
    return (count);
}

char **my_str_to_word_array(char *s, char *d)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int size = array_size(s, d);
    char **res = malloc(sizeof(char *) * (size + 1));

    if (res == NULL)
        exit(84);
    for (; j < size; j++) {
        for (x = x; s[x] == '\t' || s[x] == ' ' || (c_c2(s[x], d) == 0); x++);
        res[j] = malloc(sizeof(char) * (word_size(s, x, d) + 1));
        for (i = 0; s[x] != '\0' && c_c2(s[x], d) != 0; i++) {
            res[j][i] = s[x];
            x++;
        }
        res[j][i] = '\0';
        x++;
    }
    res[j] = NULL;
    return (res);
}