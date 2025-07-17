/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:35:31 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/26 20:35:22 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_floor(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	}
}

static void	render_walls(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	}
}

static void	render_collectibles(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_collect, x * TILE_SIZE, y * TILE_SIZE);
			}
		}
	}
}

static void	render_exit(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_exit, x * TILE_SIZE, y * TILE_SIZE);
			}
		}
	}
}

void	render_map(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	render_floor(game);
	render_walls(game);
	render_exit(game);
	render_collectibles(game);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_player,
		game->player_x * TILE_SIZE,
		game->player_y * TILE_SIZE);
	mlx_do_sync(game->mlx);
}
