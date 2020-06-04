##
## EPITECH PROJECT, 2019
## info_file
## File description:
## info_file
##

SRC	=	main.c	\
		options.c	\
		game.c	\
		debug.c

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

CFLAGS	= -I./include -L./lib/my -lmy -W -Wall -Wextra -lncurses

all:	$(NAME)

$(NAME)	:
			make -C ./lib/my
			gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f *.o
	rm -f lib/my/*.o
	rm -f lib/my/libmy.a
	rm -f *~

fclean:	clean
		rm -f $(NAME)

re:	fclean all
