##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Task 01 CPool Day10
##

SRC	 =	my_putchar.c \
		my_putstr.c \
		my_strlen.c \
		my_putstr.c \
		compare_strings.c
		
OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME) clean

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/my.h

re: fclean all
