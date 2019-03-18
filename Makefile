##
## EPITECH PROJECT, 2017
## BSQ
## File description:
## Makefile
##

SRC	=	src/bsq.c		\
		src/get.c		\
		src/tab.c		\
		src/my_getnbr.c		\
		src/my_put_char.c	\
		src/my_put_str.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

CFLAGS	+=	-Wall -Wextra -I include/

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
