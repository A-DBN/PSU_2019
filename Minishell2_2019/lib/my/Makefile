##
## EPITECH PROJECT, 2019
## Makfile
## File description:
## Makefile
##

SRC	=	my_putchar.c	\
		my_strlen.c	\
		my_put_nbr.c	\
		my_strstr.c	\
		my_str_to_word_array.c	\
		my_getnbr.c	\
		my_str_isnum.c	\
		my_strcmp.c	\
		my_putstr.c	\
		my_strncmp.c	\
		my_newstrstr.c	\
		my_cleanstr.c

OBJ	 =	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
