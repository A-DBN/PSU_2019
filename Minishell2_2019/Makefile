##
## EPITECH PROJECT, 2019
## info_file
## File description:
## info_file
##

SRC	=	src/exec.c	\
		src/env.c	\
		src/redirec.c	\
		src/annex.c	\
		src/annex_bis.c	\
		src/mysh.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-I./lib/my/include -I./src/include -L./lib/my -lmy -Wno-unused -Wall -Wextra -g

all:	$(NAME)

$(NAME)	:
			make -C ./lib/my
			gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f *.o
	rm -f lib/my/*.o
	rm -f lib/my/libmy.a
	rm -f *~
	rm -f vgcore*

fclean:	clean
		rm -f $(NAME)

re:	fclean all
