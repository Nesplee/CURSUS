/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_doors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:31:58 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/16 12:26:11 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

static int	count_doors(t_game *g)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < g->map.height)
	{
		j = 0;
		while (j < g->map.width)
		{
			if (g->map.grid[i][j] == 'D')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	fill_doors_data(t_game *g)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < g->map.height)
	{
		j = 0;
		while (j < g->map.width)
		{
			if (g->map.grid[i][j] == 'D')
			{
				g->doors[count].x = j;
				g->doors[count].y = i;
				g->doors[count].open = 0;
				count++;
			}
			j++;
		}
		i++;
	}
}

void	init_doors(t_game *g)
{
	int	count;

	count = count_doors(g);
	if (count != 0 && count != 2)
		exit_error("Nombre de portes invalide (doit être 0 ou 2)");
	g->nb_doors = count;
	if (count == 0)
	{
		g->doors = NULL;
		return ;
	}
	g->doors = malloc(sizeof(*g->doors) * count);
	if (!g->doors)
		exit_error("init_doors: malloc failed");
	fill_doors_data(g);
}

void	init_doors_images(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->nb_doors)
	{
		init_texture(&g->doors[i].anim[0],
			"./TEXTURES/PORTE_FERMEE.xpm", &g->mlx);
		init_texture(&g->doors[i].anim[1],
			"./TEXTURES/PORTE_OUVERTE.xpm", &g->mlx);
		i++;
	}
}
