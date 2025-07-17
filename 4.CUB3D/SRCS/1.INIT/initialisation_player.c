/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinguyen <dinguyen@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:44:36 by dinguyen          #+#    #+#             */
/*   Updated: 2025/07/16 12:28:30 by dinguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/cub3d.h"

void	set_player_direction(t_game *g, char spawn_char)
{
	if (spawn_char == 'N')
		g->player.dir = M_PI / 2;
	else if (spawn_char == 'S')
		g->player.dir = 3 * M_PI / 2;
	else if (spawn_char == 'E')
		g->player.dir = 0.0;
	else if (spawn_char == 'W')
		g->player.dir = M_PI;
}

void	set_player_spawn(t_game *g)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < g->map.height)
	{
		j = 0;
		while (j < g->map.width)
		{
			c = g->map.grid[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				g->player.x = j + 0.5;
				g->player.y = i + 0.5;
				set_player_direction(g, c);
				g->map.grid[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_player(t_game *g)
{
	g->player.move_speed = 0.05;
	g->player.rot_speed = 2.0;
	set_player_spawn(g);
}
