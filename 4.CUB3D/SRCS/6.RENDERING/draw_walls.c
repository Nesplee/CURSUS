/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:49:47 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/14 15:24:24 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static void	init_line_params(t_game *g, t_ray *r)
{
	if (r->side == 0)
		r->perp_wall_dist = (r->map_x - g->player.x
				+ (1 - r->step_x) / 2) / r->ray_dir_x;
	else
		r->perp_wall_dist = (r->map_y - g->player.y
				+ (1 - r->step_y) / 2) / r->ray_dir_y;
	r->line_h = (int)(WIN_HEIGHT / r->perp_wall_dist);
	r->draw_start = -r->line_h / 2 + WIN_HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_h / 2 + WIN_HEIGHT / 2;
	if (r->draw_end >= WIN_HEIGHT)
		r->draw_end = WIN_HEIGHT - 1;
}

static t_texture	*select_texture(t_game *g, t_ray *r)
{
	char	cell;
	int		idx;

	cell = g->map.grid[r->map_y][r->map_x];
	if (cell == 'D')
	{
		idx = door_index(g, r->map_x, r->map_y);
		if (idx >= 0)
			return (&g->doors[idx].anim[g->doors[idx].open]);
	}
	if (r->side == 0)
	{
		if (r->ray_dir_x < 0)
			return (&g->anim_east.frames[g->anim_east.current]);
		return (&g->anim_west.frames[g->anim_west.current]);
	}
	else
	{
		if (r->ray_dir_y < 0)
			return (&g->anim_south.frames[g->anim_south.current]);
		return (&g->anim_north.frames[g->anim_north.current]);
	}
}

static void	init_tex_slice(t_game *g, t_texture *tex, t_ray *r)
{
	int		tw;
	double	wall_x;

	if (r->side == 0)
		wall_x = g->player.y + r->perp_wall_dist * r->ray_dir_y;
	else
		wall_x = g->player.x + r->perp_wall_dist * r->ray_dir_x;
	tw = tex->img.width;
	wall_x = wall_x - (int)wall_x;
	r->tex_x = (int)(wall_x * tw);
	if ((r->side == 0 && r->ray_dir_x > 0)
		|| (r->side == 1 && r->ray_dir_y < 0))
		r->tex_x = tw - r->tex_x - 1;
	r->tex_step = (double)tex->img.height / r->line_h;
	r->tex_pos = (r->draw_start - WIN_HEIGHT / 2 + r->line_h / 2)
		* r->tex_step;
}

static void	draw_texture_slice(t_game *g, t_texture *tex,
							t_ray *r, int x)
{
	int	y;
	int	*pix;
	int	*tpx;
	int	color;
	int	ty;

	pix = (int *)g->frame.data;
	tpx = (int *)tex->img.data;
	y = r->draw_start;
	while (y <= r->draw_end)
	{
		ty = (int)r->tex_pos;
		if (ty < 0)
			ty = 0;
		if (ty >= tex->img.height)
			ty = tex->img.height - 1;
		color = tpx[ty * tex->img.width + r->tex_x];
		pix[y * WIN_WIDTH + x] = color;
		r->tex_pos += r->tex_step;
		y++;
	}
}

void	draw_wall(t_game *g, int x, t_ray *r)
{
	t_texture	*tex;

	init_line_params(g, r);
	tex = select_texture(g, r);
	init_tex_slice(g, tex, r);
	draw_texture_slice(g, tex, r, x);
}
