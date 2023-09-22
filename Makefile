# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 13:41:12 by jaristil          #+#    #+#              #
#    Updated: 2023/09/18 18:57:46 by jaristil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROGRAM

CC ?= cc
NAME := minishell
CFLAGS += -Wall -Wextra -Werror
LIB_FLAGS = -lreadline -lncurses

# DIRECTORIES

HD_DIR = ./includes
SRC_DIR = ./src
OBJ_DIR = ./objs
LIBFT_DIR = ./libft

# DELETE

RM = rm -rf

# COLORS

GREEN=\033[0;32m
BLUE=\033[0;34m
RED=\033[0;31m
PINK=\033[0;35m
END=\033[0m

# FILES

SRC_F =	main.c readline.c \
		\
		env/getenv.c env/getenv_bis.c env/setenv.c env/doenv.c \
		\
		builtin/cd.c builtin/cd_utils.c \
		builtin/echo.c \
		builtin/exec_built_in.c \
		builtin/exit.c \
		builtin/export.c \
		builtin/pwd.c \
		builtin/env.c \
		builtin/unset.c \
		\
		/exec/builtin.c \
		/exec/exec.c \
		\
		utils/free.c utils/error.c utils/utils.c \
		\
SRC = $(addprefix $(SRC_DIR)/, $(SRC_F))
OBJ = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC:.c=.o))

# COMPILES

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HD_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I $(HD_DIR) -c $< -o $@

# RULES

$(NAME) : $(OBJ)
	@echo "$(BLUE) ...Project compiling... $(END)"
	@$(CC) $(CFLAGS) -I $(HD_DIR) $(OBJ) -o $(NAME)
	@echo "$(GREEN) ...Project compiled... $(END)"

all : $(NAME)

clean :
	@echo "$(BLUE) ...Removing object files... $(END)"
	@$(RM) $(OBJ_DIR)
	@echo "$(RED) ...All object removed ... $(END)"

fclean : clean
	@echo "$(BLUE) ...Removing executables... $(END)"
	@$(RM) $(NAME)
	@echo "$(RED) ...Executables removed...$(END)"

scan :
	@echo "$(BLUE) ...Running scan... $(END)"
	@scan-build-12 make -s
	@echo " $(GREEN) ...Scan finished... $(END)"

re : fclean all

.PHONY : all clean fclean scan re