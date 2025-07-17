/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:36:12 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 12:37:45 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static int	can_move(t_game *g, double nx, double ny)
{
	double	tx;
	double	ty;

	if (nx > g->player.x)
		tx = nx + COLLISION_OFFSET;
	else
		tx = nx - COLLISION_OFFSET;
	if (ny > g->player.y)
		ty = ny + COLLISION_OFFSET;
	else
		ty = ny - COLLISION_OFFSET;
	return (!is_wall(g, tx, ty));
}

static int	get_next_door(int cur)
{
	if (cur == 0)
		return (1);
	else
		return (0);
}

static void	compute_door_dest(t_game *g, int nxt, double *dx, double *dy)
{
	*dx = g->doors[nxt].x + 0.5;
	*dy = g->doors[nxt].y + 0.5;
	if (g->doors[nxt].x > 0
		&& g->map.grid[g->doors[nxt].y][g->doors[nxt].x - 1] == '0')
		*dx = g->doors[nxt].x - 0.3;
	else if (g->doors[nxt].x < g->map.width - 1
		&& g->map.grid[g->doors[nxt].y][g->doors[nxt].x + 1] == '0')
		*dx = g->doors[nxt].x + 1.3;
	else if (g->doors[nxt].y > 0
		&& g->map.grid[g->doors[nxt].y - 1][g->doors[nxt].x] == '0')
		*dy = g->doors[nxt].y - 0.3;
	else if (g->doors[nxt].y < g->map.height - 1
		&& g->map.grid[g->doors[nxt].y + 1][g->doors[nxt].x] == '0')
		*dy = g->doors[nxt].y + 1.3;
}

static int	handle_open_door(t_game *g, int cur)
{
	int		nxt;
	double	dx;
	double	dy;

	if (cur < 0 || g->doors[cur].open == 0)
		return (0);
	g->doors[cur].open = 0;
	if (g->nb_doors == 2)
	{
		nxt = get_next_door(cur);
		compute_door_dest(g, nxt, &dx, &dy);
		g->player.x = dx;
		g->player.y = dy;
	}
	return (1);
}

void	try_move(t_game *g, double nx, double ny)
{
	int	cur;

	if (!can_move(g, nx, ny))
		return ;
	if (g->map.grid[(int)ny][(int)nx] == 'D')
	{
		cur = door_index(g, (int)nx, (int)ny);
		if (handle_open_door(g, cur))
			return ;
	}
	g->player.x = nx;
	g->player.y = ny;
}
