/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:38:36 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/25 18:55:05 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_images(t_game *game)
{
	load_base_images(game);
	load_player_sprites(game);
	load_player_left_sprites(game);
	load_collectible_sprites(game);
	load_enemy_sprites(game);
	if (!game->img_wall || !game->img_floor || !game->img_exit
		|| !game->img_collect)
		error_exit(game, ERR_IMG);
	if (!game->player_sprites[0] || !game->player_sprites[1]
		|| !game->player_sprites[2] || !game->player_sprites[3])
		error_exit(game, ERR_IMG);
	if (!game->player_left_sprites[0] || !game->player_left_sprites[1]
		|| !game->player_left_sprites[2])
		error_exit(game, ERR_IMG);
	if (!game->collectible_sprites[0] || !game->collectible_sprites[1]
		|| !game->collectible_sprites[2] || !game->collectible_sprites[3])
		error_exit(game, ERR_IMG);
	if (!game->enemy_sprites[0] || !game->enemy_sprites[1]
		|| !game->enemy_sprites[2] || !game->enemy_sprites[3])
		error_exit(game, ERR_IMG);
}

int	check_map(t_game *game)
{
	if (!check_valid_chars(game->map))
		error_exit(game, ERR_CHAR);
	if (!check_rectangular(game->map))
		error_exit(game, ERR_RECT);
	if (!check_walls(game->map))
		error_exit(game, ERR_WALLS);
	if (!check_components(game))
		error_exit(game, ERR_COMPONENTS);
	if (!check_valid_path(game))
		error_exit(game, ERR_PATH);
	return (1);
}
