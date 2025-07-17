NAME		= minishell
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I./INCLUDES
LIBFT_PATH	= ./LIBFT
LIBFT		= $(LIBFT_PATH)/libft.a

# Sources
SRCS_DIR	= SRCS
SRCS		= $(wildcard $(SRCS_DIR)/*/*.c) main.c
OBJS		= $(SRCS:.c=.o)

# Couleurs
GREEN		= \e[32m
BOLD		= \e[1m
RESET		= \e[0m

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	@printf "$(GREEN)$(BOLD)Compilation de $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_PATH) -lft -lreadline
	@printf "$(GREEN)$(BOLD)$(NAME) créé avec succès !$(RESET)\n"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJS)
	@printf "$(GREEN)Fichiers objets supprimés.$(RESET)\n"

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@printf "$(GREEN)$(NAME) supprimé.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re unused
