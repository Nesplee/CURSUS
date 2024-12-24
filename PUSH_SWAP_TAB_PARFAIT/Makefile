# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 20:14:28 by dinguyen          #+#    #+#              #
#    Updated: 2024/12/24 15:45:40 by dinguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = Libft/libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = index_stack.c main.c operations1.c operations2.c operations3.c \
	operations4.c parsing1.c parsing2.c sorting_functions.c sorting_large1.c \
	sorting_large2.c utils.c

OBJS = $(SRCS:.c=.o)

BONUS_NAME = checker
BONUS_SRCS = checker.c $(filter-out main.c, $(SRCS))
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	$(MAKE) -C Libft

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) fclean -C Libft || true

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) fclean -C Libft || true

re: fclean all

.PHONY: all clean fclean re bonus
