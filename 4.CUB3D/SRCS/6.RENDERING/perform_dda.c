/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:44:45 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 12:50:41 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static void	dda_step(t_ray *r)
{
	if (r->side_dist_x < r->side_dist_y)
	{
		r->side_dist_x += r->delta_dist_x;
		r->map_x += r->step_x;
		r->side = 0;
	}
	else
	{
		r->side_dist_y += r->delta_dist_y;
		r->map_y += r->step_y;
		r->side = 1;
	}
}

static void	check_map_bounds_and_hit(t_game *g, t_ray *r)
{
	if (r->map_x < 0 || r->map_x >= g->map.width
		|| r->map_y < 0 || r->map_y >= g->map.height)
	{
		if (r->map_x < 0)
			r->map_x = 0;
		else if (r->map_x >= g->map.width)
			r->map_x = g->map.width - 1;
		if (r->map_y < 0)
			r->map_y = 0;
		else if (r->map_y >= g->map.height)
			r->map_y = g->map.height - 1;
		r->hit = 1;
		return ;
	}
	if (g->map.grid[r->map_y][r->map_x] == '1'
		|| g->map.grid[r->map_y][r->map_x] == 'D')
		r->hit = 1;
}

void	perform_dda(t_game *g, t_ray *r)
{
	while (r->hit == 0)
	{
		dda_step(r);
		check_map_bounds_and_hit(g, r);
	}
}
