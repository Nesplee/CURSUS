/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:43:46 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/14 16:17:13 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static void	draw_cell_square(t_game *g, int x, int y, int color)
{
	int	dx;
	int	dy;
	int	px;
	int	py;

	dy = 0;
	while (dy < MINIMAP_SCALE)
	{
		dx = 0;
		while (dx < MINIMAP_SCALE)
		{
			px = x * MINIMAP_SCALE + dx;
			py = y * MINIMAP_SCALE + dy;
			if (px < WIN_WIDTH && py < WIN_HEIGHT)
				((int *)g->frame.data)[py * WIN_WIDTH + px] = color;
			dx++;
		}
		dy++;
	}
}

static int	get_cell_color(t_game *g, int x, int y)
{
	char	cell;
	int		idx;
	int		color;

	cell = g->map.grid[y][x];
	if (cell == '1')
		color = 0x777777;
	else if (cell == 'D')
	{
		idx = door_index(g, x, y);
		if (idx < 0 || g->doors[idx].open == 0)
			color = 0x777777;
		else
			color = 0x222222;
	}
	else
		color = 0x222222;
	return (color);
}

static void	draw_minimap_grid(t_game *g)
{
	int	x;
	int	y;
	int	map_w;
	int	map_h;
	int	color;

	map_w = g->map.width;
	map_h = g->map.height;
	y = 0;
	while (y < map_h)
	{
		x = 0;
		while (x < map_w)
		{
			color = get_cell_color(g, x, y);
			draw_cell_square(g, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_minimap_player(t_game *g)
{
	int	dx;
	int	dy;
	int	px;
	int	py;
	int	color;

	px = (int)(g->player.x * MINIMAP_SCALE);
	py = (int)(g->player.y * MINIMAP_SCALE);
	color = 0xFF0000;
	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			if ((px + dx) >= 0 && (px + dx) < WIN_WIDTH
				&& (py + dy) >= 0 && (py + dy) < WIN_HEIGHT)
				((int *)g->frame.data)[(py + dy) * WIN_WIDTH + px + dx] = color;
			dx++;
		}
		dy++;
	}
}

void	draw_minimap(t_game *g)
{
	draw_minimap_grid(g);
	draw_minimap_player(g);
}
