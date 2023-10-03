# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaristil <jaristil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 13:31:55 by jaristil          #+#    #+#              #
#    Updated: 2023/10/03 18:17:46 by jaristil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Compilateurs
CC = cc

# FLAGS
FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_itoa.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_memedel.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	ft_substr.c ft_tolower.c ft_toupper.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c \
	get_next_line.c get_next_line_utils.c \
	ft_printf.c ft_print_str.c ft_print_ptr.c \
	ft_print_nbr.c ft_print_unsigned.c ft_print_hex.c add_function.c \
	unsigned_itoa.c 

# Nomme automatique des fichiers .o d'apres les nomms de sources c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) -g3 -o $@ -c $< $(FLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
