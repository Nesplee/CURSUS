/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:24:09 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 12:50:07 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static void	init_side_dist(t_game *g, t_ray *r)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (g->player.x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - g->player.x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (g->player.y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - g->player.y) * r->delta_dist_y;
	}
}

static void	init_ray_vectors(t_game *g, int x, t_ray *r)
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	camera_x = 2 * x / (double)WIN_WIDTH - 1;
	dir_x = cos(g->player.dir);
	dir_y = sin(g->player.dir);
	plane_x = -dir_y * g->raycast_cfg.plane_y;
	plane_y = dir_x * g->raycast_cfg.plane_y;
	r->ray_dir_x = dir_x + plane_x * camera_x;
	r->ray_dir_y = dir_y + plane_y * camera_x;
}

static void	init_ray_params(t_game *g, t_ray *r)
{
	r->map_x = (int)g->player.x;
	r->map_y = (int)g->player.y;
	r->delta_dist_x = fabs(1.0 / r->ray_dir_x);
	r->delta_dist_y = fabs(1.0 / r->ray_dir_y);
	r->hit = 0;
}

void	cast_ray(t_game *g, int x)
{
	t_ray	*r;

	r = &g->ray_array[x];
	init_ray_vectors(g, x, r);
	init_ray_params(g, r);
	init_side_dist(g, r);
	perform_dda(g, r);
}
