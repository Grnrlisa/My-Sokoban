##
## EPITECH PROJECT, 2021
## B-PSU-101-REN-1-1-minishell1
## File description:
## Minishell 1 makefile
##

## Sources of the prog

SRC	=	sources/main_fct.c 			\
		sources/sokoban_loop.c		\
		sources/file_func.c 		\
		sources/find_pos.c 			\
		sources/moove_func.c 		\
		sources/check_cols_func.c 	\
		sources/draw_func.c		   	\
		sources/win_or_loose.c	    \
		sources/my_str_to_word_array.c
		
OBJ = $(SRC:.c=.o)

NAME =	my_sokoban

LIB = -L lib/ -lmy

INCLUDE = -I include/

## Compilation flags (auto pick-up)
CFLAGS = -Wall -W $(INCLUDE)

## Make commande
all:	mylib $(OBJ) clean
	gcc -g -o $(NAME) -lncurses $(SRC) $(INCLUDE) $(LIB)

mylib:
	make -C lib/my/

## clean commande : rm files object
clean:
	rm -f $(OBJ)
	make clean -C lib/my/


## fclean commande : rm binary
fclean:
	rm -f $(NAME)
	make clean
	make fclean -C lib/my/


## re commande : remake after cleaning
re:
	make fclean
	make all


.PHONY: clean, fclean, re, all