# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmylonas <dmylonas@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 11:02:01 by dmylonas          #+#    #+#              #
#    Updated: 2021/10/11 14:12:30 by dmylonas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIB_PATH = ./Libft
LIB_NAME = libft.a

COMPILE = gcc -g -Wall -Werror -Wextra
COMPILE_DEV = gcc -g

SRCS = main.c check_map.c create_map_check_input.c so_long_utils.c \
		fill_map.c movement.c check_collectibles_for_move.c

all: $(LIB_NAME) $(NAME)

$(LIB_NAME): 
	make -C $(LIB_PATH)

$(NAME): $(SRCS)
	$(COMPILE) $(SRCS) -lmlx -lXext -lX11 -L $(LIB_PATH) -lft -o $(NAME)

clean: 
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME) $(NAME_1)
	make -C $(LIB_PATH) fclean

re: fclean all

.PHONY: all clean fclean re