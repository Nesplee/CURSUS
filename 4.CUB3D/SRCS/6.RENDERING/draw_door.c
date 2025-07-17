/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:24:06 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/17 13:15:40 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

int	door_index(t_game *g, int mx, int my)
{
	int	i;

	if (!g->doors || g->nb_doors <= 0)
		return (-1);
	i = 0;
	while (i < g->nb_doors)
	{
		if (g->doors[i].x == mx && g->doors[i].y == my)
			return (i);
		i++;
	}
	return (-1);
}

static int	find_nearby_door(t_game *g)
{
	int		i;
	double	dx;
	double	dy;
	double	dist;

	if (!g->doors || g->nb_doors <= 0)
		return (-1);
	i = 0;
	while (i < g->nb_doors)
	{
		dx = (g->doors[i].x + 0.5) - g->player.x;
		dy = (g->doors[i].y + 0.5) - g->player.y;
		dist = sqrt(dx * dx + dy * dy);
		if (dist < 1.0)
			return (i);
		i++;
	}
	return (-1);
}

static void	close_other_doors(t_game *g, int cur)
{
	int	j;

	j = 0;
	while (j < g->nb_doors)
	{
		if (j != cur)
			g->doors[j].open = 0;
		j++;
	}
}

void	try_toggle_door(t_game *g)
{
	int	idx;

	if (!g->doors || g->nb_doors <= 0)
		return ;
	idx = find_nearby_door(g);
	if (idx < 0)
		return ;
	close_other_doors(g, idx);
	g->doors[idx].open = !g->doors[idx].open;
}
