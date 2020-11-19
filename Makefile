##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c		\
		src/load_map.c		\
		src/init.c		\
		src/parse_map.c		\
		src/count_numbers.c	\
		src/check_touch.c	\
		src/check_victory.c	\
		src/my_sokoban.c	\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-Wshadow -I ./include

LIB	=	lib/my -lmy -lcurses

NAME	=	my_sokoban

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my/
		$(CC) -o $(NAME) $(OBJ) -L $(LIB)

clean:
	make -C lib/my clean
	rm -f $(OBJ)
	rm -f *.gcno *.gcda

fclean:	clean
	make -C lib/my fclean
	rm -f $(NAME)

re:	fclean all
