/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:42:54 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/25 18:55:19 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_vars(t_game *game, int argc, char **argv)
{
	if (argc != 2)
		error_exit(game, ERR_ARGS);
	ft_memset(game, 0, sizeof(t_game));
	game->map = read_map(game, argv[1]);
	if (!game->map)
		error_exit(game, ERR_MAP);
	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	game->map_width = ft_strlen(game->map[0]);
	if (!check_map(game))
		error_exit(game, ERR_MAP);
}

static void	init_graphics(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit(game, ERR_MLX);
	game->win = mlx_new_window(game->mlx,
			game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE,
			WINDOW_TITLE);
	if (!game->win)
		error_exit(game, ERR_MLX);
	mlx_do_sync(game->mlx);
	load_images(game);
}

static void	init_game_state(t_game *game)
{
	game->current_frame = 0;
	game->collectible_frame = 0;
	game->is_moving = 0;
	game->moves = 0;
	game->collected = 0;
	game->game_over = 0;
}

static void	setup_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, animation_loop, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_hook, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_vars(&game, argc, argv);
	init_graphics(&game);
	init_game_state(&game);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
