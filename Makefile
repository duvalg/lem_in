# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/27 11:25:13 by gduval            #+#    #+#              #
#    Updated: 2017/07/27 11:25:16 by gduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIBFT_NAME = libft.a
LIBFT_PATH = ./libft/
LIBFT = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

SRC_PATH = ./srcs/
SRC_NAME = main.c						\
			init_struct.c				\
			parse.c						\
			create_rooms.c				\
			get_links.c					\
			set_index.c					\
			bring_ants.c				\
			navigate_throught_rooms.c	\
			exit.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(SRC_NAME:.c=.o)

HEADER_PATH = ./includes/
HEADER_NAME = lem_in.h
HEADER = $(addprefix $(HEADER_PATH), $(HEADER_NAME))

FLAGS = -c
CC = gcc

all: $(NAME)

$(NAME) :
	@echo "\033[93m----------------------------------\033[0m"
	@echo "\033[93m-       LEM_IN COMPILATION       -\033[0m"
	@echo "\033[93m----------------------------------\033[0m"
	@make -C libft
	@$(CC) $(SRC) $(FLAGS)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\033[93m-              done              -\033[0m"

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
