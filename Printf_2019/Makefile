##
## EPITECH PROJECT, 2019
## Makfile
## File description:
## Makefile
##

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_printf.c	\
		my_getnbr.c	\
		my_putstr.c

OBJ	 =	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I./include

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
