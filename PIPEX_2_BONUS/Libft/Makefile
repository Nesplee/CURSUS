# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 21:00:48 by dinguyen          #+#    #+#              #
#    Updated: 2025/01/05 14:43:47 by dinguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_bzero.c ft_calloc.c	ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_split.c ft_atol.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
	ft_toupper.c ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_striteri.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_lstadd_back_bonus.c \
	ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
	ft_lstsize_bonus.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c \
	ft_putptr.c ft_putunbr.c ft_printf.c ft_isnumber.c ft_strcmp.c \
	ft_split_free.c ft_swap.c ft_found_newline.c ft_isspace.c

GNL_DIR = GNL
GNL_SRCS = $(GNL_DIR)/get_next_line.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

ALL_SRCS = $(SRCS) $(GNL_SRCS)
OBJ = $(SRCS:.c=.o) $(GNL_OBJS)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
