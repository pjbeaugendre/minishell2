##
## EPITECH PROJECT, 2019
## PSU_minishell1_2019
## File description:
## Makefile
##

SRC	=	src/my_functions/my_cd.c 		\
		src/my_functions/my_cd_utils.c 	\
		src/my_functions/my_env.c 		\
		src/my_functions/my_exit.c 		\
		src/my_functions/my_setenv.c 	\
		src/my_functions/my_setenv2.c 	\
		src/my_functions/my_setenv3.c	\
		src/my_functions/my_unsetenv.c 	\
		src/redirections/redirections.c \
		src/redirections/redirections_utils.c \
		src/redirections/redirect_exec.c 	\
		src/my_funct.c 					\
		src/fill_env.c					\
		src/my_prompt.c 				\
		src/my_exec.c 					\
		src/utils.c 					\
		src/main.c

OBJ		=	$(SRC:.c=.o)

NAME	= 	mysh

CFLAGS = -I./include -Wall -Wextra

LIB_PATH = ./lib

all:	$(NAME)

$(NAME):	$(OBJ)
	make re -C lib/my
	gcc $(OBJ) -o $(NAME) -L$(LIB_PATH) -lmy

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all
