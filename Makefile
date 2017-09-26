#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhulam <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 17:28:09 by rhulam            #+#    #+#              #
#    Updated: 2017/06/08 19:06:01 by rhulam           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem_in
LIB_NAME = libft.a
LIB_PATH = ./libft/
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))
CC = gcc
SRC = main.c ants.c error.c free.c help.c help2.c help3.c help4.c help_fill_list.c list_create.c optimize_list.c routers.c validation_after_read.c
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
		@make -C libft/
		gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

clean:
		@make fclean -C libft/
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all