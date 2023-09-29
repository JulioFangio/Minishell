# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/12 15:17:00 by juduval           #+#    #+#              #
#    Updated: 2023/09/28 16:40:36 by jaristil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
LIBFT = libft/libft.a
LIBFT_DIR = libft/
LIB_FLAGS = -Llibft -lft
READLINE_FLAGS = -lreadline -lncurses
OBJ_DIRS = builtin env exec pars utils
OBJ_DIRS := $(addprefix $(OBJ_DIR), $(OBJ_DIRS))

SRC = main.c pars/readline.c pars/signals.c pars/get_cmd.c pars/elems.c pars/elems_2.c pars/elems_3.c pars/fill_elems.c \
		\
		pars/expansion.c pars/utils.c pars/utils_2.c pars/utils_3.c pars/utils_4.c pars/utils_5.c pars/parse_line.c \
		\
		pars/split_mini.c \
		\
		utils/token.c utils/fd.c utils/tab.c utils/free.c utils/error.c \
		\
		env/getenv.c env/getenv_bis.c env/setenv.c env/doenv.c \
		\
		builtin/cd.c builtin/cd_utils.c \
		builtin/echo.c \
		builtin/exit.c \
		builtin/export.c \
		builtin/pwd.c \
		builtin/env.c \
		builtin/unset.c \
		\
		exec/exec_builtin.c \
		exec/exec_pipe.c \
		exec/exec_redir.c \
		exec/start_exec.c \
		exec/exec.c \
		
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_FLAGS) $(LIBFT) $(READLINE_FLAGS) -o $(NAME)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: src/%.c | $(OBJ_DIR) $(OBJ_DIRS)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIRS):
	mkdir -p $(OBJ_DIRS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean re fclean