# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juduval <juduval@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 15:17:00 by juduval           #+#    #+#              #
#    Updated: 2023/09/05 17:54:00 by juduval          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
LIBFT = libft/libft.a
LIBFT_DIR = libft/
LIB_FLAGS = -Llibft -lft
READLINE_FLAGS = -lreadline -lncurses

SRC = main.c readline.c signals.c get_cmd.c elems.c elems_2.c utils.c utils_2.c utils_3.c

all: $(NAME) ${LIBFT}

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_FLAGS) $(LIBFT) $(READLINE_FLAGS) -o $(NAME)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean re fclean