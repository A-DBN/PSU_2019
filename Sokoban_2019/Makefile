##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## sokoban
##

SRC     =	sokoban_h.c	\
			movements.c	\
			open_window.c	\
			my_sokoban.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g -L./lib/my -lmy -I./include -lncurses

NAME    =       my_sokoban

all:    $(NAME)

$(NAME)	:	$(OBJ)
			make -C lib/my
			gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	make -C lib/my clean
	rm -f *.o
	rm -f *~
	rm -f vgcore.*

fclean: clean
		make -C lib/my fclean
		rm -f $(NAME)
		rm -f lib/my/libmy.a

re:     fclean all
