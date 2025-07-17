/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:55:03 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/26 22:10:37 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_player_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < MAX_FRAMES)
	{
		if (game->player_sprites[i])
			mlx_destroy_image(game->mlx, game->player_sprites[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (game->player_left_sprites[i])
			mlx_destroy_image(game->mlx, game->player_left_sprites[i]);
		i++;
	}
}

static void	free_basic_sprites(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
}

static void	free_collectible_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->collectible_sprites[i])
			mlx_destroy_image(game->mlx, game->collectible_sprites[i]);
		i++;
	}
}

static void	free_enemy_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->enemy_sprites[i])
			mlx_destroy_image(game->mlx, game->enemy_sprites[i]);
		i++;
	}
}

void	free_images(t_game *game)
{
	free_player_sprites(game);
	free_collectible_sprites(game);
	free_enemy_sprites(game);
	free_basic_sprites(game);
	if (game->hud_background)
		mlx_destroy_image(game->mlx, game->hud_background);
}
