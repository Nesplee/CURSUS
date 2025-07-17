/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:13:24 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/26 22:39:50 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		handle_movement(keycode, game);
	return (0);
}

void	set_direction(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		game->direction = DIR_LEFT;
	else if (keycode == KEY_D)
		game->direction = DIR_RIGHT;
	else if (keycode == KEY_W)
		game->direction = PLAYER_DIR_UP;
	else if (keycode == KEY_S)
		game->direction = PLAYER_DIR_DOWN;
	game->is_moving = 1;
}

int	animation_loop(t_game *game)
{
	static unsigned long	frame;
	int						should_render;

	should_render = 0;
	frame++;
	if (game->is_moving && frame % (FRAME_DELAY * 2) == 0)
	{
		game->current_frame = (game->current_frame + 1) % 4;
		game->enemy_frame = (game->enemy_frame + 1) % 4;
		should_render = 1;
	}
	if (frame % FRAME_DELAY == 0)
	{
		game->collectible_frame = (game->collectible_frame + 1) % 4;
		should_render = 1;
	}
	if (should_render)
	{
		mlx_clear_window(game->mlx, game->win);
		render_map(game);
		mlx_do_sync(game->mlx);
	}
	return (0);
}
