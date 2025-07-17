/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:20:54 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 12:36:16 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static void	update_rotation(t_game *g, double delta)
{
	double	rot_speed;

	rot_speed = g->player.rot_speed * delta;
	if (rot_speed > 0.05)
		rot_speed = 0.05;
	if (g->input.key_left)
	{
		g->player.dir -= rot_speed;
		if (g->player.dir < 0)
			g->player.dir += 2.0 * M_PI;
	}
	if (g->input.key_right)
	{
		g->player.dir += rot_speed;
		if (g->player.dir >= 2.0 * M_PI)
			g->player.dir -= 2.0 * M_PI;
	}
}

void	update_player(t_game *g, double delta)
{
	double	speed;

	speed = g->player.move_speed * delta * 60.0;
	if (speed > 0.1)
		speed = 0.1;
	update_rotation(g, delta);
	update_player_movement(g, speed);
}
