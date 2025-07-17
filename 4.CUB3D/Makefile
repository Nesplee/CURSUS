NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

INCDIRS = -IINCLUDES -ILIBFT -IMINILIBX-LINUX
SRCDIRS = \
	SRCS/1.INIT \
	SRCS/2.LEXING \
	SRCS/3.CHECKING \
	SRCS/4.PARSING \
	SRCS/5.UPDATE \
	SRCS/6.RENDERING \
	SRCS/7.UTILS

SRCS = $(shell find $(SRCDIRS) -name '*.c') main.c
OBJS = $(SRCS:.c=.o)

LIBFT = LIBFT/libft.a
MLX = MINILIBX-LINUX/libmlx.a

LDFLAGS = -LLIBFT -lft -LMINILIBX-LINUX -lmlx \
			-lXext -lX11 -lm -lbsd

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(INCDIRS) -o $@ $(OBJS) $(LDFLAGS)

$(LIBFT):
	make -C LIBFT

$(MLX):
	make -C MINILIBX-LINUX

%.o: %.c
	$(CC) $(CFLAGS) $(INCDIRS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C LIBFT clean
	make -C MINILIBX-LINUX clean

fclean: clean
	rm -f $(NAME)
	make -C LIBFT fclean

re: fclean all
