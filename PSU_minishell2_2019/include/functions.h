/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "struct.h"

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

int main(int ac, char **av, char **envp);

void new_env(char **envp, info_t *inf);

int cd(char **arg, info_t *inf);

int env(info_t *inf);

void my_prompt(void);

void my_getpath(info_t *inf);

void my_shell1(info_t *inf, int temp);

int my_exec(char *str, char **av, info_t *inf);

int my_exit(char **arg, info_t *inf, char **arr, char *l_free);

int w_functions(info_t *inf, char *line);

int my_setenv(char **arg, info_t *inf);

int change_line_value_to_null(char *arg, info_t *inf);

int change_line_value(char **arg, info_t *inf);

int new_env_line_w_value(char **arg, info_t *inf);

char **my_realloc_arr(info_t *inf, char *str);

int check_setenv_err(char **arg);

int my_functions(char **arg, info_t *inf, char **arr, char *l_free);

int two_arg(char **arg, info_t *inf);

int three_arg(char **arg, info_t *inf);

int my_unsetenv(info_t *inf, char **arg);

int check_line(char *arg, info_t *inf);

int new_env_line(char *arg, info_t *inf);

int empty_line(char *line);

int do_cd(info_t *inf, char *arg);

void edit_pwd_old(info_t *inf, char *str, char *pwd);

void display_cd_error(char *str);

char *get_oldpwd(info_t *inf);

char *get_home(info_t *inf);

void check_oldpwd(info_t *inf);

void free_myshell(info_t *inf);

int next_loop(info_t *inf, char **arg);

int getnb_chev(char *str);

void make_algo(info_t *inf, char **arr, char *line, char *l_free);

int check_redirect(char *str);

void choose_do(info_t *inf, char *line, char **arr, int c);

int check_error(int ac);

int check_use_path(info_t *inf);

void redirect_do(info_t *inf, char *line, char **arr, char *str);

#endif