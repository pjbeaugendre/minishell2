/*
** EPITECH PROJECT, 2020
** PSU_my_printf_2019
** File description:
** my
*/

#include <stdio.h>
#include <stdlib.h>

int my_getnbr(char const *str);

int my_printf(char *s, ...);

void my_putchar(char c);

int my_isneg(int n);

int my_putstr(char const *str);

char *my_revstr(char *str);

int my_showstr(char const *str);

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

void my_swap(int *a, int *b);

int my_put_nbr(int nb);

char **my_str_to_word_array(char *str, char *div);

int my_strcmp(char *str1, char *str2);

char *my_strcat(char *s1, char *s2);

int my_strncmp(char *str1, char *str2, int n);

int my_pstrerr(char const *str);

void my_putcherr(char c);

void my_free_array(char **array);

char *my_strdup(char *str);

void *my_malloc(size_t size);

void my_show_array(char **arr);