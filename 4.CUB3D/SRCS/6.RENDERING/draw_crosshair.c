/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_crosshair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:42:21 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 13:12:48 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	int	*pixel;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		pixel = (int *)img->data;
		pixel[y * img->width + x] = color;
	}
}

static void	draw_crosshair_h(t_game *g, int cx, int cy, int size)
{
	int	i;

	i = -size;
	while (i <= size)
	{
		if (cx + i >= 0 && cx + i < WIN_WIDTH
			&& cy >= 0 && cy < WIN_HEIGHT)
			put_pixel(&g->frame, cx + i, cy, CROSSHAIR_COLOR);
		i++;
	}
}

static void	draw_crosshair_v(t_game *g, int cx, int cy, int size)
{
	int	i;

	i = -size;
	while (i <= size)
	{
		if (cx >= 0 && cx < WIN_WIDTH
			&& cy + i >= 0 && cy + i < WIN_HEIGHT)
			put_pixel(&g->frame, cx, cy + i, CROSSHAIR_COLOR);
		i++;
	}
}

void	draw_crosshair(t_game *g)
{
	int	cx;
	int	cy;

	cx = WIN_WIDTH / 2;
	cy = WIN_HEIGHT / 2;
	draw_crosshair_h(g, cx, cy, CROSSHAIR_SIZE);
	draw_crosshair_v(g, cx, cy, CROSSHAIR_SIZE);
}
