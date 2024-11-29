# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 12:05:43 by dinguyen          #+#    #+#              #
#    Updated: 2024/11/29 11:40:07 by dinguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

LIBFT = Libft/libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = arguments.c operations1.c operations2.c operations3.c sorting1.c \
	utils_arguments1.c utils_arguments2.c utils_operations1.c utils_stacks1.c \
	utils_stacks2.c main.c
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
