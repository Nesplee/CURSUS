/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_moves_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:17:32 by dinguyen          #+#    #+#             */
/*   Updated: 2025/01/24 18:10:06 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_move_validity(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map_width
		|| new_y < 0 || new_y >= game->map_height)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (game->map[new_y][new_x] == 'N')
	{
		ft_printf("Game Over! You hit an enemy!\n");
		close_window(game);
		return (0);
	}
	return (1);
}

static void	handle_collectible(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->collected++;
		game->map[y][x] = '0';
	}
}

static int	handle_exit(t_game *game)
{
	if (game->collected == game->collectibles)
	{
		ft_printf("Bravo! Résultat: %d coups!\n", game->moves + 1);
		close_window(game);
		return (1);
	}
	return (0);
}

static void	update_position(t_game *game, int new_x, int new_y)
{
	char	current_pos;

	if (game->map[game->player_y][game->player_x] == 'E')
		current_pos = 'E';
	else
		current_pos = '0';
	game->map[game->player_y][game->player_x] = current_pos;
	game->player_x = new_x;
	game->player_y = new_y;
	if (game->map[new_y][new_x] != 'E')
		game->map[new_y][new_x] = 'P';
	game->moves++;
	render_map(game);
	ft_printf("Moves: %d | Collected: %d/%d\n",
		game->moves, game->collected, game->collectibles);
}

void	handle_movement(int keycode, t_game *game)
{
	int		new_x;
	int		new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == KEY_D)
		new_x++;
	if (keycode == KEY_A)
		new_x--;
	if (keycode == KEY_S)
		new_y++;
	if (keycode == KEY_W)
		new_y--;
	set_direction(keycode, game);
	if (!check_move_validity(game, new_x, new_y))
	{
		game->is_moving = 0;
		return ;
	}
	handle_collectible(game, new_x, new_y);
	update_position(game, new_x, new_y);
	if (game->map[new_y][new_x] == 'E'
		&& game->collected == game->collectibles)
		handle_exit(game);
}
