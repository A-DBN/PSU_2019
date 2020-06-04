##
## EPITECH PROJECT, 2019
## day10
## File description:
## Makefile
##

SRCS = 	atoi_itoa.c\
		file_to_str.c\
		ftsplit.c\
		putchar.c\
		putnbr.c\
		putstr.c\
		strrev.c\
		my_strlowcase.c\
		my_strcat.c\
		my_strcmp.c\
		my_strdup.c\
		my_strlen.c\
		my_strstr.c\

HEAD = my.h

HEADPATH = ../../include/

OBJ = ${SRCS:.c=.o}

NAME = libmy.a

all : ${NAME}

${NAME} : ${OBJ}
	cp ${HEAD} ${HEADPATH}
	ar rc ${NAME} ${OBJ}
	mv ${NAME} ../

clean :
	rm -f ${OBJ}

fclean : clean
	rm -f ../${NAME}
	rm -f ${HEADPATH}${HEAD}

re : fclean all
