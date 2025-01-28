/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:06:53 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/26 19:54:05 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	width = game->map_width * TILE_SIZE;
	height = game->map_height * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, WINDOW_TITLE);
	if (!game->win)
	{
		ft_putstr_fd(ERR_MLX, 2);
		exit(1);
	}
	load_images(game);
	mlx_do_sync(game->mlx);
	render_map(game);
}
