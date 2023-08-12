# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juduval <juduval@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 14:18:56 by juduval           #+#    #+#              #
#    Updated: 2023/08/12 16:40:20 by juduval          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_DIR = ../objs
BONUS_OBJ = $(BONUS:.c=.o)

SRC = ft_bzero.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_memcmp.c ft_memmove.c ft_putchar_fd.c \
	ft_putnbr_fd.c ft_split.c ft_strdup.c ft_strjoin.c \
	ft_strlcpy.c ft_strmapi.c ft_strnstr.c ft_strtrim.c \
	ft_tolower.c ft_atoi.c ft_calloc.c ft_isalpha.c \
	ft_isdigit.c ft_itoa.c ft_memchr.c ft_memcpy.c \
	ft_memset.c ft_putendl_fd.c ft_putstr_fd.c ft_strchr.c \
	ft_striteri.c ft_strlcat.c ft_strlen.c ft_strncmp.c \
	ft_strrchr.c ft_substr.c

BONUS = ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c

all : $(NAME)

bonus : $(OBJ) $(BONUS_OBJ)
	ar -rcs $(NAME) $(OBJ) $(BONUS_OBJ)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean re fclean
