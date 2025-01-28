/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handle_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:06:53 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/25 18:54:36 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}

void	init_window(t_game *game)
{
	int	width;
	int	height;

	game->map_height = 0;
	while (game->map[game->map_height])
		game->map_height++;
	game->map_width = ft_strlen(game->map[0]);
	width = game->map_width * TILE_SIZE;
	height = game->map_height * TILE_SIZE;
	mlx_do_sync(game->mlx);
	game->win = mlx_new_window(game->mlx, width, height, WINDOW_TITLE);
	if (!game->win)
		error_exit(game, ERR_MLX);
	load_images(game);
	mlx_do_sync(game->mlx);
	render_map(game);
}
