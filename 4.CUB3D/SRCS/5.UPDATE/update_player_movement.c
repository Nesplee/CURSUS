/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_movement.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 09:39:32 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/15 10:38:59 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static void	move_forward_backward(t_game *g, double speed)
{
	double	dir_x;
	double	dir_y;
	double	new_x;
	double	new_y;

	dir_x = cos(g->player.dir);
	dir_y = sin(g->player.dir);
	if (g->input.key_w || g->input.key_up)
	{
		new_x = g->player.x + dir_x * speed;
		new_y = g->player.y + dir_y * speed;
		try_move(g, new_x, new_y);
	}
	if (g->input.key_s || g->input.key_down)
	{
		new_x = g->player.x - dir_x * speed;
		new_y = g->player.y - dir_y * speed;
		try_move(g, new_x, new_y);
	}
}

static void	move_strafe(t_game *g, double speed)
{
	double	perp_x;
	double	perp_y;
	double	new_x;
	double	new_y;

	perp_x = -sin(g->player.dir);
	perp_y = cos(g->player.dir);
	if (g->input.key_a || g->input.key_left)
	{
		new_x = g->player.x - perp_x * speed;
		new_y = g->player.y - perp_y * speed;
		try_move(g, new_x, new_y);
	}
	if (g->input.key_d || g->input.key_right)
	{
		new_x = g->player.x + perp_x * speed;
		new_y = g->player.y + perp_y * speed;
		try_move(g, new_x, new_y);
	}
}

void	update_player_movement(t_game *g, double speed)
{
	move_forward_backward(g, speed);
	move_strafe(g, speed);
}
