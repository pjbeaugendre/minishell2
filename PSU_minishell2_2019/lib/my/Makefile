##
## EPITECH PROJECT, 2019
## day10
## File description:
## Makefile
##

SRC	=	my_getnbr.c				\
		my_isneg.c				\
		my_putchar.c			\
		my_putcherr.c			\
		my_putstr.c				\
		my_pstrerr.c			\
		my_revstr.c				\
		my_showstr.c			\
		my_strcpy.c 			\
		my_strlen.c				\
		my_put_nbr.c 			\
		my_str_to_word_array.c 	\
		my_strcmp.c 			\
		my_strncmp.c 			\
		my_strcat.c 			\
		my_free_array.c			\
		my_strdup.c 			\
		my_malloc.c 			\
		my_show_array.c 		\
		my_swap.c

NAME	= libmy.a

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ./../
	cp my.h ./../../include/

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re: fclean all
