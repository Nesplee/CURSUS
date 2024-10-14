# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 00:16:33 by dinguyen          #+#    #+#              #
#    Updated: 2024/10/14 17:55:59 by dinguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c main.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ../libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_H = $(LIBFT_DIR)libft.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		ar rcs $@ $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(LIBFT_H)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
