# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/30 12:36:48 by dinguyen          #+#    #+#              #
#    Updated: 2024/12/01 16:22:40 by dinguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = Libft/libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = operations1.c operations2.c operations3.c operations4.c \
	sort1.c sort2.c utils_stacks1.c utils_stacks2.c utils_verifications1.c \
	utils_verifications2.c  main.c
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
