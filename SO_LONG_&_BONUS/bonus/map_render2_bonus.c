/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:07:54 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/26 22:40:16 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*create_moves_text(int moves)
{
	char	*tmp;
	char	*moves_str;

	tmp = ft_itoa(moves);
	moves_str = ft_strjoin("Moves: ", tmp);
	free(tmp);
	return (moves_str);
}

static char	*create_collect_text(int collected, int total)
{
	char	*tmp1;
	char	*tmp2;
	char	*collect_str;
	char	*final_str;

	tmp1 = ft_itoa(collected);
	tmp2 = ft_itoa(total);
	collect_str = ft_strjoin("Items: ", tmp1);
	final_str = ft_strjoin(collect_str, "/");
	free(collect_str);
	collect_str = ft_strjoin(final_str, tmp2);
	free(final_str);
	free(tmp1);
	free(tmp2);
	return (collect_str);
}

void	render_hud(t_game *game)
{
	char	*moves_str;
	char	*collect_str;

	moves_str = create_moves_text(game->moves);
	collect_str = create_collect_text(game->collected, game->collectibles);
	mlx_string_put(game->mlx, game->win, HUD_X, HUD_MOVES_Y,
		HUD_COLOR, moves_str);
	mlx_string_put(game->mlx, game->win, HUD_X, HUD_COLLECT_Y,
		HUD_COLOR, collect_str);
	free(moves_str);
	free(collect_str);
}

void	render_enemies(t_game *game)
{
	int		x;
	int		y;
	void	*current_sprite;

	current_sprite = game->enemy_sprites[game->enemy_frame];
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'N')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
				mlx_put_image_to_window(game->mlx, game->win,
					current_sprite, x * TILE_SIZE, y * TILE_SIZE);
			}
		}
	}
}
