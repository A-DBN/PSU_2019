##
## EPITECH PROJECT, 2019
## info_file
## File description:
## info_file
##

SRC	=	src/test.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

CFLAGS	=	-I./lib/my/include -I./src/include -L./lib/my -lmy -W -Wall -Wextra -g

all:	$(NAME)

$(NAME)	:
			make -C ./lib/my
			gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f *.o
	rm -f *~

fclean:	clean
		rm -f $(NAME)

re:	fclean all
