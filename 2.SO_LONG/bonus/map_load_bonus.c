/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:25:01 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/25 18:54:10 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_base_images(t_game *game)
{
	int	width;
	int	height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/img_wall.xpm",
			&width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/img_floor.xpm",
			&width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "assets/img_exit.xpm",
			&width, &height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"assets/img_collectible1.xpm", &width, &height);
}

void	load_player_sprites(t_game *game)
{
	int	width;
	int	height;

	game->player_sprites[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/img_player.xpm", &width, &height);
	game->player_sprites[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/player1_3_bonus.xpm", &width, &height);
	game->player_sprites[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/player2_bonus.xpm", &width, &height);
	game->player_sprites[3] = mlx_xpm_file_to_image(game->mlx,
			"assets/player1_3_bonus.xpm", &width, &height);
}

void	load_player_left_sprites(t_game *game)
{
	int	width;
	int	height;

	game->player_left_sprites[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/player1_3_reverse_bonus.xpm", &width, &height);
	game->player_left_sprites[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/player2_reverse_bonus.xpm", &width, &height);
	game->player_left_sprites[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/player1_3_reverse_bonus.xpm", &width, &height);
}

void	load_collectible_sprites(t_game *game)
{
	int	width;
	int	height;

	game->collectible_sprites[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/img_collectible1.xpm", &width, &height);
	game->collectible_sprites[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/img_collectible2_bonus.xpm", &width, &height);
	game->collectible_sprites[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/img_collectible3_bonus.xpm", &width, &height);
	game->collectible_sprites[3] = mlx_xpm_file_to_image(game->mlx,
			"assets/img_collectible4_bonus.xpm", &width, &height);
}

void	load_enemy_sprites(t_game *game)
{
	int	width;
	int	height;

	game->enemy_sprites[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/img_enemy_0_bonus.xpm", &width, &height);
	game->enemy_sprites[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/img_enemy_1_3_bonus.xpm", &width, &height);
	game->enemy_sprites[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/img_enemy_2_bonus.xpm", &width, &height);
	game->enemy_sprites[3] = mlx_xpm_file_to_image(game->mlx,
			"assets/img_enemy_1_3_bonus.xpm", &width, &height);
}
