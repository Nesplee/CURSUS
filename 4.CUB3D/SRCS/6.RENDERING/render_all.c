/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:19:29 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 13:49:45 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static void	draw_ceiling(t_game *g)
{
	int	x;
	int	y;
	int	*pixel;
	int	col;

	pixel = (int *)g->frame.data;
	col = g->c_color;
	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
			pixel[y * WIN_WIDTH + x++] = col;
		y++;
	}
}

static void	draw_floor(t_game *g)
{
	int	x;
	int	y;
	int	*pixel;
	int	col;

	pixel = (int *)g->frame.data;
	col = g->f_color;
	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
			pixel[y * WIN_WIDTH + x++] = col;
		y++;
	}
}

void	render_all(t_game *g, double delta)
{
	int	x;

	draw_ceiling(g);
	draw_floor(g);
	x = 0;
	while (x < WIN_WIDTH)
	{
		cast_ray(g, x);
		draw_wall(g, x, &g->ray_array[x]);
		x++;
	}
	draw_minimap(g);
	draw_crosshair(g);
	mlx_put_image_to_window(g->mlx.mlx_ptr,
		g->mlx.win_ptr, g->frame.img_ptr, 0, 0);
	draw_fps_ui(g, delta);
}
