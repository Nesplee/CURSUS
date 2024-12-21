# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 20:14:28 by dinguyen          #+#    #+#              #
#    Updated: 2024/12/22 00:07:08 by dinguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

LIBFT = Libft/libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = index_stack.c main.c operations1.c operations2.c operations3.c \
	operations4.c parsing1.c parsing2.c sorting_functions.c sorting_large.c \
	utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C Libft

clean:
	rm -f $(OBJS)
	$(MAKE) fclean -C Libft || true

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C Libft || true

re: fclean all
