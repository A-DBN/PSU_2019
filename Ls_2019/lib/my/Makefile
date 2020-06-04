##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	 =	my_putchar.c	\
		my_putstr.c	\
		my_put_nbr.c

OBJ	 =	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I../../include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f *.o
	rm -f ../../libmy.a
	rm -f ../my.h

re:	fclean all
