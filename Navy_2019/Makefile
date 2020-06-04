##
## EPITECH PROJECT, 2019
## jules.vitrac
## File description:
## Makefile
##

SRCS = 	src/main.c\
		src/errcheck_frees.c\
		src/gameloop.c\
		src/map_handling.c\
		src/grid_handling.c\
		src/pid_exchange.c

OBJ = ${SRCS:.c=.o}

LIBPATH = lib/my/

CFLAGS = -Wall -Wextra -L lib -lmy -I include -I lib/my

LIB_INCLUDE = -L lib -lmy -I include

NAME = navy

all : ${NAME}

debug : clean
debug : CFLAGS += -g
debug : ${NAME}

${NAME} : ${OBJ}
	make -C ${LIBPATH} all
	gcc -o ${NAME} ${OBJ} ${LIB_INCLUDE}

clean :
	rm -f ${OBJ}
	make -C ${LIBPATH} clean

fclean : clean
	rm -f ${NAME}
	make -C ${LIBPATH} fclean

re : fclean all

.PHONY: all debug clean fclean re
