# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 11:40:21 by dinguyen          #+#    #+#              #
#    Updated: 2025/01/13 19:24:31 by dinguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c parse.c paths.c utils.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = bonus/main_bonus.c bonus/parse_bonus.c bonus/paths_bonus.c \
			bonus/utils_bonus.c bonus/here_doc.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT = Libft/libft.a
LIBFT_DIR = Libft

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
