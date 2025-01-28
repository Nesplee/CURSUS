/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:35:31 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/25 18:03:52 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_floor(t_game *game)
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

void	render_walls(t_game *game)
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

void	render_player(t_game *game)
{
	void	*current_sprite;

	if (game->direction == DIR_LEFT)
		current_sprite = game->player_left_sprites[game->current_frame % 3];
	else if (game->is_moving)
		current_sprite = game->player_sprites[game->current_frame];
	else
		current_sprite = game->player_sprites[0];
	mlx_put_image_to_window(game->mlx, game->win, current_sprite,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}

void	render_collectibles(t_game *game)
{
	int		x;
	int		y;
	void	*current_sprite;

	current_sprite = game->collectible_sprites[game->collectible_frame];
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
					current_sprite, x * TILE_SIZE, y * TILE_SIZE);
			}
		}
	}
}

void	render_exit(t_game *game)
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
