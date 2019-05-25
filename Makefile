##
## EPITECH PROJECT, 2019
## 42sh
## File description:
## Makefile
##

FILES = search.c \
		exec_file.c \
		exec_com.c \
		my_str_to_word_array.c \
		my_atoi.c \
		builtin.c \
		built_in_env.c \
		built_in_exit.c \
		built_in_cd.c \
		my_error.c

MAIN = src/main.c

SRC = $(addprefix src/,$(FILES))

OBJ = $(notdir $(SRC:.c=.o)) $(notdir $(MAIN:.c=.o))

I_PATH = include/

FLAGS = -Wall -Wextra

NAME = 42sh

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ) :
	gcc $(FLAGS) -c $(SRC) $(MAIN) -I$(I_PATH)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all fclean clean re
