/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_hooks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:35:02 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/16 12:34:42 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static int	init_mouse_tracking(int x, int *last_x, int *initialized)
{
	if (!(*initialized))
	{
		*last_x = x;
		*initialized = 1;
		return (1);
	}
	return (0);
}

static void	update_player_rotation(t_game *g, int dx)
{
	double	sensitivity;

	sensitivity = 0.002;
	g->player.dir += dx * sensitivity;
	if (g->player.dir < 0)
		g->player.dir += 2.0 * M_PI;
	else if (g->player.dir >= 2.0 * M_PI)
		g->player.dir -= 2.0 * M_PI;
}

static int	mouse_move(int x, int y, t_game *g)
{
	static int	initialized;
	static int	last_x;
	int			dx;

	(void)y;
	if (init_mouse_tracking(x, &last_x, &initialized))
		return (0);
	dx = x - last_x;
	if (abs(dx) > 100)
	{
		last_x = x;
		return (0);
	}
	update_player_rotation(g, dx);
	last_x = x;
	return (0);
}

void	init_hooks(t_game *g)
{
	mlx_hook(g->mlx.win_ptr, 2, 1L << 0, key_press, g);
	mlx_hook(g->mlx.win_ptr, 3, 1L << 1, key_release, g);
	mlx_hook(g->mlx.win_ptr, 6, PointerMotionMask, mouse_move, g);
	mlx_hook(g->mlx.win_ptr, 17, 0, close_window, g);
	mlx_loop_hook(g->mlx.mlx_ptr, game_loop, g);
}
