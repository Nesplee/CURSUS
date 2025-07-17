/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:22:36 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 12:40:55 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int	is_wall(t_game *g, double x, double y)
{
	int	mx;
	int	my;
	int	idx;

	mx = (int)x;
	my = (int)y;
	if (mx < 0 || mx >= g->map.width || my < 0 || my >= g->map.height)
		return (1);
	if (g->map.grid[my][mx] == '1')
		return (1);
	if (g->map.grid[my][mx] == 'D')
	{
		idx = door_index(g, mx, my);
		if (idx < 0 || g->doors[idx].open == 0)
			return (1);
	}
	return (0);
}

static void	update_single_anim(t_anim *anim, double dt_ms)
{
	double	new_timer;
	int		new_frame;

	new_timer = anim->timer + dt_ms;
	if (new_timer >= ANIM_DELAY_MS)
	{
		new_timer -= ANIM_DELAY_MS;
		new_frame = anim->current + 1;
		if (new_frame >= ANIM_FRAMES)
			new_frame = 0;
		anim->current = new_frame;
	}
	anim->timer = new_timer;
}

void	update_animations(t_game *g, double delta)
{
	double	dt_ms;

	dt_ms = delta * 1000.0;
	update_single_anim(&g->anim_north, dt_ms);
	update_single_anim(&g->anim_south, dt_ms);
	update_single_anim(&g->anim_east, dt_ms);
	update_single_anim(&g->anim_west, dt_ms);
}
