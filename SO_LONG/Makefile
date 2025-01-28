# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 17:38:01 by dinguyen          #+#    #+#              #
#    Updated: 2025/01/25 18:34:04 by dinguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
BONUS_NAME	= so_long_bonus
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.
MLX_FLAGS	= -Lminilibx-linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz
LIBFT		= Libft/libft.a

SRCS		=	game_moves.c main.c map_check.c map_check2.c \
				map_path.c map_read.c map_render.c utils.c window_handle.c

BONUS_SRCS	=	bonus/game_moves_bonus.c bonus/game_hooks_bonus.c \
				bonus/main_bonus.c bonus/map_check_bonus.c \
				bonus/map_check2_bonus.c bonus/map_load_bonus.c \
				bonus/map_path_bonus.c bonus/map_read_bonus.c \
				bonus/map_render_bonus.c bonus/map_render2_bonus.c \
				bonus/utils_bonus.c bonus/utils_free_bonus.c \
				bonus/window_handle_bonus.c

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

MLX_PATH	= minilibx-linux/
MLX			= $(MLX_PATH)libmlx.a

all			: $(MLX) $(LIBFT) $(NAME)

$(MLX)		:
	make -C	$(MLX_PATH)

$(LIBFT)	:
	make -C Libft

$(NAME)		: $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

bonus		: $(MLX) $(LIBFT) $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(BONUS_NAME)

%.o			: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C Libft
	make clean -C $(MLX_PATH)

fclean		: clean
	rm -f $(NAME) $(BONUS_NAME)
	make fclean -C Libft
	rm -f $(MLX)

re			: fclean all

.PHONY		: all clean fclean re bonus
