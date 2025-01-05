# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 22:42:00 by dinguyen          #+#    #+#              #
#    Updated: 2025/01/05 22:22:18 by dinguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFT = Libft/libft.a

SRCS = Children.c Fork.c Init.c Main.c Parse.c Paths.c Pipes.c \
	Utils_error.c Utils_free.c Here_doc.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C Libft

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

bonus: fclean $(LIBFT)
	$(CC) $(CFLAGS) -DBONUS -c $(SRCS)
	$(CC) *.o $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C Libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C Libft

re: fclean all

.PHONY: all bonus clean fclean re
